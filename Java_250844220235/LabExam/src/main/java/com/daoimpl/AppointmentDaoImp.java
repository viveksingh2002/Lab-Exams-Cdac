package com.daoimpl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import com.dao.AppointmentDao;
import com.entities.AppointmentPojo;
import com.util.MysqlConnection;

public class AppointmentDaoImp implements AppointmentDao{

	// Book Apointment
	@Override
	public void bookAppointment(AppointmentPojo appointment) throws Exception {
		try(Connection con = MysqlConnection.getConnection()){
			String sql = "insert into appointment values(?, ?, ?, ?, ?, ?)";
			try(PreparedStatement stmt = con.prepareStatement(sql)){
				stmt.setInt(1, appointment.getId());
				stmt.setInt(2, appointment.getDoctorId());
				stmt.setString(3, appointment.getPatitentName());
				stmt.setInt(4, appointment.getPatientAge());
				stmt.setString(5, appointment.getDate().toString());
				stmt.setString(6, "Scheduled");
				
				int cnt =  stmt.executeUpdate();
				
				if(cnt==1) {
					System.out.println("Appointment is booked successfully!!");
				}else {
					System.out.println("Something went wrong.");
				}
			}
		}
		
	}


	@Override
	public void cancelAppointment(int appointmentId) throws Exception {
		try(Connection con = MysqlConnection.getConnection()){
			String sql = "update appointment set status=? where appointment_id=?";
			try(PreparedStatement stmt = con.prepareStatement(sql)){
				stmt.setString(1, "Cancelled");
				stmt.setInt(2, appointmentId);
				
				int cnt =  stmt.executeUpdate();
				
				if(cnt==1) {
					System.out.println("Appointment is cancelled successfully!!");
				}else {
					System.out.println("Something went wrong.");
				}
			}
		}
	}

	@Override
	public void viewAllAppointment() throws Exception {
		try(Connection con = MysqlConnection.getConnection()){
			String sql = "select * from appointment";
			try(PreparedStatement stmt = con.prepareStatement(sql)){
				try(ResultSet rs = stmt.executeQuery()){
					while(rs.next()) {
						int id = rs.getInt("appointment_id");
						int dId = rs.getInt("doctor_id");
						String pName = rs.getString("patient_name");
						int pAge = rs.getInt("Patient_age");
						String date = rs.getDate("appointment_date").toString();
						String status = rs.getString("status");
						
						System.out.printf("%-10d%-10d%-20s%-10d%-20s%-20s\n", id, dId, pName, pAge, date, status);
					}
				}
				
			}
		}
		
	}

	@Override
	public void viewAllUpcommintAppointment() throws Exception {
		try(Connection con = MysqlConnection.getConnection()){
			String sql = "select * from appointment where status=?";
			try(PreparedStatement stmt = con.prepareStatement(sql)){
				stmt.setString(1, "Scheduled");
				try(ResultSet rs = stmt.executeQuery()){
					while(rs.next()) {
						int id = rs.getInt("appointment_id");
						int dId = rs.getInt("doctor_id");
						String pName = rs.getString("patient_name");
						int pAge = rs.getInt("Patient_age");
						String date = rs.getDate("appointment_date").toString();
						String status = rs.getString("status");
						
						System.out.printf("%-10d%-10d%-20s%-10d%-20s%-20s\n", id, dId, pName, pAge, date, status);
					}
				}
				
			}
		}
		
	}

	@Override
	public void countEachDoctorAppointment() throws Exception {
		try(Connection con = MysqlConnection.getConnection()){
			String sql = "Select doctor_id, count(*) as total from appointment group by 1";
			try(PreparedStatement stmt = con.prepareStatement(sql)){
				try(ResultSet rs = stmt.executeQuery()){
					while(rs.next()) {
						int dId = rs.getInt("doctor_id");
						int count = rs.getInt("total");
						
						System.out.printf("%-10d%-10d\n", dId, count);
					}
				}
				
			}
		}
		
	}

	

}
