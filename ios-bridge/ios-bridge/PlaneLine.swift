//
//  PlaneLine.swift
//  ios-bridge
//
//  Created by Fredrik on 02.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

import Foundation
import UIKit

@objc
public class PlaneLine : NSObject {
	public let start: CGPoint
	public let end: CGPoint
	public let color: UIColor
	
	@objc
	public init(fromX startX: Float, y startY: Float, toX endX: Float, y endY: Float, withColor color: UIColor) {
		self.start = CGPoint(x: Double(startX), y: Double(startY))
		self.end = CGPoint(x: Double(endX), y: Double(endY))
		self.color = color
	}
}
