package com.backend.entities;

import java.time.LocalDate;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.EnumType;
import jakarta.persistence.Enumerated;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;


@Entity
@Table(name = "employee_attendance")
@Getter
@Setter
@ToString
public class Employee {
	@Id
	@Column(name = "employee_id")
	private Long id;
	@Column(name = "employee_name")
	private String employeeName;
	private String department;
	private LocalDate attendanceDate;
	@Enumerated(EnumType.STRING)
	private PresentStatus status;
	@Column(name = "hours_worked")
	private Integer hoursWorked;

}
