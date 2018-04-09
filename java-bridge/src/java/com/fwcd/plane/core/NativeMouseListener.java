package com.fwcd.plane.core;

public class NativeMouseListener implements AutoCloseable {
	private long nativeThisPtr;
	
	public native void onClick();
	
	public native void onRelease();
	
	public native void onDrag();
	
	public native void onMove();

	@Override
	public native void close();
}
