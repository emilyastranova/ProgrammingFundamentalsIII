#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

#include "cityType.h"
#include "CSVRow.h"

std::istream& operator>>(std::istream& str, CSVRow& data) {
    data.readNextRow(str);
    return str;
}
int main() {
    
    std::ifstream file("500Cities.csv");
    std::map<std::string, cityType> cityMap;
    cityType tempCity;
    std::map<std::string, cityType>::iterator it = cityMap.begin();
    std::cout << file.fail() << std::endl;

    CSVRow row;
    while (file >> row) {
        // std::cout << "stateid: " << row[0] << std::endl;
        tempCity.setStateID(row[0]);
        // std::cout << "placename: " << row[1] << std::endl;
        tempCity.setPlaceName(row[1]);
        // std::cout << "fips: " << row[2] << std::endl;
        tempCity.setPlaceFIPS(row[2]);
        // std::cout << "population: " << row[3] << std::endl;
        tempCity.setPopulation(stoi(row[3]));
        tempCity.setGeolocation(row[4].append(",").append(row[5]));
        cityMap.insert(std::pair<std::string, cityType>(tempCity.getPlaceFIPS(), tempCity));
    }

    string lookupFIPS;
    std::cout << "Search for city by FIPS: ";
    std::cin >> lookupFIPS;

    bool found = false;
    for (it = cityMap.begin(); it != cityMap.end(); ++it) {
        if(it->first == lookupFIPS)
        {
            std::cout << "\nCity Found\nName: " << it->second.getName() << "\nState ID: " << it->second.getID() << 
            "\nPopulation: " << it->second.getPopulation() << "\nGeolocation: " << it->second.getGeolocation() << std::endl << std::endl;
            found = true;
        }
    }
    if(!found)
        std::cout << "\nCity Not Found" << std::endl;
}