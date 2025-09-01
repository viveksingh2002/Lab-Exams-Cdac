#include<iostream>
#include<string>

#include "Employee.h" 



void Employee::setCompanyName(string companyName){
    this->companyName = companyName;
}

string Employee::getCompanyName(void){
    return this->companyName;
}

void Employee::setEmployeeName(string employeeName){
    this->employeeName = employeeName;
}

string Employee::getEmployeeName(void){
    return this->employeeName;
}

void Employee::setSalary(double salary){
    this->salary = salary;
}

double Employee::getSalary(void){
    return this->salary;
}

void Employee::setNoOfLeave(int noOfLeave) throw(NegativeValueNotAllowedException) {
    if(noOfLeave<0){
        throw NegativeValueNotAllowedException("No. of leaves cannot be negative.");
    }
    this->noOfLeave = noOfLeave;
}

int Employee::getNoOfLeave(void){
    return this->noOfLeave;
}

void Employee::acceptRecord(void) throw(NegativeValueNotAllowedException)  {
    string companyName, employeeName;
    int noOfLeave;
    cout<<"Company Name: ";
    cin>>companyName;
    cout<<"Employee Name: ";
    cin>>employeeName;
    cout<<"No of Leave taken: ";
    cin>>noOfLeave;

    this->setCompanyName(companyName);
    this->setEmployeeName(employeeName);
    this->setNoOfLeave(noOfLeave);
    this->setSalary(0);
}

void Employee::displayRecord(void){
    cout<<"Company Name: "<<this->companyName<<endl;
    cout<<"Employee Name: "<<this->employeeName<<endl;
    cout<<"No of Leave taken: "<<this->noOfLeave<<endl;
    cout<<"Salary: "<<this->salary<<endl;
}