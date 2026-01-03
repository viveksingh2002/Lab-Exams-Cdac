package com.backend.repo;

import java.time.LocalDate;
import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import com.backend.dtos.CountEmployee;
import com.backend.entities.Employee;

public interface EmployeeRepo extends JpaRepository<Employee, Long> {

	@Query("select e from Employee e where e.status='Absent' and e.attendanceDate=:date")
	List<Employee> getEmployeesAbsentOnDate(@Param("date") LocalDate date);
	
	@Query("""
		       select new com.backend.dtos.CountEmployee(
		           e.department,
		           e.status,
		           count(e)
		       )
		       from Employee e
		       group by e.department, e.status
		       """)
	List<CountEmployee> getCountOfEmployeesGroupByDeptandStatus();
}
