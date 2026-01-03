package com.backend.service.impl;

import java.time.LocalDate;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.backend.dtos.ApiResponse;
import com.backend.dtos.CountEmployee;
import com.backend.entities.Employee;
import com.backend.repo.EmployeeRepo;
import com.backend.service.EmployeeService;

import jakarta.transaction.Transactional;


@Service
@Transactional
public class EmployeeServiceImpl implements EmployeeService {
	
	@Autowired
	private EmployeeRepo employeeRepo;

	@Override
	public ApiResponse addEmployee(Employee employee) {
		Employee savedEmp = employeeRepo.save(employee);
		return new ApiResponse("Employee attendace added id: "+savedEmp.getId(), "Success");
	}

	@Override
	public Employee getEmployeeByWorkhour() {
		
		return null;
	}

	@Override
	public List<Employee> getEmployeesAbsentOnDate(LocalDate date) {
		return employeeRepo.getEmployeesAbsentOnDate(date);
	}

	@Override
	public List<CountEmployee> getCountOfEmployeesGroupByDeptandStatus() {
		return employeeRepo.getCountOfEmployeesGroupByDeptandStatus();
	}

	/*
	 * @Override public List<Employee> employeePresentOnAllWorkingDays(LocalDate
	 * firstDate, LocalDate lastDate) {
	 * employeeRepo.getEmployeesPresentAllDays(LocalDate firstDate, localDate
	 * lastDate);
	 * 
	 * return null; }
	 */
	
	
	
	

}
