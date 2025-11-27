package com.code;

public class LlinkedList {

	static class Node {
		private int data;
		private Node next;

		public Node(int val) {
			data = val;
			next = null;
		}
	}

	private Node head;

	
	public LlinkedList() {
		head = null;
	} 
	
	public Node getHead() {
		return head;
	}

	public boolean isEmpty() {
		return head == null;
	}

	public void addLast(int val) {
		Node node = new Node(val);
		if (head == null) {
			head = node;
			return;
		}
		Node trav = head;
		while (trav.next != null) {
			trav = trav.next;
		}
		trav.next = node;
	}

	public void deleteFirst() {
		if (head == null)
			return;
		head = head.next;
	}

	public void display() {
		Node trav = head;
		if (trav == null)
			return;
		while (trav != null) {
			System.out.print(" " + trav.data);
			trav = trav.next;
		}
		System.out.println();
	}

	public void sort() {
		Node trav = head;
		if (trav == null)
			return;

		for (; trav != null; trav = trav.next) {
			for (Node trav2 = head; trav2.next != null; trav2 = trav2.next) {
				if (trav2.data > trav2.next.data) {
					int temp = trav2.data;
					trav2.data = trav2.next.data;
					trav2.next.data = temp;
				}
			}
		}
	}

	public void addSumTwoConseccutive() {
		Node trav = head;
		if (trav == null || trav.next == null)
			return;
		while (trav != null && trav.next != null) {
			int sum = trav.data + trav.next.data;
			Node node = new Node(sum);
			trav = trav.next;
			node.next = trav.next;
			trav.next = node;

			trav = trav.next.next;
		}
	}

	public void mergeSortedList(LlinkedList ll1, LlinkedList ll2) {
		Node node1 = ll1.getHead();
		Node node2 = ll2.getHead();
		if (node1 == null || node2 == null) {
			head = node1 == null ? node2 : node1;
			return;
		}
		head = new Node(-1);
		Node trav = head;

		while (node1 != null && node2 != null) {
			if (node1.data > node2.data) {
				trav.next = new Node(node2.data);
				trav = trav.next;
				node2 = node2.next;
			} else {
				trav.next = new Node(node1.data);
				trav = trav.next;
				node1 = node1.next;
			}
		}

		while (node1 != null) {
			trav.next = new Node(node1.data);
			trav = trav.next;
			node1 = node1.next;
		}

		while (node2 != null) {
			trav.next = new Node(node2.data);
			trav = trav.next;
			node2 = node2.next;
		}
		
		node1=null;
		node2=null;
		head = head.next;
	}

}
