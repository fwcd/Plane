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
	private var imagePaintQueue = Queue<PlaneImage>()
	private var paintableRenderer: PlaneRenderCallback?
	
    override public func draw(_ rect: CGRect) {
		paintableRenderer?.onRender()
		
		guard let ctx: CGContext = UIGraphicsGetCurrentContext() else { return }
		ctx.textMatrix = ctx.textMatrix
				.scaledBy(x: 1, y: -1)
				.translatedBy(x: 0, y: -bounds.height)
        ctx.setLineWidth(4.0)
		
        while !rectPaintQueue.isEmpty {
			let rect: PlaneBox = rectPaintQueue.poll()
			
			if rect.filled {
				ctx.setFillColor(rect.color.cgColor)
				ctx.fill(rect.toCGRect())
			} else {
				ctx.setStrokeColor(rect.color.cgColor)
				ctx.addRect(rect.toCGRect())
				
			}
        }
        
        while !ovalPaintQueue.isEmpty {
			let oval: PlaneBox = ovalPaintQueue.poll()
			
			if oval.filled {
				ctx.setFillColor(oval.color.cgColor)
				ctx.fillEllipse(in: oval.toCGRect())
			} else {
				ctx.setStrokeColor(oval.color.cgColor)
				ctx.addEllipse(in: oval.toCGRect())
			}
        }
		
		while !linePaintQueue.isEmpty {
			let line: PlaneLine = linePaintQueue.poll()
			
			ctx.setStrokeColor(line.color.cgColor)
			ctx.move(to: line.start)
			ctx.addLine(to: line.end)
		}
		
		while !stringPaintQueue.isEmpty {
			let str: PlaneString = stringPaintQueue.poll()
			let font = UIFont.systemFont(ofSize: CGFloat(str.size))
			let attributes = [NSForegroundColorAttributeName:str.color, NSFontAttributeName:font]
			let attributedStr = NSAttributedString(string: str.value, attributes: attributes)
			let path = CGMutablePath()
			path.addRect(CGRect(x: CGFloat(str.x), y: -bounds.height + CGFloat(str.y) + (font.lineHeight * 1.5), width: bounds.width, height: bounds.height))
			let framesetter = CTFramesetterCreateWithAttributedString(attributedStr)
			let frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, attributedStr.length), path, nil)
			
			CTFrameDraw(frame, ctx)
		}
		
		while !imagePaintQueue.isEmpty {
			let img: PlaneImage = imagePaintQueue.poll()
			ctx.draw(img.img, in: img.bounds)
		}
		
        ctx.strokePath()
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
	
	@objc
	public func enqueueImage(_ img: PlaneImage) {
		imagePaintQueue.insert(img)
	}
}
