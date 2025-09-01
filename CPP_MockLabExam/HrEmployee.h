#ifndef HREMPLOYEE_H
#define HREMPLOYEE_H

#include<iostream>
#include<string>

#include "Employee.h"

class HrEmployee: public Employee{
    private:
        int noOfEmployeeHired;
        const static int maxPaidLeave;
        const static double salaryPerDay;
        const static double incentivePerEmployee;

    public:
        HrEmployee(void): noOfEmployeeHired(0) { }

        void setNoOfEmployeeHired(int noOfEmployeeHired) throw(NegativeValueNotAllowedException);

        int getNoOfEmployeeHired(void);

        void acceptRecord(void) throw(NegativeValueNotAllowedException) ;

        void displayRecord(void);

        void calculateSalary(void);


};

#endif