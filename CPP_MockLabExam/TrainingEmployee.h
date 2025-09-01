#ifndef TRAININGEMPLOYEE_H
#define TRAININGEMPLOYEE_H

#include<iostream>
#include<string>

#include "Employee.h"

class TrainingEmployee: public Employee{
    private:
        int noOfLectureSession;
        int noOfLabSession;
        const static int maxPaidLeave;
        const static double salaryPerLecture;
        const static double incentivePerLab;

    public:

        TrainingEmployee(void): noOfLectureSession(0), noOfLabSession(0) { }

        void setNoOfLectureSession(int noOfLectureSession) throw(NegativeValueNotAllowedException);

        int getNoOfLectureSession(void);

        void setNoOfLabSession(int noOfLabSession) throw(NegativeValueNotAllowedException);

        int getNoOfLabSession(void);

        void acceptRecord(void) throw(NegativeValueNotAllowedException);

        void displayRecord(void);


        void calculateSalary(void);
};

#endif
