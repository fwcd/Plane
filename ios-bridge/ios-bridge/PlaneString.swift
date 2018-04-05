//
//  PlaneString.swift
//  ios-bridge
//
//  Created by Fredrik on 02.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

import Foundation
import UIKit

@objc
public class PlaneString: NSObject {
	public let x: Float
	public let y: Float
	public let value: String
	public let size: Float
	public let bold: Bool
	public let italic: Bool
	public let underlined: Bool
	public let color: UIColor
	
	@objc
	public init(atX x: Float, andY y: Float, value: String, size: Float, bold: Bool, italic: Bool, underlined: Bool, color: UIColor) {
		self.x = x
		self.y = y
		self.value = value
		self.size = size
		self.bold = bold
		self.italic = italic
		self.underlined = underlined
		self.color = color
	}
}
