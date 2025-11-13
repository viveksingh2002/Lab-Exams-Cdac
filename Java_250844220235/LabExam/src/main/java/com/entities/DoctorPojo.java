package com.entities;

public class DoctorPojo {
	
	private int id;
	private String name;
	private String spectialization;
	
	public DoctorPojo() {	}

	public DoctorPojo(int id, String name, String spectialization) {
		super();
		this.id = id;
		this.name = name;
		this.spectialization = spectialization;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getSpectialization() {
		return spectialization;
	}

	public void setSpectialization(String spectialization) {
		this.spectialization = spectialization;
	}

	@Override
	public String toString() {
		return "Doctor [id=" + id + ", name=" + name + ", spectialization=" + spectialization + "]";
	}
	
}
