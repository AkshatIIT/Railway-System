

#include "Station.h"
#include "Railways.h"

Station::Station(string name): name_(name) {}

Station::~Station() {}

string Station::GetName() const{
    return this->name_;
}

double Station::GetDistance(const Station& other) const{
    const Railways& tempRailways = Railways::Railway();
    return tempRailways.GetDistance(*this, other);
}

bool Station::operator==(const Station& s) const{
    return this->name_== s.name_;
}

ostream& operator<<(ostream& os, const Station& s){
    os<<s.GetName();
    return os;
}
