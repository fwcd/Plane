package com.fwcd.plane.core;

import java.awt.Color;

import com.fwcd.plane.utils.FloatConsumer;

/**
 * The Screen interface, translated directly from C++.
 */
public interface Screen {
	void repaintSoon();
	
	void setBackground(Color color);
	
	Color getBackground();
	
	float getWidth();
	
	float getHeight();
	
	void drawRect(float x, float y, float w, float h, Stroke stroke);
	
	void fillRect(float x, float y, float w, float h, Fill fill);
	
	void drawOval(float x, float y, float w, float h, Stroke stroke);
	
	void fillOval(float x, float y, float w, float h, Fill fill);
	
	void drawImage(String filePath, float x, float y, FloatConsumer returnedW, FloatConsumer returnedH);
	
	void drawImageSized(String filePath, float x, float y, float w, float h);
	
	void drawString(String str, float x, float y, FontAttributes attribs);
	
	void drawLine(float startX, float startY, float endX, float endY, Stroke stroke);
	
	void addOnTop(NativePaintable paintable);
	
	void addOnBottom(NativePaintable paintable);
	
	void remove(NativePaintable paintable);
	
	void addKeyListener(NativeKeyListener keyListener);
	
	void addMouseListener(NativeMouseListener mouseListener);
	
	void removeKeyListener(NativeKeyListener keyListener);
	
	void removeMouseListener(NativeMouseListener mouseListener);
	
	void blockUntilExit();
}
