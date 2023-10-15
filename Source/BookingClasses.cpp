
#include "BookingClasses.h"

BookingClass::BookingClass(const string& name): name_(name){}
BookingClass::~BookingClass(){}    

//static declarations
template<>
const string BookingClass::AC2Tier::sName = "AC2Tier";
template<>
const string BookingClass::AC3Tier::sName = "AC3Tier";
template<>
const string BookingClass::ACChairCar::sName = "ACChairCar";
template<>
const string BookingClass::ACFirstClass::sName = "ACFirstClass";
template<>
const string BookingClass::SecondSitting::sName = "SecondSitting";
template<>
const string BookingClass::Sleeper::sName = "Sleeper";
template<>
const string BookingClass::ExecutiveChairCar::sName = "ExecutiveChairCar";
template<>
const string BookingClass::FirstClass::sName = "FirstClass";

//get set methods
void BookingClass::SetLoadFactor(const double& lf) { this->fareLoadFactor_ = lf; }
const string& BookingClass::GetName() const { return this->name_ ; }
bool BookingClass::IsSitting() const { return this->sitting_ ; }
bool BookingClass::IsAC() const { return this->AC_ ; }
int BookingClass::GetNumberOfTiers() const { return this->numOfTiers_ ; }
double BookingClass::GetReservationCharge() const{ return this->reservationCharge_; }
bool BookingClass::IsLuxury() const { return this->luxury_ ; }
void BookingClass::SetLuxury(const bool& l) { this->luxury_ = l; }
double BookingClass::GetTatkalLoadFactor() const{ return this->tatkalLoadFactor_; }
double BookingClass::GetMinTatkalCharge() const{ return this->minTatkalCharge_; }
double BookingClass::GetMaxTatkalCharge() const{ return this->maxTatkalCharge_; }
double BookingClass::GetMinTatkalDistance() const{ return this->minTatkalDistance_; }
void BookingClass::SetTatkalLoadFactor(const double& tlf){ this->tatkalLoadFactor_ = tlf; }
void BookingClass::SetMinTatkalCharge(const double& mtc){ this->minTatkalCharge_ = mtc; }
void BookingClass::SetMinTatkalDistance(const double& mtd){ this->minTatkalDistance_ = mtd; }

//setting parameters for booking classes
template<>
void BookingClass::AC2Tier::setParameters(){
    this->fareLoadFactor_ = 4.00;
    this->sitting_ = false;
    this->AC_ = true;
    this->numOfTiers_ = 2;
    this->luxury_ = false;
    this->reservationCharge_ = 50;
    this->minTatkalCharge_ = 400;
    this->maxTatkalCharge_ = 500;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::AC3Tier::setParameters(){
    this->fareLoadFactor_ = 2.50;
    this->sitting_ = false;
    this->AC_ = true;
    this->numOfTiers_ = 3;
    this->luxury_ = false;
    this->reservationCharge_ = 40;
    this->minTatkalCharge_ = 300;
    this->maxTatkalCharge_ = 400;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::ACChairCar::setParameters(){
    this->fareLoadFactor_ = 2.00;
    this->sitting_ = true;
    this->AC_ = true;
    this->numOfTiers_ = 0;
    this->luxury_ = false;
    this->reservationCharge_ = 40;
    this->minTatkalCharge_ = 125;
    this->maxTatkalCharge_ = 225;
    this->minTatkalDistance_ = 250;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::ACFirstClass::setParameters(){
    this->fareLoadFactor_ = 6.50;
    this->sitting_ = false;
    this->AC_ = true;
    this->numOfTiers_ = 2;
    this->luxury_ = true;
    this->reservationCharge_ = 60;
    this->minTatkalCharge_ = 400;
    this->maxTatkalCharge_ = 500;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::SecondSitting::setParameters(){
    this->fareLoadFactor_ = 0.60;
    this->sitting_ = true;
    this->AC_ = false;
    this->numOfTiers_ = 0;
    this->luxury_ = false;
    this->reservationCharge_ = 15;
    this->minTatkalCharge_ = 10;
    this->maxTatkalCharge_ = 15;
    this->minTatkalDistance_ = 100;
    this->tatkalLoadFactor_ = 0.1;
}
template<>
void BookingClass::Sleeper::setParameters(){
    this->fareLoadFactor_ = 1.00;
    this->sitting_ = false;
    this->AC_ = false;
    this->numOfTiers_ = 3;
    this->luxury_ = false;
    this->reservationCharge_ = 20;
    this->minTatkalCharge_ = 100;
    this->maxTatkalCharge_ = 200;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::ExecutiveChairCar::setParameters(){
    this->fareLoadFactor_ = 5.00;
    this->sitting_ = true;
    this->AC_ = true;
    this->numOfTiers_ = 0;
    this->luxury_ = true;
    this->reservationCharge_ = 60;
    this->minTatkalCharge_ = 400;
    this->maxTatkalCharge_ = 500;
    this->minTatkalDistance_ = 250;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::FirstClass::setParameters(){
    this->fareLoadFactor_ = 3.00;
    this->sitting_ = false;
    this->AC_ = false;
    this->numOfTiers_ = 2;
    this->luxury_ = true;
    this->reservationCharge_ = 50;
    this->minTatkalCharge_ = 400;
    this->maxTatkalCharge_ = 500;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;

}

//overloading << operator 
ostream& operator<<(ostream& os, const BookingClass& b){
    os<<b.GetName()<<endl;
    os<<" : Fare Load Factor: "<<b.fareLoadFactor_<<endl;
    if(b.IsSitting()) os<<" : Mode: Sitting\n";
    else os<<" : Mode: Sleeping\n";
    if(b.IsAC()) os<<" : Comfort: AC\n";
    else os<<" : Comfort: Non-AC\n";
    os<<" : Bunks: "<<b.GetNumberOfTiers()<<endl;
    if(b.IsLuxury()) os<<" : Luxury: Yes\n";
    else os<<" : Luxury: No\n";
    os<<" : Reservation Charge: "<<b.reservationCharge_<<endl;
    os<<" : Min Tatkal Charge : "<<b.minTatkalCharge_<<endl;
    os<<" : Max Tatkal Charge : "<<b.maxTatkalCharge_<<endl;
    os<<" : Min Tatkal Distance : "<<b.minTatkalDistance_<<endl;
    return os;
}


