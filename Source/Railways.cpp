

#include "Railways.h"
#include<map>
using namespace std;

const Railways& Railways::Railway(){      //static method, used to return the only element of the class 
        static Railways obj;
        return obj;
    }  

vector<Station> Railways::sStations = {Station("Mumbai"),Station("Delhi"),Station("Bangalore"),Station("Kolkata"),Station("Chennai")};

map<pair<string,string>,double> GetMap(){   //Function to get map of distance between stations
    map<pair<string,string>,double> sdistanceMap_;

    sdistanceMap_[make_pair("Mumbai", "Kolkata")] = 2014;
    sdistanceMap_[make_pair("Kolkata", "Mumbai")] = 2014;

    sdistanceMap_[make_pair("Mumbai", "Delhi")] = 1447;
    sdistanceMap_[make_pair("Delhi", "Mumbai")] = 1447;

    sdistanceMap_[make_pair("Kolkata", "Chennai")] = 1659;
    sdistanceMap_[make_pair("Chennai", "Kolkata")] = 1659;

    sdistanceMap_[make_pair("Mumbai", "Bangalore")] = 981;
    sdistanceMap_[make_pair("Bangalore", "Mumbai")] = 981;

    sdistanceMap_[make_pair("Mumbai", "Chennai")] = 1338;
    sdistanceMap_[make_pair("Chennai", "Mumbai")] = 1338;

    sdistanceMap_[make_pair("Bangalore", "Kolkata")] = 1871;
    sdistanceMap_[make_pair("Kolkata", "Bangalore")] = 1871;

    sdistanceMap_[make_pair("Delhi", "Bangalore")] = 2150;
    sdistanceMap_[make_pair("Bangalore", "Delhi")] = 2150;

    sdistanceMap_[make_pair("Delhi", "Kolkata")] = 1472;
    sdistanceMap_[make_pair("Kolkata", "Delhi")] = 1472;

    sdistanceMap_[make_pair("Delhi", "Chennai")] = 2180;
    sdistanceMap_[make_pair("Chennai", "Delhi")] = 2180;

    sdistanceMap_[make_pair("Chennai", "Bangalore")] = 350;
    sdistanceMap_[make_pair("Bangalore", "Chennai")] = 350;

    return sdistanceMap_;
}

map<pair<string,string>,double> Railways::sdistanceMap_ = GetMap();

double Railways::GetDistance(const Station& s1, const Station& s2) const{
    return sdistanceMap_[make_pair(s1.GetName(),s2.GetName())];
}

ostream& operator<<(ostream &os, const Railways &r){
    os<<"Indian Railways"<<endl;
    os<<"List of all Stations"<<endl;

    for(auto i = r.sStations.begin(); i != r.sStations.end(); ++i)
        os<<i->GetName()<<endl;
    cout<<endl;

    cout<<"Distance between stations"<<endl;
    
    for(auto i = r.sdistanceMap_.begin(); i != r.sdistanceMap_.end(); ++i)
        cout<<i->first.first<<" -> "<<i->first.second<<" = "<<i->second<<endl;

    return os;
}
