
#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

class Date {

    unsigned int date_, month_, year_;

public:
    //Sets date, month, year
    Date(unsigned int = 1, unsigned int = 1 , unsigned int = 2021);

    //default dtor
    ~Date();

    //returns date
    int getDay();

    //returns month
    int getMonth();
    
    //returns year
    int getYear();
    
    //check the validity
    void ValidDate();

    //computing Age
    float ComputeAge(const Date& other);

    //Overloaded operator to print the Date in dd/MMM/yyyy format 
    friend ostream& operator<<(ostream& os, const Date& d);

    //for Unit testing
    static void UnitTest();
};

#endif
