

#ifndef BOOKINGCLASS_H
#define BOOKINGCLASS_H

#include <iostream>
using namespace std;

// Forward declaration of templatized class
template<typename T>
class BookingClassTypes;

//Abstract Base Class
class BookingClass{

private:

    const string& name_;  //Name of the booking class
    struct ACChairCarType {};
    struct SecondSittingType {};
    struct ACFirstClassType {};
    struct AC2TierType {};
    struct AC3TierType {};
    struct FirstClassType {};
    struct SleeperType {};
    struct ExecutiveChairCarType {};
    
protected:
    
    bool sitting_; //sitting_ = false means berth available
    bool AC_; //AC_ = false means Non-AC
    int numOfTiers_;
    double fareLoadFactor_;
    bool luxury_; //luxury_ = false means Ordinary
    double reservationCharge_;
    double tatkalLoadFactor_;
    double minTatkalCharge_;
    double maxTatkalCharge_;
    double minTatkalDistance_;

    //default ctor
    BookingClass(const string& name);

    //virtual dtor
    virtual ~BookingClass();

public:
    //returns name of Booking Class
    const string& GetName() const;

    //pure virtual method to return load factors
    virtual double GetLoadFactor() const = 0;

    //function to change the fare load factors
    void SetLoadFactor(const double& lf);

    //returns boolean true when the booking class has Seats (not Berths) 
    bool IsSitting() const ;
    
    //returns boolean true when the booking class has AC 
    bool IsAC() const ;
    
    //returns the number of tiers in the booking class
    int GetNumberOfTiers() const ;

    //returns the reservation charge in the booking class
    double GetReservationCharge() const ;

    // //returns the concession factor in the booking class
    // double GetConcessionFactor() const ;
    
    //returns boolean true when the booking class is luxurious 
    bool IsLuxury() const ;

    //to change the luxury status of the booking class 
    void SetLuxury(const bool& l);

    //to change the tatkal load factor of the booking class 
    void SetTatkalLoadFactor(const double& tlf);
    
    //to change the min tatkal charge of the booking class 
    void SetMinTatkalCharge(const double& mtc);

    //to change the min tatkal distance of the booking class 
    void SetMinTatkalDistance(const double& mtd);

    //to return the tatkal load factor of the booking class 
    double GetTatkalLoadFactor() const;
    
    //to return the min tatkal charge of the booking class 
    double GetMinTatkalCharge() const;

   //to return the max tatkal charge of the booking class 
    double GetMaxTatkalCharge() const;

    //to return the min tatkal distance of the booking class 
    double GetMinTatkalDistance() const;

    //Overloaded operator to print the name, seat/berth, comfort, #tiers and luxury status of the Booking class 
    friend ostream& operator<<(ostream& os, const BookingClass& b);

    typedef BookingClassTypes<ACChairCarType> ACChairCar;
    typedef BookingClassTypes<SecondSittingType> SecondSitting;
    typedef BookingClassTypes<ACFirstClassType> ACFirstClass;
    typedef BookingClassTypes<AC2TierType> AC2Tier;
    typedef BookingClassTypes<AC3TierType> AC3Tier;
    typedef BookingClassTypes<FirstClassType> FirstClass;
    typedef BookingClassTypes<SleeperType> Sleeper;
    typedef BookingClassTypes<ExecutiveChairCarType> ExecutiveChairCar;

    //For unit testing of BookingClass Class 
    static void UnitTest();
};

template<typename T>
class BookingClassTypes: public BookingClass{

private:

    static const string sName;
    
    BookingClassTypes(const string& name = BookingClassTypes<T>::sName): BookingClass(name){
        setParameters();
    }
    
    //default dtor
    ~BookingClassTypes(){};

    void setParameters();

public:

    static BookingClassTypes<T>& Type() {
        static BookingClassTypes<T> theObject; 
        return theObject;
    }

    inline double GetLoadFactor() const{
        return this->fareLoadFactor_;
    }

};

#endif
