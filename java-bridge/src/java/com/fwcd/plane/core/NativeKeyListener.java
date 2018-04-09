package com.fwcd.plane.core;

public class NativeKeyListener implements AutoCloseable {
	private long nativeThisPtr;
	
	public native void onPress(char keyChar);
	
	public native void onRelease(char keyChar);
	
	@Override
	public native void close();
}
