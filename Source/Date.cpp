

#include "Date.h"
#include "Exceptions.h"

Date::Date(unsigned int d , unsigned int m , unsigned int y ) : date_(d), month_(m), year_(y) {
    ValidDate();
}

Date::~Date() {}

int Date::getDay(){ return this->date_; }
int Date::getMonth(){ return this->month_; }
int Date::getYear(){ return this->year_; }
        
void Date::ValidDate(){		//checks whether the constructed date is valid or not 
    try{
        if(this->year_ >= 1900 && this->year_ <= 2099){
            if(this->month_<=12 && this->month_>=1){
                if(this->month_==1 || this->month_==3 || this->month_==5 || this->month_==7 || this->month_==8 || this->month_==10 || this->month_==12){
                    if(!(this->date_>=1 && this->date_<=31)) throw Bad_Date{};
                }
                else{
                    if(this->month_!=2){
                        if(!(this->date_>=1 && this->date_<=30)) throw Bad_Date{};
                    }
                    else if(this->year_%4==0){
                        if(!(this->date_>=1 && this->date_<=29)) throw Bad_Date{};
                    }
                    else if(!(this->date_>=1 && this->date_<=28)) throw Bad_Date{};
                }
            }
            else throw Bad_Date{};
        }
        else throw Bad_Date{};
    }
    catch(Bad_Date& e){
        cout << e.what() <<endl;
    }
}

float Date::ComputeAge(const Date& other){
	int days = 0;

    days += (other.year_ - this->year_)*365;
    days += (other.month_ - this->month_)*31;
    days += (other.date_ - this->date_);
    return days*1.0/365;
}

ostream& operator<<(ostream& os, const Date& d){
    os<< d.date_ << "/" << d.month_ << "/" << d.year_;
    return os;
}

