//
//  Queue.swift
//  ios-bridge
//
//  Created by Fredrik on 01.04.18.
//  Copyright © 2018 fwcd. All rights reserved.
//

import Foundation

class Queue<T> {
    private var data: [T] = [T]()
    var isEmpty: Bool {
        return data.isEmpty
    }
    
    func insert(_ item: T) {
        data.append(item)
    }
    
    func poll() -> T {
        return data.removeFirst()
    }
}
