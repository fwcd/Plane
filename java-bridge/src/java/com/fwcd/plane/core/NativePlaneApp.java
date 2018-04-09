package com.fwcd.plane.core;

public class NativePlaneApp implements AutoCloseable {
	private long nativeThisPtr;
	
	public native void initialize(Screen screen);
	
	@Override
	public native void close();
}
