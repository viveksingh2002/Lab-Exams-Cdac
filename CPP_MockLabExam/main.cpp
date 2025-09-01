

#include "Employee.h"
#include "FactoryEmployee.cpp"

int main(){

    try{

        int choice;
        Employee* emp;

        while((choice = FactoryEmployee::menuList())){
            try{
                emp = FactoryEmployee::getInstance(choice);
                if(emp!=NULL){

                    cout<<"#####################################################"<<endl;
                    emp->acceptRecord();
                    cout<<"#####################################################"<<endl;
                    emp->calculateSalary();
                    cout<<"#####################################################"<<endl;
                    emp->displayRecord();
                    cout<<"#####################################################"<<endl;

                } 
            }catch(NegativeValueNotAllowedException &ex){
                cout<<ex.getMessage()<<endl;
            }

            delete emp;
            emp = NULL;
        }


    }catch(...){
        cout<<"Generic Exception."<<endl;
    }

}