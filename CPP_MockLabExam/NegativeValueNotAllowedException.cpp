
#include<iostream>
#include<string>

using namespace std;

class NegativeValueNotAllowedException{

    private:
        string message;
    
    public:
        NegativeValueNotAllowedException(string message){
            this->message = message;
        }

        string getMessage(void){
            return this->message;
        }

};
