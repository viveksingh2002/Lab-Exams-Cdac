#include<iostream>
#include<string>

#include "HrEmployee.h" 

void HrEmployee::setNoOfEmployeeHired(int noOfEmployeeHired) throw(NegativeValueNotAllowedException) {
    if(noOfEmployeeHired<0){
        throw NegativeValueNotAllowedException("No. of employee hired cannot be negative.");
    }
    this->noOfEmployeeHired = noOfEmployeeHired;
}

int HrEmployee::getNoOfEmployeeHired(void){
    return this->noOfEmployeeHired;
}

void HrEmployee::acceptRecord(void) throw(NegativeValueNotAllowedException) {
    int noOfEmployeeHired;
    Employee::acceptRecord();
    cout<<"No. of employee hired: ";
    cin>>noOfEmployeeHired;
    this->setNoOfEmployeeHired(noOfEmployeeHired);
}

void HrEmployee::displayRecord(void){
    Employee::displayRecord();
    cout<<"No. of employee hired: "<<this->noOfEmployeeHired<<endl;
}

void HrEmployee::calculateSalary(void){
    double calculatedSalary;
    int noOfDaysPresent = daysInMonth-(this->getNoOfLeave() > HrEmployee::maxPaidLeave?(this->getNoOfLeave()-HrEmployee::maxPaidLeave):0);
    calculatedSalary = HrEmployee::salaryPerDay*noOfDaysPresent+HrEmployee::incentivePerEmployee*this->noOfEmployeeHired;
    this->setSalary(calculatedSalary);
}

// static varibale global decalaration
const int HrEmployee::maxPaidLeave = 3;
const double HrEmployee::salaryPerDay = 1250.0;
const double HrEmployee::incentivePerEmployee = 500.0;