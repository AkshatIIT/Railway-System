

#ifndef EXCEPTIONS_H
#define EXCEPIONS_H
#include<iostream>
#include<exception>
using namespace std;


class Exceptions : public exception {
public:
    virtual const char* what() const noexcept;
};
inline char const * Exceptions::what() const noexcept{ return "Unknown Error"; }

class Bad_Date : public Exceptions{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_Date::what() const noexcept{ return "Bad Date"; }

class Bad_Passenger : public Exceptions{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_Passenger::what() const noexcept{ return "Bad Passenger"; }

class Bad_Aadhar : public Bad_Passenger{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_Aadhar::what() const noexcept{ return "Invalid Aadhar"; }

class Bad_Mobile : public Bad_Passenger{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_Mobile::what() const noexcept{ return "Invalid Mobile"; }

class Bad_Name : public Bad_Passenger{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_Name::what() const noexcept{ return "Invalid Name"; }

class Bad_Booking : public Exceptions{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_Booking::what() const noexcept{ return "Bad Booking"; }

class Bad_BookingDate : public Bad_Booking{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_BookingDate::what() const noexcept{ return "Bad Booking Date"; }

class Bad_SeniorCitizen : public Bad_Booking{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_SeniorCitizen::what() const noexcept{ return "Senior citizen Error"; }

class Bad_Divyaang : public Bad_Booking{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_Divyaang::what() const noexcept{ return "Divyaang Error"; }

class Bad_Category : public Bad_Booking{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_Category::what() const noexcept{ return "Category Error"; }

class Bad_Railways : public Exceptions{
public:
    virtual const char* what() const noexcept;
};
inline char const * Bad_Railways::what() const noexcept{ return "Same Station Invalid"; }
#endif
