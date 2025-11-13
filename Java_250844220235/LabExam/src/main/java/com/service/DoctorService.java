package com.service;

import java.time.LocalDate;
import java.util.Scanner;

import com.entities.DoctorPojo;

public class DoctorService {
	private static Scanner sc = new Scanner(System.in);
	
	public static DoctorPojo acceptDoctor() {
		DoctorPojo doc = new DoctorPojo();
		
		System.out.print("Enter the Doctor Id : ");
		doc.setId(sc.nextInt());
		
		System.out.print("Enter the Doctor Name : ");
		doc.setName(sc.next());
		
		System.out.print("Enter the Doctor Speciallization : ");
		doc.setSpectialization(sc.next());
		
		return doc;
		
	}

}
