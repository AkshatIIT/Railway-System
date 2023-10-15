

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

    Passenger p_baddate("17r95z64z21g","7858814444",Date(1,1,1959),"female","Ishan","","","TB");
    CreateBooking(Station("Kolkata"),Station("Chennai"),Date(29,2,2021),current_date,BookingClass::FirstClass::Type(),"Divyaang",&p_baddate);

    Passenger p_pastdate("17r95z64z21g","7858814444",Date(1,1,1959),"female","Ishan","","","TB");
    CreateBooking(Station("Kolkata"),Station("Chennai"),Date(2,2,2020),current_date,BookingClass::FirstClass::Type(),"Divyaang",&p_pastdate);

    Passenger p_badpass("17r95z64z1g","78588174444",Date(1,1,1959),"female","","","","TB");
    CreateBooking(Station("Kolkata"),Station("Chennai"),Date(26,5,2021),current_date,BookingClass::FirstClass::Type(),"Divyaang",&p_badpass);

    Passenger p_baddivyaang("17r95z64z21g","7858814444",Date(1,1,2000),"female","Ishan","","","TA");
    CreateBooking(Station("Kolkata"),Station("Chennai"),Date(26,5,2021),current_date,BookingClass::FirstClass::Type(),"Divyaang",&p_baddivyaang);

    Passenger p_badcat("17r95z64z21g","7858814444",Date(1,1,2000),"female","Ishan","","");
    CreateBooking(Station("Kolkata"),Station("Chennai"),Date(26,5,2021),current_date,BookingClass::FirstClass::Type(),"CAt",&p_badcat);

    Passenger p_badstation("17r95z64z21g","7858814444",Date(1,1,2000),"female","Ishan","","","TB");
    CreateBooking(Station("Kolkata"),Station("Kolkata"),Date(26,5,2021),current_date,BookingClass::FirstClass::Type(),"Divyaang",&p_badstation);
}
