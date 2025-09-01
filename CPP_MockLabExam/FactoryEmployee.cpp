#include<iostream>
#include<string>

#include "HrEmployee.h"
#include "TrainingEmployee.h"

using namespace std;

class FactoryEmployee{
    public:
    static Employee* getInstance(int choice){

        Employee* emp = NULL;
        switch (choice)
        {
        case 1:
            emp = new HrEmployee();
            break;
        case 2:
            emp = new TrainingEmployee();
            break;
        
        default:
            cout<<"Invalid Input!!"<<endl;
            break;
        }
        
        return emp;
    }

    static int menuList(void){
        int choice;
        cout<<"0. Exit"<<endl;
        cout<<"1. Hr Employee"<<endl;
        cout<<"2. Training Employee"<<endl;
        cout<<"Enter the choice: ";
        cin>>choice;
        return choice;
    }
        
};