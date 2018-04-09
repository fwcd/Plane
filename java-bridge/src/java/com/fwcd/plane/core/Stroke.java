package com.fwcd.plane.core;

import java.awt.Color;

public class Stroke {
	private float width;
	private Color color;
	
	public Stroke(float width, Color color) {
		this.width = width;
		this.color = color;
	}
	
	public float getWidth() { return width; }
	
	public Color getColor() { return color; }
}
