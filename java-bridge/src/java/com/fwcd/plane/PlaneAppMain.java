package com.fwcd.plane;

import com.fwcd.plane.core.NativePlaneApp;
import com.fwcd.plane.core.Screen;
import com.fwcd.plane.swing.SwingScreen;

public class PlaneAppMain {
	static {
		System.loadLibrary("plane");
	}
	
	public static void main(String[] args) {
		NativePlaneApp app = new NativePlaneApp();
		Screen screen = new SwingScreen("Plane", 640, 480);
		app.initialize(screen);
		screen.blockUntilExit();
	}
}
