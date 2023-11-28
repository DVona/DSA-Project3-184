//
// Created by dvdot on 11/27/2023.
//

#ifndef DSAPROJ3_CARDATA_H
#define DSAPROJ3_CARDATA_H
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include "Car.h"
using namespace std;

class CarData {
public:
    CarData();
    ~CarData();
    vector<Car> cars;
private:
    void loadDatatoVector();
    Car loadCar(ifstream* fileptr, string make);
    void loadStats(ifstream* fileptr);

    set<string> sizeClasses{"Compact Car","Sport Utility Vehicle","Two Seaters","Large Cars","Truck","Midsize Cars",
                            "Van","Special Purpose Vehicle","Station Wagon","NA"};
    set<string> driveLines{"Front-Wheel Drive","All-Wheel Drive","Rear-Wheel Drive","4-Wheel Drive",
                           "Part-time 4-Wheel Drive","4-Wheel or All-Wheel Drive","NA"};
};

#endif //DSAPROJ3_CARDATA_H
