package com.backend.dtos;

import java.time.LocalDateTime;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
public class ApiResponse {
	
	private String message;
	private String status;
	private LocalDateTime timeStamp;
	public ApiResponse(String message, String status) {
		super();
		this.message = message;
		this.status = status;
		this.timeStamp = LocalDateTime.now();
	}
	
}
