#include <iostream>
#include <string>

using namespace std;

// Custom exception for handling negative prices or charges
class InvalidPriceException
{

private:
    string message;

public:
    // parameterize contructor
    InvalidPriceException(string message) : message(message) {}

    string getMessage(void) const
    {
        return this->message;
    }
};

// Base class representing generic vehicle servicing
class Servicing
{
private:
    // Data-members
    string customerName;
    string vehicleNo;
    long long mobileNo;
    double totalBill;

public:
    Servicing(void) : customerName(" "), vehicleNo(" "), mobileNo(0), totalBill(0.0) {}

    // function declarations

    // Mutator (setter)
    void setCustomerName(string customerName);

    void setVehicleNo(string vehicleNo);

    void setMobileNo(long long mobileNo);

    void setTotalBill(double totalBill);

    // Inspector (getter)

    string getCustomerName(void);

    string getVehicleNo(void);

    long getMobileNo(void);

    double getTotalBill(void);

    // Accept customer details from user input
    virtual void acceptData(void);

    // Display customer details
    virtual void displayData(void);

    // pure virtual function to be implement in derived class
    virtual void calculateTotalBill(void) = 0;

    // Print the final bill with customer details and total charges
    void displayBill(void);
};

// Servicing class: function definitions
void Servicing::setCustomerName(string customerName)
{
    this->customerName = customerName;
}

void Servicing::setVehicleNo(string vehicleNo)
{
    this->vehicleNo = vehicleNo;
}

void Servicing::setMobileNo(long long mobileNo)
{
    this->mobileNo = mobileNo;
}

void Servicing::setTotalBill(double totalBill)
{
    this->totalBill = totalBill;
}

string Servicing::getCustomerName(void)
{
    return this->customerName;
}

string Servicing::getVehicleNo(void)
{
    return this->vehicleNo;
}

long Servicing::getMobileNo(void)
{
    return this->mobileNo;
}

double Servicing::getTotalBill(void)
{
    return this->totalBill;
}

void Servicing::acceptData(void)
{
    cout << "Customer Name : ";
    cin >> this->customerName;
    cout << "Customer vehicle No. : ";
    cin >> this->vehicleNo;
    cout << "Customer mobile No. : ";
    cin >> this->mobileNo;
}

void Servicing::displayData(void)
{
    cout << "Customer Name : " << this->customerName << endl;
    cout << "Customer Mobile No. : " << this->mobileNo << endl;
    cout << "Customer Vehicle No. : " << this->vehicleNo << endl;
}

void Servicing::displayBill(void)
{

    cout << "################################################" << endl;
    cout << "Invoice" << endl;

    this->displayData();

    cout << "The total bill: " << this->totalBill << endl;

    cout << "################################################" << endl;
}

// Derived class for maintenance/repair services
// Includes part cost, labour charges, and GST
class Maintenance : public Servicing
{

private:
    // Data-members
    string partName;
    double partPrice;
    double labourCharges;

    const static float gstOnPurchasedPart;
    const static float gstOnLabourCharges;

public:
    Maintenance(void) : partName(" "), partPrice(0.0), labourCharges(0.0) {}

    // function declarations

    // Mutator (setter)
    void setPartName(string partName);

    void setPartPrice(double partPrice) throw(InvalidPriceException);

    void setLabourCharges(double labourCharges);

    // Inspector (getter)
    string getPartName(void);

    double getPartPrice(void);

    double getLaboutCharges(void);

    // Accept customer details from user input
    void acceptData(void) throw(InvalidPriceException);

    // Display customer details
    void displayData(void);

    void calculateTotalBill(void);
};

// Maintenance class: function definitions
void Maintenance::setPartName(string partName)
{
    this->partName = partName;
}

void Maintenance::setPartPrice(double partPrice) throw(InvalidPriceException)
{
    if (partPrice < 0)
    {
        throw InvalidPriceException("Invalid input! Price/Charge cannot be negative.");
    }
    this->partPrice = partPrice;
}

void Maintenance::setLabourCharges(double labourCharges)
{
    if (labourCharges < 0)
    {
        throw InvalidPriceException("Invalid input! Price/Charge cannot be negative.");
    }
    this->labourCharges = labourCharges;
}

string Maintenance::getPartName(void)
{
    return this->partName;
}

double Maintenance::getPartPrice(void)
{
    return this->partPrice;
}

double Maintenance::getLaboutCharges(void)
{
    return this->labourCharges;
}

void Maintenance::acceptData(void) throw(InvalidPriceException)
{

    string partName;
    double partPrice;
    double labourCharges;
    Servicing::acceptData();

    cout << "Name of part: ";
    cin >> partName;
    cout << "Price of part: ";
    cin >> partPrice;
    cout << "Labour charges: ";
    cin >> labourCharges;

    // validating the price using setters;
    this->setPartName(partName);
    this->setPartPrice(partPrice);
    this->setLabourCharges(labourCharges);
}

void Maintenance::displayData(void)
{

    Servicing::displayData();
    cout << "Name of part: " << this->partName << endl;
    cout << "Price of part: " << this->partPrice << endl;
    cout << "Labout charges: " << this->labourCharges << endl;
}

void Maintenance::calculateTotalBill(void)
{
    double totalBill = 0;
    // Calculate the total cost
    totalBill += this->partPrice + this->labourCharges;
    // adding the gst
    totalBill += (this->partPrice * Maintenance::gstOnPurchasedPart) + (this->labourCharges * Maintenance::gstOnLabourCharges);

    this->setTotalBill(totalBill);
}

// Derived class for engine/gear oil change services
// Calculates cost including GST on oil price
class OilChange : public Servicing
{

private:
    // Data-members
    string oilName;
    double oilPrice;

    const static float gstOnOilPrice;

public:
    OilChange(void) : oilName(" "), oilPrice(0.0) {}

    // function declarations

    // Mutator (setter)
    void setOilName(string oilName);

    void setOilPrice(double oilPrice);

    // Inspector (getter)
    string getOilName(void);

    double getOilPrice(void);

    // Accept customer details from user input
    void acceptData(void) throw(InvalidPriceException);

    // Display customer details
    void displayData(void);

    // Implementation fo virtual function of parent class
    void calculateTotalBill(void);
};

// OilChange class: function definitions
void OilChange::setOilName(string oilName)
{
    this->oilName = oilName;
}

void OilChange::setOilPrice(double oilPrice)
{
    if (oilPrice < 0)
    {
        throw InvalidPriceException("Invalid input! Price/Charge cannot be negative.");
    }
    this->oilPrice = oilPrice;
}

string OilChange::getOilName(void)
{
    return this->oilName;
}

double OilChange::getOilPrice(void)
{
    return this->oilPrice;
}

void OilChange::acceptData(void) throw(InvalidPriceException)
{
    Servicing::acceptData();

    string oilName;
    double oilPrice;

    cout << "Name of oil: ";
    cin >> oilName;
    cout << "Price of oil: ";
    cin >> oilPrice;

    this->setOilName(oilName);
    this->setOilPrice(oilPrice);
}

void OilChange::displayData(void)
{

    Servicing::displayData();

    cout << "Name of oil: " << oilName << endl;
    cout << "Price of oil: " << oilPrice << endl;
}

void OilChange::calculateTotalBill(void)
{
    double totalBill = 0;
    // Calculate the total cost
    totalBill += this->oilPrice;
    // Adding the gst
    totalBill += (this->oilPrice * OilChange::gstOnOilPrice);

    this->setTotalBill(totalBill);
}

// Design-Pattern
// Factory class to create Servicing objects based on user choice
class FactoryServicing
{

public:
    // Factory method: returns a pointer to a derived Servicing object
    // (Maintenance or OilChange) depending on menu choice
    static Servicing *getInstance(int choice)
    {
        Servicing *servicing;
        servicing = NULL;

        switch (choice)
        {
        case 1:
            servicing = new Maintenance();
            break;

        case 2:
            servicing = new OilChange();
            break;

        default:
            cout << "Invalid choice!!try again." << endl;
            break;
        }

        return servicing;
    }

    // Menu List
    // Return the user choice
    static int menuList(void)
    {
        int choice;

        cout << "0. Exit" << endl;
        cout << "1. Maintenance / Repairing" << endl;
        cout << "2. Engine / Gear Oil Change" << endl;
        cout << "Enter the choice: ";
        cin >> choice;

        return choice;
    }
};

// Global decalaration of static variables;
const float Maintenance::gstOnPurchasedPart = 0.05;
const float Maintenance::gstOnLabourCharges = 0.05;
const float OilChange::gstOnOilPrice = 0.12;

// Program entry point
int main()
{

    // Outer try-catch block to handle any unhandled exceptions
    try
    {

        int choice;
        // Pointer of Servicing class
        Servicing *servicing;

        while ((choice = FactoryServicing::menuList()) != 0)
        {

            // Getting the instance of class
            servicing = FactoryServicing::getInstance(choice);

            if (servicing != NULL)
            {

                // Inner try-catch to handle InvalidPriceException from input
                try
                {
                    // Calling the member fuction with the object of chosen derived class
                    servicing->acceptData();
                    servicing->calculateTotalBill();
                    servicing->displayBill();
                }
                catch (const InvalidPriceException &ex)
                {

                    cout << ex.getMessage() << endl;
                }
            }

            // Free dynamically allocated memory and reset pointer to NULL
            delete servicing;
            servicing = NULL;
        }
    }
    catch (...)
    {
        cout << "Generic Exception" << endl;
    }
}
