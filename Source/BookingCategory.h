

#ifndef BOOKINGCATEGORY_H
#define BOOKINGCATEGORY_H

#include <iostream>
#include "Passenger.h"
#include "BookingClasses.h"

using namespace std;

//Abstract Base Class
class BookingCategory{

protected: 

    // virtual bool IsEligible(const Passenger& passenger, const BookingClass& bookingClass);
    
    // default ctor
    BookingCategory();

    //virtual dtor
    virtual ~BookingCategory();

public: 

    //overloaded ostream
    friend ostream& operator<<(ostream& os, const BookingCategory& b);

    //For unit testing of BookingCategory Class 
    static void UnitTest();
};


#endif
