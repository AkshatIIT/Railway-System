

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

using namespace std;

void CreateBooking(Station s1, Station s2, Date dob, Date dor, const BookingClass& bookingClass,string bookingCategory, Passenger *p){
    if(bookingCategory=="General" || bookingCategory=="Ladies"){
        cout<<GeneralBooking(s1,s2,dob,dor,bookingClass,General::Type(),p)<<endl;
    }
    else if(bookingCategory=="Senior Citizen"){
        cout<<SeniorCitizenBooking(s1,s2,dob,dor,bookingClass,SeniorCitizen::Type(),p)<<endl;
    }
    else if(bookingCategory=="Tatkal"){
        cout<<TatkalBooking(s1,s2,dob,dor,bookingClass,Tatkal::Type(),p)<<endl;
    }
    else if(bookingCategory=="Premium Tatkal"){
        cout<<PremiumTatkalBooking(s1,s2,dob,dor,bookingClass,PremiumTatkal::Type(),p)<<endl;
    }
    else if(bookingCategory=="Divyaang"){
        if(p->GetDisabilityType()=="Blind"){
            cout<<BlindBooking(s1,s2,dob,dor,bookingClass,Blind::Type(),p)<<endl;
        }
        else if(p->GetDisabilityType()=="Orthopaedically Handicapped"){
            cout<<OHBooking(s1,s2,dob,dor,bookingClass,OH::Type(),p)<<endl;
        }
        else if(p->GetDisabilityType()=="Cancer"){
            cout<<CancerBooking(s1,s2,dob,dor,bookingClass,Cancer::Type(),p)<<endl;
        }
        else if(p->GetDisabilityType()=="TB"){
            cout<<TBBooking(s1,s2,dob,dor,bookingClass,TB::Type(),p)<<endl;
        }
        else{
            try{throw Bad_Divyaang{};}
            catch(Bad_Divyaang &e){
            std::cout << e.what() << std::endl;
            }
        }
    }
    else{
        try{throw Bad_Category{};}
        catch(Bad_Category &e){
        std::cout << e.what() << std::endl;
        }
    }
}

int main(){
    Date current_date = Date(9,4,2021);

    Passenger p_Gen("17r9zzzzzq1g","7756210444",Date(4,2,2001),"Male","Ishan");
    CreateBooking(Station("Mumbai"),Station("Kolkata"),Date(20,4,2021),current_date,BookingClass::AC3Tier::Type(),"General",&p_Gen);

    Passenger p_tatkal("17r9zz66z21g","4456214444",Date(4,2,1959),"female","Ishan");
    CreateBooking(Station("Bangalore"),Station("Kolkata"),Date(10,4,2021),current_date,BookingClass::ACFirstClass::Type(),"Tatkal",&p_tatkal);

    Passenger p_ptatkal("17r95z66z21g","7758814444",Date(4,2,1959),"female","Ishan");
    CreateBooking(Station("Bangalore"),Station("Chennai"),Date(20,5,2021),current_date,BookingClass::ACChairCar::Type(),"Premium Tatkal",&p_ptatkal);

    Passenger p_senior("17r95z64z21g","7858814444",Date(1,1,1959),"male","Ishan");
    CreateBooking(Station("Delhi"),Station("Chennai"),Date(20,6,2021),current_date,BookingClass::Sleeper::Type(),"Senior Citizen",&p_senior);

    Passenger p_blind("17r95z64z21g","7858814444",Date(1,1,1959),"female","Ishan","","","Blind");
    CreateBooking(Station("Kolkata"),Station("Chennai"),Date(4,6,2021),current_date,BookingClass::SecondSitting::Type(),"Divyaang",&p_blind);

    Passenger p_ortho("17r95z64z21g","7858814444",Date(1,1,1959),"female","Ishan","","","Orthopaedically Handicapped");
    CreateBooking(Station("Delhi"),Station("Bangalore"),Date(20,6,2021),current_date,BookingClass::ExecutiveChairCar::Type(),"Divyaang",&p_ortho);

    Passenger p_cancer("17r95z64z21g","7858814444",Date(1,1,1959),"male","Ishan","","","Cancer");
    CreateBooking(Station("Delhi"),Station("Mumbai"),Date(20,6,2021),current_date,BookingClass::AC3Tier::Type(),"Divyaang",&p_cancer);

    Passenger p_tb("17r95z64z21g","7858814444",Date(1,1,1959),"female","Ishan","","","TB");
    CreateBooking(Station("Kolkata"),Station("Chennai"),Date(20,6,2021),current_date,BookingClass::FirstClass::Type(),"Divyaang",&p_tb);
}
