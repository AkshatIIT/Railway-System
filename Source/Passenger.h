

#ifndef PASSENGER_H
#define PASSENGER_H

#include<iostream>
#include "Date.h"
using namespace std;

class Passenger{

    string firstName_;
    string middleName_;
    string lastName_;
    string name_;
    string aadhar_;
    Date dateOfBirth_;
    string gender_;
    string mobile_;
    string disabilityType_;
    string disabilityID_;
    
public:
    //ctor
    Passenger(const string& aadhar, const string& mobile, const Date& dob, const string& gender, string firstname = "", string middlename = "", string lastname = "", const string& disabilityType = "", const string& disabilityID = "");
    
    //default dtor
    ~Passenger();

    string GetGender();
    string GetDisabilityType();

    Date GetDateOfBirth();

    //overloaded ostream
    friend ostream& operator<<(ostream& os, const Passenger& p);
    
    static void UnitTest();
};

inline string Passenger::GetGender(){ return this->gender_; }
inline string Passenger::GetDisabilityType(){ return this->disabilityType_; }
inline Date Passenger::GetDateOfBirth(){ return this->dateOfBirth_;}

#endif
