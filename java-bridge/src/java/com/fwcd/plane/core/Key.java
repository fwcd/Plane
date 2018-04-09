package com.fwcd.plane.core;

public class Key {
	private char keyChar;
	private SpecialKey special;
	
	public Key(char keyChar) {
		this.keyChar = keyChar;
		special = SpecialKey.NONE;
	}
	
	public Key(SpecialKey special) {
		keyChar = 0;
		this.special = special;
	}
	
	public char asChar() {
		if (!hasChar()) {
			throw new IllegalStateException("Tried to fetch non-existent key character.");
		}
		
		return keyChar;
	}
	
	public SpecialKey asSpecialKey() {
		if (!isSpecial()) {
			throw new IllegalStateException("Tried to fetch non-existent special key.");
		}
		
		return special;
	}
	
	public boolean isEmpty() { return !hasChar() && !isSpecial(); }
	
	public boolean hasChar() { return keyChar != 0; }
	
	public boolean isSpecial() { return special != SpecialKey.NONE; }
}
