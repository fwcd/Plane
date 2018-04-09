package com.fwcd.plane.core;

import java.awt.Color;

public class FontAttributes {
	private float size;
	private boolean bold;
	private boolean italic;
	private boolean underlined;
	private Color color;
	
	public FontAttributes(float size, boolean bold, boolean italic, boolean underlined, Color color) {
		this.size = size;
		this.bold = bold;
		this.italic = italic;
		this.underlined = underlined;
		this.color = color;
	}
	
	public float getSize() { return size; }
	
	public boolean isBold() { return bold; }
	
	public boolean isItalic() { return italic; }
	
	public boolean isUnderlined() { return underlined; }
	
	public Color getColor() { return color; }
}
