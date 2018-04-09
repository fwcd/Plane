package com.fwcd.plane.utils;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.function.Consumer;

public class ContextualTaskQueue<T> {
	private final Queue<Consumer<T>> tasks = new ArrayDeque<>();
	
	public void enqueue(Consumer<T> task) {
		tasks.offer(task);
	}
	
	public void drain(T context) {
		while (!tasks.isEmpty()) {
			tasks.poll().accept(context);
		}
	}
}
