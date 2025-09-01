#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>

#include "NegativeValueNotAllowedException.cpp"

#define daysInMonth 31

using namespace std;

class Employee{
    private:
        string companyName;
        string employeeName;
        double salary;
        int noOfLeave; 
    
    public:
        Employee(void): companyName(" "), employeeName(" "), salary(0.0), noOfLeave(0) { }

        void setCompanyName(string companyName);

        string getCompanyName(void);

        void setEmployeeName(string employeeName);

        string getEmployeeName(void);

        void setSalary(double salary);

        double getSalary(void);

        void setNoOfLeave(int noOfLeave) throw(NegativeValueNotAllowedException);

        int getNoOfLeave(void);

        virtual void acceptRecord(void) throw(NegativeValueNotAllowedException);

        virtual void displayRecord(void);

    virtual void calculateSalary(void) = 0;

};

#endif