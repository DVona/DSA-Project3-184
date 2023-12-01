//
// Created by dvdot on 11/27/2023.
//

#ifndef DSAPROJ3_CARDATA_H
#define DSAPROJ3_CARDATA_H
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include "Car.cpp"
using namespace std;

class CarData {

public:
    Car newCar;
    CarData();
    ~CarData()=default;
    vector<Car> cars;
    void loadDatatoVector();
    Car loadCar(ifstream* fileptr);

    string getFuel(Car *x);
    string getDrive(Car *x);
    vector<Car> getCar();
    int getPassengerSpaceScore();
    int getYearScore();


    set<string> sizeClasses{"Compact Car","Sport Utility Vehicle","Two Seaters","Large Cars","Truck","Midsize Cars",
                            "Van","Special Purpose Vehicle","Station Wagon","NA"};
    set<string> driveLines{"Front-Wheel Drive","All-Wheel Drive","Rear-Wheel Drive","4-Wheel Drive",
                           "Part-time 4-Wheel Drive","4-Wheel or All-Wheel Drive","NA"};
    set<string> fuelTypes{"Premium Gasoline", "Regular Gasoline", "Midgrade Gasoline", "Diesel", "Electricity",
                          "Natural Gas", "E85", "Propane", "NA"}; // "E85", "Propane", and "NA" are only in fuel2
private:
    int yearQuantiles[11];
    int passSpaceQuantiles[11];
    int storSpaceQuantiles[11];
    float displacementQuantiles[11];
    float mpgQuantiles[11];
    int econScoreQuantiles[11];
    int ghgScoreQuantiles[11];
    int savingsQuantiles[11];
};

#endif //DSAPROJ3_CARDATA_H
