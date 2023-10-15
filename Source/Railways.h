

#ifndef RAILWAYS_H
#define RAILWAYS_H

#include<iostream>
#include<vector>
#include<map>
#include "Station.h"
using namespace std;

//Singleton Class
class Railways{
    string name_;   //a string for storing the name of Railways
    static vector<Station> sStations;   //a static list (vector) of Stations (known a priori)
    static map<pair<string,string>, double> sdistanceMap_;  //a map (Hash Map) to store the distance between any pair of stations 

    Railways(){name_ = "IndianRailways";}
    ~Railways(){}

public:
    static const Railways& Railway();  
    
    friend ostream &operator<<(ostream &os, const Railways &r); //Overloaded operator to print the Railways name (ie Indian Railways), the list of Stations, and the distance between every pair of Stations 
    double GetDistance(const Station& s1, const Station& s2)const;  //returns the prior known distance between the two stations 
    static void UnitTest(); //For unit testing of Railways Class
};
#endif
