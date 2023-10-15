

#include<iostream>
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "Passenger.h"
#include "BookingClasses.h"
#include "BookingCategory.h"
#include "Booking.h"
#include "Categories.h"
#include "Exceptions.h"
#include "Gender.h"
using namespace std;

//For unit testing of Date Class 
void Date::UnitTest(){
    cout<<"\n=== Testing Construction ===\n";
    Date d(28,2,2001);
    cout<<"Address of Constructed Object: "<<&d<<endl;
    cout<<"=== Testing operator << ===\n"<<d<<endl;
    cout<<"=== Testing exception ===\n"<<Date(29,2,2021)<<endl;
    
    return;
}

//Unit testing of Booking class and various booking classes
void BookingClass::UnitTest(){
    
    cout<<"\n=== Testing operator << for every Booking Class ===\n"<<endl;
    const BookingClass& b1 = BookingClass::ACFirstClass::Type();
    cout<<b1<<endl;
    const BookingClass& b2 = BookingClass::AC2Tier::Type();
    cout<<b2<<endl;
    const BookingClass& b3 = BookingClass::AC3Tier::Type();
    cout<<b3<<endl;
    const BookingClass& b4 = BookingClass::ACChairCar::Type();
    cout<<b4<<endl;
    const BookingClass& b5 = BookingClass::ExecutiveChairCar::Type();
    cout<<b5<<endl;
    const BookingClass& b6 = BookingClass::FirstClass::Type();
    cout<<b6<<endl;
    const BookingClass& b7 = BookingClass::SecondSitting::Type();
    cout<<b7<<endl;
    const BookingClass& b8 = BookingClass::Sleeper::Type();
    cout<<b8<<endl;


    cout<<"Fare Loaded Factor of "<<b1.GetName()<<" from Virtual GetLoadFactor() Method = "<<b1.GetLoadFactor()<<endl;
    if(b1.GetLoadFactor()!=6.5) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b2.GetName()<<" from Virtual GetLoadFactor() Method = "<<b2.GetLoadFactor()<<endl;
    if(b2.GetLoadFactor()!=4) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b3.GetName()<<" from Virtual GetLoadFactor() Method = "<<b3.GetLoadFactor()<<endl;
    if(b3.GetLoadFactor()!=2.5) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b4.GetName()<<" from Virtual GetLoadFactor() Method = "<<b4.GetLoadFactor()<<endl;
    if(b4.GetLoadFactor()!=2) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b5.GetName()<<" from Virtual GetLoadFactor() Method = "<<b5.GetLoadFactor()<<endl;
    if(b5.GetLoadFactor()!=5) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b6.GetName()<<" from Virtual GetLoadFactor() Method = "<<b6.GetLoadFactor()<<endl;
    if(b6.GetLoadFactor()!=3) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b7.GetName()<<" from Virtual GetLoadFactor() Method = "<<b7.GetLoadFactor()<<endl;
    if(b7.GetLoadFactor()!=0.6) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b8.GetName()<<" from Virtual GetLoadFactor() Method = "<<b8.GetLoadFactor()<<endl;
    if(b8.GetLoadFactor()!=1) cout<<"Error in GetLoadFactor Method\n";

    return;
}

//For unit testing of Passenger Class 
void Passenger::UnitTest(){
    cout<<"=== Testing Constructor ==="<<endl;
    Passenger p("d8d73g28h221","7602045111",Date(28,2,2001),"Male","ISHAN","Abd","","1ow1");
    cout<<p<<endl;

    cout<<"=== Testing Exceptions ==="<<endl;
    Passenger p2("d8d73g28h1","7602045111",Date(28,2,2001),"Male","ISHAN","Abd","","1ow1");
    cout<<p2<<endl;
}

//For unit testing of Railways Class 
void Railways::UnitTest(){
    cout<<"\n=== Testing operator << ===\n"<<Railways::Railway()<<endl;
    
    Station s1("Mumbai"), s2("Delhi");
    cout<<"===Testing GetDistance() Method ===\nDistance between Mumbai and Delhi: "<<Railways::Railway().GetDistance(s1,s2)<<endl;
    
    if(Railways::Railway().GetDistance(s1,s2)!=1447){ cout<<"Error in GetDistance Method\n"; }
    
    Station s3("Kolkata"), s4("Chennai");

    if(Railways::Railway().GetDistance(s3,s4)!=1659){ cout<<"Error in GetDistance Method\n"; }
    return;
}

//For unit testing of Station Class 
void Station::UnitTest(){
    cout<<"\n=== Testing Construction ===\n";
    Station s("Kolkata");
    cout<<"Address of Constructed Object: "<<&s<<endl;
    cout<<"=== Testing GetName() Method ===\nName: "<<s.GetName()<<endl;
    
    if(s.GetName()!="Kolkata"){ cout<<"Error on GetName Method\n"; }
    
    Station other("Mumbai");
    cout<<"=== Testing operator << ===\n"<<s<<" "<<other<<endl;
    cout<<"=== Testing GetDistance() Method ===\nDistance= "<<s.GetDistance(other)<<endl;

    if(s.GetDistance(other)!= 2014){ cout<<"Error on GetDistance Method\n"; }

    Station x("Chennai");
    cout<<"Distance between Chennai and Kolkata = "<<s.GetDistance(x)<<endl;

    if(s.GetDistance(x)!= 1659){ cout<<"Error on GetDistance Method\n"; }

    return;
}

//For unit testing of Category Class 
void BookingCategory::UnitTest(){
    cout<<"\n=========================Testing Construction of every Class===================================="<<endl;
    cout<<"Constructing General Object"<<endl<<"Address of General Category : "<<&General::Type()<<endl;
    cout<<"==================================================================================================="<<endl;
    cout<<"Constructing Tatkal Object"<<endl<<"Address of Tatkal Category : "<<&Tatkal::Type()<<endl;
    cout<<"==================================================================================================="<<endl;
    cout<<"Constructing PremiumTatkal Object"<<endl<<"Address of PremiumTatkal Category : "<<&PremiumTatkal::Type()<<endl;
    cout<<"==================================================================================================="<<endl;
    cout<<"Constructing SeniorCitizen Object"<<endl<<"Address of SeniorCitizen Category : "<<&SeniorCitizen::Type()<<endl;
    cout<<"==================================================================================================="<<endl;
    cout<<"Constructing Blind Object"<<endl<<"Address of Blind Category : "<<&Blind::Type()<<endl;
    cout<<"==================================================================================================="<<endl;
    cout<<"Constructing OH Object"<<endl<<"Address of OH Category : "<<&OH::Type()<<endl;
    cout<<"==================================================================================================="<<endl;
    cout<<"Constructing TB Object"<<endl<<"Address of TB Category : "<<&TB::Type()<<endl;
    cout<<"==================================================================================================="<<endl;
    cout<<"Constructing Cancer Object"<<endl<<"Address of Cancer Category : "<<&Cancer::Type()<<endl;
    cout<<"==================================================================================================="<<endl;
}

//For unit testing of Gender Class 
// void Gender::UnitTest() {
//     if (!Gender::IsMale(Gender::Male::Type())) {                                     // Check IsMale function
//         cout << "Error in IsMale() function" << endl;
//     }
//     if (Gender::Male::Type().GetName() != "Male") {                                 // Check the GetName function
//         cout << "Error in GetName() function" << endl;
//     }
//     cout << "---------------------------------------------------------------------------------" << endl;
// }

int main() {
   	
    cout<<"\n=========================Testing Railways Class=============================="<<endl;
    Railways::UnitTest();

    cout<<"\n=========================Testing Station Class==============================="<<endl;
    Station::UnitTest();

    cout<<"\n=========================Testing Date Class===================================="<<endl;
    Date::UnitTest();

    cout<<"\n=========================Testing Passenger Class=============================="<<endl;
    Passenger::UnitTest();

    cout<<"\n=========================Testing Booking Classes Class========================="<<endl;
    BookingClass::UnitTest();
    
    cout<<"\n=========================Testing Category Class==============================="<<endl;
    BookingCategory::UnitTest();

    // cout<<"\n=========================Testing Gender Class==============================="<<endl;
    // //Gender::UnitTest();

    return 0;
}
