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
	public init(image: CGImage?, x: Float, y: Float, w: Float, h: Float, shouldInterpolate: Bool) {
		if (image == nil) {
			// TODO: Generate a proper error message here if the image could not be loaded
			PlaneLog.error("Image source is nil while loading")
		}
		
		img = image!
		
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
