package com.fwcd.plane.core;

public class MouseEvent {
	private Vec2Float[] lastPositions;
	private Vec2Float[] positions;
	private MouseButton button;
	private int clicks = 1;
	
	public MouseEvent(Vec2Float[] lastPositions, Vec2Float[] positions) {
		this.lastPositions = lastPositions;
		this.positions = positions;
	}
	
	public void setButton(MouseButton button) { this.button = button; }
	
	public void setClicks(int clicks) { this.clicks = clicks; }
	
	public boolean usesTouch() { return button == MouseButton.TOUCH; }
	
	public Vec2Float getPosDelta() { return getPos().sub(getLastPos()); }
	
	public Vec2Float getPos() { return positions[0]; }
	
	public Vec2Float getLastPos() { return lastPositions[0]; }
	
	public Vec2Float[] getAllLastPositions() { return lastPositions; }
	
	public Vec2Float[] getAllPositions() { return positions; }
	
	public MouseButton getButton() { return button; }
	
	public int getClicks() { return clicks; }
}
