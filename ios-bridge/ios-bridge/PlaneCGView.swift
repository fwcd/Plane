//
//  PlaneCGView.swift
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

import Foundation
import UIKit

@objc
public class PlaneCGView : UIView {
    private var rectPaintQueue = Queue<PlaneBox>()
    private var ovalPaintQueue = Queue<PlaneBox>()
	private var linePaintQueue = Queue<PlaneLine>()
	
    override public func draw(_ rect: CGRect) {
        let ctx: CGContext? = UIGraphicsGetCurrentContext()
        ctx?.setLineWidth(4.0)
        ctx?.setStrokeColor(UIColor.blue.cgColor)
		ctx?.setFillColor(UIColor.blue.cgColor)
		ctx?.addEllipse(in: CGRect(x: 100, y: 100, width: 200, height: 200))
		
        while !rectPaintQueue.isEmpty {
			let rect: PlaneBox = rectPaintQueue.poll()
			
			if rect.filled {
				ctx?.fill(toCGRect(rect))
			} else {
				ctx?.addRect(toCGRect(rect))
			}
        }
        
        while !ovalPaintQueue.isEmpty {
			let oval: PlaneBox = ovalPaintQueue.poll()
			
			if oval.filled {
				ctx?.fillEllipse(in: toCGRect(oval))
			} else {
				ctx?.addEllipse(in: toCGRect(oval))
			}
        }
		
		while !linePaintQueue.isEmpty {
			let line: PlaneLine = linePaintQueue.poll()
			
			ctx?.move(to: line.getStart())
			ctx?.addLine(to: line.getEnd())
		}
        
        ctx?.strokePath()
    }
    
    private func toCGRect(_ box: PlaneBox) -> CGRect {
        return CGRect(x: Double(box.x), y: Double(box.y), width: Double(box.w), height: Double(box.h))
    }
    
    @objc
    public func repaint() {
        setNeedsDisplay()
    }
    
    @objc
    public func enqueueRect(_ rect: PlaneBox) {
        rectPaintQueue.insert(rect)
    }
    
    @objc
    public func enqueueOval(_ oval: PlaneBox) {
        ovalPaintQueue.insert(oval)
    }
}
