package com.entities;

import java.time.LocalDate;

import com.util.NegativeValueNotAllowedException;

public class AppointmentPojo {
	
	private int id;
	private int doctorId;
	private String patitentName;
	private int patientAge;
	private LocalDate date;
	private String status;
	
	public AppointmentPojo() {	}

	public AppointmentPojo(int id, int doctorId, String patitentName, int patientAge, LocalDate date, String status) {
		this.id = id;
		this.doctorId = doctorId;
		this.patitentName = patitentName;
		this.patientAge = patientAge;
		this.date = date;
		this.status = status;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getDoctorId() {
		return doctorId;
	}

	public void setDoctorId(int doctorId) {
		this.doctorId = doctorId;
	}

	public String getPatitentName() {
		return patitentName;
	}

	public void setPatitentName(String patitentName) {
		this.patitentName = patitentName;
	}

	public int getPatientAge() {
		return patientAge;
	}

	public void setPatientAge(int patientAge) {
		if(patientAge<=0) {
			throw new NegativeValueNotAllowedException("Age cannot be negative.");
		}
		this.patientAge = patientAge;
	}

	public LocalDate getDate() {
		return date;
	}

	public void setDate(LocalDate date) {
		this.date = date;
	}

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	@Override
	public String toString() {
		return "AppointmentPojo [id=" + id + ", doctorId=" + doctorId + ", patitentName=" + patitentName
				+ ", patientAge=" + patientAge + ", date=" + date + ", status=" + status + "]";
	}
}
