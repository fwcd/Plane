package com.fwcd.plane.core;

public class KeyEvent {
	private Key key;
	private Key[] modifiers;
	
	public KeyEvent(Key key, Key[] modifiers) {
		this.key = key;
	}
	
	public Key getKey() { return key; }
	
	public Key[] getModifiers() { return modifiers; }
}
