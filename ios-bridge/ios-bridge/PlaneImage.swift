//
//  PlaneImage.swift
//  ios-bridge
//
//  Created by Fredrik on 03.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

import Foundation
import UIKit

@objc
public class PlaneImage : NSObject {
	public let img: CGImage
	public let bounds: CGRect
	
	@objc
	public init(path: String, source: CGDataProvider, x: Float, y: Float, w: Float, h: Float, shouldInterpolate: Bool) {
		pLogDebug("Loading image from " + path)
		let intent = CGColorRenderingIntent.defaultIntent
		let optionalImg: CGImage?
		
		if (path.hasSuffix("png")) {
			optionalImg = CGImage(pngDataProviderSource: source, decode: nil, shouldInterpolate: shouldInterpolate, intent: intent)
		} else if (path.hasSuffix("jpg") || path.hasSuffix("jpeg")) {
			optionalImg = CGImage(jpegDataProviderSource: source, decode: nil, shouldInterpolate: shouldInterpolate, intent: intent)
		} else {
			optionalImg = nil
		}
		
		// TODO: Generate a proper error message here if the image could not be loaded
		img = optionalImg!
		
		bounds = CGRect(x: CGFloat(x), y: CGFloat(y), width: (w < 0 ? CGFloat(img.width) : CGFloat(w)), height: (h < 0 ? CGFloat(img.height) : CGFloat(h)))
	}
	
	@objc
	public func getWidth() -> Float {
		return Float(bounds.width);
	}
	
	@objc
	public func getHeight() -> Float {
		return Float(bounds.height);
	}
}
