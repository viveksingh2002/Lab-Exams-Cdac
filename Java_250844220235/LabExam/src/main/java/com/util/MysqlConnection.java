package com.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public final class MysqlConnection {
	
	public static final String DB_DRIVER = "com.mysql.cj.jdbc.Driver";
	public static final String DB_URL = "jdbc:mysql://localhost:3306/hospital_jdbc";
	public static final String DB_USER = "D1_93010_Vivek";
	public static final String DB_PASS = "manager";
	
	static {
		try {
			Class.forName(DB_DRIVER);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static Connection getConnection() throws SQLException {
		
		Connection con = DriverManager.getConnection(DB_URL, DB_USER, DB_PASS);
		return con;
		
	}

}
