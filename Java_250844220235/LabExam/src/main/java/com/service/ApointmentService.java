package com.service;

import java.time.LocalDate;
import java.util.Scanner;

import com.entities.AppointmentPojo;
import com.util.NegativeValueNotAllowedException;

public class ApointmentService {
	private static Scanner sc = new Scanner(System.in);
	
	public static AppointmentPojo acceptAppointmentPojo() throws NegativeValueNotAllowedException{
		AppointmentPojo appointment = new AppointmentPojo();
		
		System.out.print("Enter the Appointment Id : ");
		appointment.setId(sc.nextInt());
		
		System.out.print("Enter the Doctor Id : ");
		appointment.setDoctorId(sc.nextInt());
		
		System.out.print("Enter the Patient Name : ");
		appointment.setPatitentName(sc.next());
		
		System.out.print("Enter the Patient Age : ");
		appointment.setPatientAge(sc.nextInt());
		
		System.out.println("Enter the Schedule Date : ");
		System.out.print("Enter day : ");
		int day = sc.nextInt();
		System.out.print("Enter month : ");
		int month = sc. nextInt();
		System.out.print("Enter year : ");
		int year = sc.nextInt();
		appointment.setDate(LocalDate.of(year, month, day));
		
		return appointment;
	}

}
