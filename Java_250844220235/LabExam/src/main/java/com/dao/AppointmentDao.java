package com.dao;

import com.entities.AppointmentPojo;

public interface AppointmentDao {
	
	abstract void bookAppointment(AppointmentPojo appointment) throws Exception;
	
	abstract void cancelAppointment(int appointmentId) throws Exception;
	
	abstract void viewAllAppointment() throws Exception;
	
	abstract void viewAllUpcommintAppointment() throws Exception;
	
	abstract void countEachDoctorAppointment() throws Exception;

}
