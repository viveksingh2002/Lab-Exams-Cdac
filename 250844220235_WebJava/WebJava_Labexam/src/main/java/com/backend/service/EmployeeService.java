package com.backend.service;

import java.time.LocalDate;
import java.util.List;

import com.backend.dtos.ApiResponse;
import com.backend.dtos.CountEmployee;
import com.backend.entities.Employee;


public interface EmployeeService {
	
	ApiResponse addEmployee(Employee employee);

	Employee getEmployeeByWorkhour();
	
	List<Employee> getEmployeesAbsentOnDate(LocalDate date);
	
	List<CountEmployee> getCountOfEmployeesGroupByDeptandStatus();
	
//	List<Employee> employeePresentOnAllWorkingDays(LocalDate firstDate, LocalDate lastDate);

}
