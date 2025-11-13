package com.dao;

import com.entities.DoctorPojo;

public interface DoctorDao {
	
	abstract void addDoctor(DoctorPojo doc) throws Exception;

}
