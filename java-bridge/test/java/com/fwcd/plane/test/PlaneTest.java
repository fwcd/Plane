package com.fwcd.plane.test;

import javax.swing.JFrame;

import com.fwcd.plane.PlaneComponent;

public class PlaneTest {
	public static void main(String[] args) {
		JFrame frame = new JFrame("Plane wrapper");
		frame.setSize(640, 480);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.add(new PlaneComponent());
		frame.setVisible(true);
	}
}
