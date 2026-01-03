package com.backend.dtos;

import com.backend.entities.PresentStatus;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
@AllArgsConstructor
public class CountEmployee {
	
	private String department;
	private PresentStatus status;
	private Long count;

}
