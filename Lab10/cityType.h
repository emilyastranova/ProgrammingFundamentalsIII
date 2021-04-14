#ifndef H_CityType
#define H_CityType

#include <iostream>
#include <string>

using namespace std;

class cityType {

   public:
    void setStateID(string sid);
    void setPlaceName(string pname);
    void setPlaceFIPS(string fips);
    void setPopulation(int pop);
    void setGeolocation(string geo);

    string getID();
    string getName();
    string getPlaceFIPS();
    int getPopulation();
    string getGeolocation();

    bool operator!=(const cityType&) const;
    bool operator==(const cityType&) const;

   private:
    string id;
    string name;
    string placeFIPS;
    int population;
    string geolocation;
};

#endif