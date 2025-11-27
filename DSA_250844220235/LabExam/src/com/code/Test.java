package com.code;

import java.util.Scanner;

public class Test {
	private static Scanner sc = new Scanner(System.in);

	public static int menuList() {
		System.out.println("0. Exit");
		System.out.println("1. Add Last");
		System.out.println("2. Delete First");
		System.out.println("3. Display");
		System.out.println("4. Sort");
		System.out.println("5. Add Node with Consecutive Sum");
		System.out.println("6. Merge Two Sorted List");
		System.out.print("Enter the choice: ");
		return sc.nextInt();
	}

	public static void addIntoList(LlinkedList ll) {
		System.out.print("Enter the value: ");
		ll.addLast(sc.nextInt());
		System.out.println("Insertion successfull.");
	}

	public static void mergeList() {
		LlinkedList ll1 = new LlinkedList();
		LlinkedList ll2 = new LlinkedList();

		LlinkedList res = new LlinkedList();

		System.out.print("Enter the values of List 1: ");
		while (true) {
			ll1.addLast(sc.nextInt());
			System.out.print("want to add more (y/n): ");
			String str = sc.next();
			if (!str.equals("y"))
				break;
		}

		System.out.print("Enter the values of List 2: ");
		while (true) {
			ll2.addLast(sc.nextInt());
			System.out.print("want to add more (y/n): ");
			String str = sc.next();
			if (!str.equals("y"))
				break;
		}

		ll1.sort();
		ll2.sort();

		System.out.println("========================================");
		System.out.println("Sorted List1 : ");
		ll1.display();
		System.out.println("Sorted List2 : ");
		ll2.display();

		res.mergeSortedList(ll1, ll2);
		System.out.println("Merge successful.");

		System.out.println("Merged List : ");
		res.display();
		System.out.println("========================================");
	}

	public static void main(String[] args) {

		int choice;
		LlinkedList ll = new LlinkedList();
		while ((choice = menuList()) != 0) {
			switch (choice) {
			case 1: {
				addIntoList(ll);
				break;
			}
			case 2: {
				ll.deleteFirst();
				System.out.println("Delete successful.");
				break;
			}
			case 3: {
				ll.display();
				break;
			}
			case 4: {
				ll.sort();
				System.out.println("Sort successful.");
				break;
			}
			case 5: {
				ll.addSumTwoConseccutive();
				System.out.println("Task successful.");
				break;
			}
			case 6: {
				mergeList();

				break;
			}
			default:
				System.out.println("Invalid Input!! Try again.");
			}
		}

		System.out.println("=====================END=====================");

	}

}
