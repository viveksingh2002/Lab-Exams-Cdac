package com.util;

import java.util.Scanner;

public class MenuList {
	
	public static int menuList() {
		Scanner sc = new Scanner(System.in);
		System.out.println("0. Exit");
		System.out.println("1. Add Doctor");
		System.out.println("2. Book Appointment");
		System.out.println("3. Cancel Appointment");
		System.out.println("4. All Appointments");
		System.out.println("5. All Upcomming Appointment");
		System.out.println("6. Appointment Count of Each Doctor");
		System.out.print("Enter your choice : ");
		return sc.nextInt();
		
	}

}
