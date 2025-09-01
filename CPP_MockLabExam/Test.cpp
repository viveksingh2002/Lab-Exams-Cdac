#include <iostream>
#include <string>

#define daysInMonth 31

using namespace std;

class NegativeValueNotAllowedException
{

private:
    string message;

public:
    NegativeValueNotAllowedException(string message)
    {
        this->message = message;
    }

    string getMessage(void)
    {
        return this->message;
    }
};

class Employee
{
private:
    string companyName;
    string employeeName;
    double salary;
    int noOfLeave;

public:
    Employee(void) : companyName(" "), employeeName(" "), salary(0.0), noOfLeave(0) {}

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

void Employee::setCompanyName(string companyName)
{
    this->companyName = companyName;
}

string Employee::getCompanyName(void)
{
    return this->companyName;
}

void Employee::setEmployeeName(string employeeName)
{
    this->employeeName = employeeName;
}

string Employee::getEmployeeName(void)
{
    return this->employeeName;
}

void Employee::setSalary(double salary)
{
    this->salary = salary;
}

double Employee::getSalary(void)
{
    return this->salary;
}

void Employee::setNoOfLeave(int noOfLeave) throw(NegativeValueNotAllowedException)
{
    if (noOfLeave < 0)
    {
        throw NegativeValueNotAllowedException("No. of leaves cannot be negative.");
    }
    this->noOfLeave = noOfLeave;
}

int Employee::getNoOfLeave(void)
{
    return this->noOfLeave;
}

void Employee::acceptRecord(void) throw(NegativeValueNotAllowedException)
{
    string companyName, employeeName;
    int noOfLeave;
    cout << "Company Name: ";
    cin >> companyName;
    cout << "Employee Name: ";
    cin >> employeeName;
    cout << "No of Leave taken: ";
    cin >> noOfLeave;

    this->setCompanyName(companyName);
    this->setEmployeeName(employeeName);
    this->setNoOfLeave(noOfLeave);
    this->setSalary(0);
}

void Employee::displayRecord(void)
{
    cout << "Company Name: " << this->companyName << endl;
    cout << "Employee Name: " << this->employeeName << endl;
    cout << "No of Leave taken: " << this->noOfLeave << endl;
    cout << "Salary: " << this->salary << endl;
}

class HrEmployee : public Employee
{
private:
    int noOfEmployeeHired;
    const static int maxPaidLeave;
    const static double salaryPerDay;
    const static double incentivePerEmployee;

public:
    HrEmployee(void) : noOfEmployeeHired(0) {}

    void setNoOfEmployeeHired(int noOfEmployeeHired) throw(NegativeValueNotAllowedException);

    int getNoOfEmployeeHired(void);

    void acceptRecord(void) throw(NegativeValueNotAllowedException);

    void displayRecord(void);

    void calculateSalary(void);
};

void HrEmployee::setNoOfEmployeeHired(int noOfEmployeeHired) throw(NegativeValueNotAllowedException)
{
    if (noOfEmployeeHired < 0)
    {
        throw NegativeValueNotAllowedException("No. of employee hired cannot be negative.");
    }
    this->noOfEmployeeHired = noOfEmployeeHired;
}

int HrEmployee::getNoOfEmployeeHired(void)
{
    return this->noOfEmployeeHired;
}

void HrEmployee::acceptRecord(void) throw(NegativeValueNotAllowedException)
{
    cout << "acceptRecord(void) hr" << endl;
    int noOfEmployeeHired;
    Employee::acceptRecord();
    cout << "No. of employee hired: ";
    cin >> noOfEmployeeHired;
    this->setNoOfEmployeeHired(noOfEmployeeHired);
}

void HrEmployee::displayRecord(void)
{
    Employee::displayRecord();
    cout << "No. of employee hired: " << this->noOfEmployeeHired << endl;
}

void HrEmployee::calculateSalary(void)
{
    double calculatedSalary;
    int noOfDaysPresent = daysInMonth - (this->getNoOfLeave() > HrEmployee::maxPaidLeave ? (this->getNoOfLeave() - HrEmployee::maxPaidLeave) : 0);
    calculatedSalary = HrEmployee::salaryPerDay * noOfDaysPresent + HrEmployee::incentivePerEmployee * this->noOfEmployeeHired;
    this->setSalary(calculatedSalary);
}

class TrainingEmployee : public Employee
{
private:
    int noOfLectureSession;
    int noOfLabSession;
    const static int maxPaidLeave;
    const static double salaryPerLecture;
    const static double incentivePerLab;

public:
    TrainingEmployee(void) : noOfLectureSession(0), noOfLabSession(0) {}

    void setNoOfLectureSession(int noOfLectureSession) throw(NegativeValueNotAllowedException);

    int getNoOfLectureSession(void);

    void setNoOfLabSession(int noOfLabSession) throw(NegativeValueNotAllowedException);

    int getNoOfLabSession(void);

    void acceptRecord(void) throw(NegativeValueNotAllowedException);

    void displayRecord(void);

    void calculateSalary(void);
};

void TrainingEmployee::setNoOfLectureSession(int noOfLectureSession) throw(NegativeValueNotAllowedException)
{
    if (noOfLectureSession < 0)
    {
        throw NegativeValueNotAllowedException("No. of Lecture session cannot be negative.");
    }
    this->noOfLectureSession = noOfLectureSession;
}

int TrainingEmployee::getNoOfLectureSession(void)
{
    return this->noOfLectureSession;
}

void TrainingEmployee::setNoOfLabSession(int noOfLabSession) throw(NegativeValueNotAllowedException)
{
    if (noOfLabSession < 0)
    {
        throw NegativeValueNotAllowedException("No. of Lab session cannot be negative.");
    }
    this->noOfLabSession = noOfLabSession;
}

int TrainingEmployee::getNoOfLabSession(void)
{
    return this->noOfLabSession;
}

void TrainingEmployee::acceptRecord(void) throw(NegativeValueNotAllowedException)
{
    int noOfLectureSession, noOfLabSession;
    Employee::acceptRecord();
    cout << "No. of lecture session attend: ";
    cin >> noOfLectureSession;
    cout << "No. of lab session attend: ";
    cin >> noOfLabSession;

    this->setNoOfLectureSession(noOfLectureSession);
    this->setNoOfLabSession(noOfLabSession);
}

void TrainingEmployee::displayRecord(void)
{
    Employee::displayRecord();
    cout << "No. of lecture session attend: " << this->noOfLectureSession << endl;
    cout << "No. of lab session attend: " << this->noOfLabSession << endl;
}

void TrainingEmployee::calculateSalary(void)
{
    double calculatedSalary;
    int noOfDaysPresent = daysInMonth - (this->getNoOfLeave() > TrainingEmployee::maxPaidLeave ? (this->getNoOfLeave() - TrainingEmployee::maxPaidLeave) : 0);
    calculatedSalary = TrainingEmployee::salaryPerLecture * noOfDaysPresent + TrainingEmployee::incentivePerLab * this->noOfLabSession;
    this->setSalary(calculatedSalary);
}

// all Statitc variable global decalaration
const int HrEmployee::maxPaidLeave = 3;
const double HrEmployee::salaryPerDay = 1250.0;
const double HrEmployee::incentivePerEmployee = 500.0;
const int TrainingEmployee::maxPaidLeave = 2;
const double TrainingEmployee::salaryPerLecture = 900.0;
const double TrainingEmployee::incentivePerLab = 400.0;

// Factory system design

class FactoryEmployee
{
public:
    static Employee *getInstance(int choice)
    {

        Employee *emp = NULL;
        switch (choice)
        {
        case 1:
            emp = new HrEmployee();
            break;
        case 2:
            emp = new TrainingEmployee();
            break;

        default:
            cout << "Invalid Input!!" << endl;
            break;
        }

        return emp;
    }

    static int menuList(void)
    {
        int choice;
        cout << "1. Hr Employee" << endl;
        cout << "2. Training Employee" << endl;
        cout << "Enter the choice: ";
        cin >> choice;
        return choice;
    }
};

int main()
{

    try
    {

        int choice;
        Employee *emp;

        while ((choice = FactoryEmployee::menuList()))
        {
            try
            {
                emp = FactoryEmployee::getInstance(choice);
                if (emp != NULL)
                {

                    cout << "#####################################################" << endl;
                    emp->acceptRecord();
                    cout << "#####################################################" << endl;
                    emp->calculateSalary();
                    cout << "#####################################################" << endl;
                    emp->displayRecord();
                    cout << "#####################################################" << endl;
                }
            }
            catch (NegativeValueNotAllowedException &ex)
            {
                cout << ex.getMessage() << endl;
            }

            delete emp;
            emp = NULL;
        }
    }
    catch (...)
    {
        cout << "Generic Exception." << endl;
    }
}
