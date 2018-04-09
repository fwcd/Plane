package com.fwcd.plane.core;

public class Vec2Float {
	private float x;
	private float y;
	
	public Vec2Float(float x, float y) {
		this.x = x;
		this.y = y;
	}
	
	public float getX() { return x; }
	
	public float getY() { return y; }
	
	public Vec2Float add(Vec2Float other) {
		return new Vec2Float(x + other.x, y + other.y);
	}
	
	public Vec2Float sub(Vec2Float other) {
		return new Vec2Float(x - other.x, y - other.y);
	}
	
	public Vec2Float scale(float factor) {
		return new Vec2Float(x * factor, y * factor);
	}
	
	public Vec2Float normalize() {
		float len = length();
		return new Vec2Float(x / len, y / len);
	}
	
	public float length() {
		return (float) Math.hypot(x, y);
	}
}
