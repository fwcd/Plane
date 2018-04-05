//
//  PlaneViewController.swift
//  ios-bridge
//
//  Created by Fredrik on 31.03.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

import UIKit

class PlaneViewController: UIViewController {
	private var app: PlaneAppHolder?
	override var prefersStatusBarHidden: Bool {
		// TODO: This value is probably queried before app is intialized
		return !(app?.showsStatusBar() ?? false)
	}
	
	override func loadView() {
		view = PlaneCGView()
		app = PlaneAppHolder(view: view)
		app!.startApp()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
	
	override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
		app?.onTouchDown(touches)
	}
	
	override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
		app?.onTouchMove(touches)
	}
	
	override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
		app?.onTouchUp(touches)
	}
}

