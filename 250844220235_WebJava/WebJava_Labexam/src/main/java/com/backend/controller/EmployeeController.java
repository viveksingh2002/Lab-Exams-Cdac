package com.backend.controller;

import java.time.LocalDate;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RequestPart;
import org.springframework.web.bind.annotation.RestController;

import com.backend.dtos.ApiResponse;
import com.backend.dtos.CountEmployee;
import com.backend.entities.Employee;
import com.backend.service.EmployeeService;


@RestController
@RequestMapping("/employee")
public class EmployeeController {
	
	@Autowired
	private EmployeeService employeeService;
	
	@PostMapping("/add")
	public ResponseEntity<?> addEmployee(@RequestBody Employee employee){

		ApiResponse resp = employeeService.addEmployee(employee);
		return ResponseEntity.ok(resp);
		
	}
	
	@GetMapping("/")
	public ResponseEntity<?> getEmployeesAbsentOnDate(@RequestParam LocalDate date){
		List<Employee> emps = employeeService.getEmployeesAbsentOnDate(date);
		return ResponseEntity.ok(emps);
	}
	
	@GetMapping("/count")
	public ResponseEntity<?> getCountOfEmployeesGroupByDeptandStatus(){
		List<CountEmployee> count = employeeService.getCountOfEmployeesGroupByDeptandStatus();
		return ResponseEntity.ok(count);
	}

}
