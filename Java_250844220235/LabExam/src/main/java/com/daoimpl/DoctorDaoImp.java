package com.daoimpl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import com.dao.DoctorDao;
import com.entities.DoctorPojo;
import com.util.MysqlConnection;

public class DoctorDaoImp implements DoctorDao{
	
	@Override
	public void addDoctor(DoctorPojo doc) throws Exception {
		try(Connection con = MysqlConnection.getConnection()){
			String sql = "insert into doctor values(?, ?, ?)";
			try(PreparedStatement stmt = con.prepareStatement(sql)){
				stmt.setInt(1, doc.getId());
				stmt.setString(2, doc.getName());
				stmt.setString(3, doc.getSpectialization());
				
				int cnt =  stmt.executeUpdate();
				
				if(cnt==1) {
					System.out.println("Doctor added successfully!!");
				}else {
					System.out.println("Something went wrong.");
				}
			}
		}
		
	}

}
