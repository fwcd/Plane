package com.fwcd.plane;

import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JComponent;

public class PlaneComponent extends JComponent {
	private static final long serialVersionUID = 6240915532882688225L;
	
	@Override
	protected void paintComponent(Graphics g) {
		drawTo((Graphics2D) g);
	}
	
	public native void drawTo(Graphics2D g2d);
}
