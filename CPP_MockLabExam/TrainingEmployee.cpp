#include<iostream>
#include<string>

#include "TrainingEmployee.h" 

void TrainingEmployee::setNoOfLectureSession(int noOfLectureSession) throw(NegativeValueNotAllowedException) {
    if(noOfLectureSession<0){
        throw NegativeValueNotAllowedException("No. of Lecture session cannot be negative.");
    }
    this->noOfLectureSession = noOfLectureSession;
}

int TrainingEmployee::getNoOfLectureSession(void){
    return this->noOfLectureSession;
}

void TrainingEmployee::setNoOfLabSession(int noOfLabSession) throw(NegativeValueNotAllowedException) {
    if(noOfLabSession<0){
        throw NegativeValueNotAllowedException("No. of Lab session cannot be negative.");
    }
    this->noOfLabSession = noOfLabSession;
}

int TrainingEmployee::getNoOfLabSession(void){
    return this->noOfLabSession;
}

void TrainingEmployee::acceptRecord(void) throw(NegativeValueNotAllowedException) {
    int noOfLectureSession, noOfLabSession;
    Employee::acceptRecord();
    cout<<"No. of lecture session attend: ";
    cin>>noOfLectureSession;
    cout<<"No. of lab session attend: ";
    cin>>noOfLabSession;

    this->setNoOfLectureSession(noOfLectureSession);
    this->setNoOfLabSession(noOfLabSession);
    
}

void TrainingEmployee::displayRecord(void){
    Employee::displayRecord();
    cout<<"No. of lecture session attend: "<<this->noOfLectureSession<<endl;
    cout<<"No. of lab session attend: "<<this->noOfLabSession<<endl;
}


void TrainingEmployee::calculateSalary(void) {
    double calculatedSalary;
    int noOfDaysPresent = daysInMonth-(this->getNoOfLeave() > TrainingEmployee::maxPaidLeave?(this->getNoOfLeave()-TrainingEmployee::maxPaidLeave):0);
    calculatedSalary = TrainingEmployee::salaryPerLecture*noOfDaysPresent+TrainingEmployee::incentivePerLab*this->noOfLabSession;
    this->setSalary(calculatedSalary);

}


// static variable global decalaration 
const int TrainingEmployee::maxPaidLeave = 2;
const double TrainingEmployee::salaryPerLecture = 900.0;
const double TrainingEmployee::incentivePerLab = 400.0;