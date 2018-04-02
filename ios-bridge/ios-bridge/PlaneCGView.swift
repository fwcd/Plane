//
//  PlaneCGView.swift
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

import Foundation
import UIKit
import CoreGraphics
import CoreText

/**
 * The view class that handles native graphics rendering
 * tasks.
 */
@objc
public class PlaneCGView : UIView {
    private var rectPaintQueue = Queue<PlaneBox>()
    private var ovalPaintQueue = Queue<PlaneBox>()
	private var linePaintQueue = Queue<PlaneLine>()
	private var stringPaintQueue = Queue<PlaneString>()
	private var paintableRenderer: PlaneRenderCallback?
	
    override public func draw(_ rect: CGRect) {
		paintableRenderer?.onRender()
		
        let ctx: CGContext? = UIGraphicsGetCurrentContext()
        ctx?.setLineWidth(4.0)
		
        while !rectPaintQueue.isEmpty {
			let rect: PlaneBox = rectPaintQueue.poll()
			
			if rect.filled {
				ctx?.setFillColor(rect.color.cgColor)
				ctx?.fill(rect.toCGRect())
			} else {
				ctx?.setStrokeColor(rect.color.cgColor)
				ctx?.addRect(rect.toCGRect())
				
			}
        }
        
        while !ovalPaintQueue.isEmpty {
			let oval: PlaneBox = ovalPaintQueue.poll()
			
			if oval.filled {
				ctx?.setFillColor(oval.color.cgColor)
				ctx?.fillEllipse(in: oval.toCGRect())
			} else {
				ctx?.setStrokeColor(oval.color.cgColor)
				ctx?.addEllipse(in: oval.toCGRect())
			}
        }
		
		while !linePaintQueue.isEmpty {
			let line: PlaneLine = linePaintQueue.poll()
			
			ctx?.setStrokeColor(line.color.cgColor)
			ctx?.move(to: line.start)
			ctx?.addLine(to: line.end)
		}
		
		while !stringPaintQueue.isEmpty {
			let str: PlaneString = stringPaintQueue.poll()
			let attributedStr: CFAttributedString = CFAttributedStringCreate(nil, CFStringCreateWithCString(nil, str.value.cString(using: String.Encoding.unicode), CFStringBuiltInEncodings.unicode.rawValue), nil)
			let line: CTLine = CTLineCreateWithAttributedString(attributedStr)
			
			// FIXME: Figure out why font rendering is not working
			
			ctx?.setFontSize(CGFloat(str.size))
			ctx?.setStrokeColor(str.color.cgColor)
			ctx?.setTextDrawingMode(CGTextDrawingMode.stroke)
			CTLineDraw(line, ctx!)
		}
        
        ctx?.strokePath()
    }
	
	@objc
	public func injectPaintableRenderer(_ paintableRenderer: PlaneRenderCallback) {
		self.paintableRenderer = paintableRenderer
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
	
	@objc
	public func enqueueLine(_ line: PlaneLine) {
		linePaintQueue.insert(line)
	}
	
	@objc
	public func enqueueString(_ str: PlaneString) {
		stringPaintQueue.insert(str)
	}
}
