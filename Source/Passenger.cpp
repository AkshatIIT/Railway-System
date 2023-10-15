

#include "Passenger.h"
#include "Date.h"
#include "Exceptions.h"

Passenger::Passenger(const string& aadhar, const string& mobile, const Date& dob, const string& gender, string firstname, string middlename, string lastname, const string& disabilityType, const string& disabilityID){
    
    this->dateOfBirth_ = dob;
    this->gender_ = gender;
    this->firstName_ = firstname;
    this->middleName_ = middlename;
    this->lastName_ = lastname;
    this->disabilityID_ = disabilityID;
    this->disabilityType_ = disabilityType;
    try{
        if(firstname.length()==0 && lastname.length()== 0)
            throw Bad_Name{};
        else this->name_ = firstname+" "+middlename+" "+lastname;
    }
    catch(Bad_Name &e){
        std::cout << e.what() << std::endl;
    }
    try{
        if(mobile.length() == 10) this->mobile_ = mobile;
        else throw Bad_Mobile{};
    }
    catch(Bad_Mobile &e){
        std::cout << e.what() << std::endl;
    }
    try{
        if(aadhar.length() == 12) this->aadhar_ = aadhar;
        else throw Bad_Aadhar{};
    }
    catch(Bad_Aadhar &e){
        std::cout << e.what() << std::endl;
    }
    
    
}
    
Passenger::~Passenger(){ }

ostream& operator<<(ostream& os, const Passenger& p){
    os<<p.name_<<endl;
    os<<" : Date of Birth: "<<p.dateOfBirth_<<endl;
    os<<" : Gender: "<<p.gender_<<endl;
    os<<" : Aadhar: "<<p.aadhar_<<endl;
    if(p.mobile_!="") os<<" : Mobile: "<<p.mobile_<<endl;
    if(p.disabilityType_!="") os<<" : Disability Type: "<<p.disabilityType_<<endl;
    if(p.disabilityID_!="") os<<" : Disability ID: "<<p.disabilityID_<<endl;
    return os;
}
