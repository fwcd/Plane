package com.fwcd.plane.swing;

import java.awt.BasicStroke;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

import com.fwcd.plane.core.Fill;
import com.fwcd.plane.core.FontAttributes;
import com.fwcd.plane.core.NativeKeyListener;
import com.fwcd.plane.core.NativeMouseListener;
import com.fwcd.plane.core.NativePaintable;
import com.fwcd.plane.core.Screen;
import com.fwcd.plane.core.Stroke;
import com.fwcd.plane.utils.ContextualTaskQueue;
import com.fwcd.plane.utils.FloatConsumer;

public class SwingScreen implements Screen {
	private final ContextualTaskQueue<Graphics2D> drawQueue = new ContextualTaskQueue<>();
	private final Deque<NativePaintable> paintables = new ArrayDeque<>();
	private final List<NativeMouseListener> mouseListeners = new ArrayList<>();
	private final List<NativeKeyListener> keyListeners = new ArrayList<>();
	private final JPanel panel;
	
	public SwingScreen(String title, int width, int height) {
		JFrame frame = new JFrame(title);
		frame.setSize(width, height);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new BorderLayout());
		panel = new JPanel() {
			private static final long serialVersionUID = 1L;
			
			@Override
			protected void paintComponent(Graphics g) {
				super.paintComponent(g);
				drawQueue.drain((Graphics2D) g);
			}
		};
		frame.add(panel, BorderLayout.CENTER);
		frame.setVisible(true);
	}
	
	@Override
	public void repaintSoon() {
		SwingUtilities.invokeLater(panel::repaint);
	}

	@Override
	public void setBackground(Color color) {
		panel.setBackground(color);
	}

	@Override
	public Color getBackground() {
		return panel.getBackground();
	}

	@Override
	public float getWidth() {
		return panel.getWidth();
	}

	@Override
	public float getHeight() {
		return panel.getHeight();
	}

	private void applyStroke(Stroke stroke, Graphics2D g2d) {
		g2d.setStroke(new BasicStroke(stroke.getWidth()));
		g2d.setColor(stroke.getColor());
	}
	
	private void applyFill(Fill fill, Graphics2D g2d) {
		g2d.setColor(fill.getColor());
	}
	
	@Override
	public void drawRect(float x, float y, float w, float h, Stroke stroke) {
		drawQueue.enqueue(g2d -> {
			applyStroke(stroke, g2d);
			g2d.drawRect((int) x, (int) y, (int) w, (int) h);
		});
	}

	@Override
	public void fillRect(float x, float y, float w, float h, Fill fill) {
		drawQueue.enqueue(g2d -> {
			applyFill(fill, g2d);
			g2d.fillRect((int) x, (int) y, (int) w, (int) h);
		});
	}

	@Override
	public void drawOval(float x, float y, float w, float h, Stroke stroke) {
		drawQueue.enqueue(g2d -> {
			applyStroke(stroke, g2d);
			g2d.drawOval((int) x, (int) y, (int) w, (int) h);
		});
	}

	@Override
	public void fillOval(float x, float y, float w, float h, Fill fill) {
		drawQueue.enqueue(g2d -> {
			applyFill(fill, g2d);
			g2d.fillOval((int) x, (int) y, (int) w, (int) h);
		});
	}

	@Override
	public void drawImage(String filePath, float x, float y, FloatConsumer returnedW, FloatConsumer returnedH) {
		drawQueue.enqueue(g2d -> {
			try {
				BufferedImage img = ImageIO.read(new File(filePath));
				returnedW.accept(img.getWidth());
				returnedH.accept(img.getHeight());
				g2d.drawImage(img, (int) x, (int) y, null);
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		});
	}

	@Override
	public void drawImageSized(String filePath, float x, float y, float w, float h) {
		drawQueue.enqueue(g2d -> {
			try {
				BufferedImage img = ImageIO.read(new File(filePath));
				g2d.drawImage(img, (int) x, (int) y, (int) w, (int) h, null);
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		});
	}

	@Override
	public void drawString(String str, float x, float y, FontAttributes attribs) {
		drawQueue.enqueue(g2d -> {
			int style = Font.PLAIN;
			
			if (attribs.isBold()) {
				style += Font.BOLD;
			}
			if (attribs.isItalic()) {
				style += Font.ITALIC;
			}
			
			// TODO: Support underlined text by drawing a line
			
			g2d.setColor(attribs.getColor());
			g2d.setFont(g2d.getFont().deriveFont(style, attribs.getSize()));
			g2d.drawString(str, x, y);
		});
	}

	@Override
	public void drawLine(float startX, float startY, float endX, float endY, Stroke stroke) {
		drawQueue.enqueue(g2d -> {
			applyStroke(stroke, g2d);
			g2d.drawLine((int) startX, (int) startY, (int) endX, (int) endY);
		});
	}

	@Override
	public void addOnTop(NativePaintable paintable) {
		paintables.addLast(paintable);
	}

	@Override
	public void addOnBottom(NativePaintable paintable) {
		paintables.addFirst(paintable);
	}

	@Override
	public void remove(NativePaintable paintable) {
		paintables.remove(paintable);
		// TODO: Do cleanup here?
	}

	@Override
	public void addKeyListener(NativeKeyListener keyListener) {
		keyListeners.add(keyListener);
	}

	@Override
	public void addMouseListener(NativeMouseListener mouseListener) {
		mouseListeners.add(mouseListener);
	}

	@Override
	public void removeKeyListener(NativeKeyListener keyListener) {
		keyListeners.remove(keyListener);
		// TODO: Do cleanup here?
	}

	@Override
	public void removeMouseListener(NativeMouseListener mouseListener) {
		mouseListeners.remove(mouseListener);
		// TODO: Do cleanup here?
	}

	@Override
	public void blockUntilExit() {
		// Not needed as AWT operates on a separate thread and thus keeps the application alive
	}
}
