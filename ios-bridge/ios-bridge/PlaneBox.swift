//
//  PlaneBox.swift
//  ios-bridge
//
//  Created by Fredrik on 02.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

import Foundation
import UIKit

@objc
public class PlaneBox: NSObject {
	public let x: Float
	public let y: Float
	public let w: Float
	public let h: Float
	public let filled: Bool
	public let color: UIColor
	
	@objc
	public init(atX x: Float, andY y: Float, withWidth w: Float, andHeight h: Float, filled: Bool, color: UIColor) {
		self.x = x
		self.y = y
		self.w = w
		self.h = h
		self.filled = filled
		self.color = color
	}
	
	public func toCGRect() -> CGRect {
		return CGRect(x: Double(x), y: Double(y), width: Double(w), height: Double(h))
	}
}
