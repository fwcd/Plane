package com.fwcd.plane.core;

public class NativePaintable implements AutoCloseable {
	private long nativeThisPtr;
	private long nativeScreenPtr;
	
	public native void paint();
	
	@Override
	public native void close();
}
