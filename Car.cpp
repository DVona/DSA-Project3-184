//
// Created by dvdot on 11/22/2023.
//
#ifndef DSAPROJ3_CAR_CPP
#define DSAPROJ3_CAR_CPP
#include <string>
#include <tuple>
#include <map>
#include "CarTree.h"

using namespace std;
// Data URL:
// https://public.opendatasoft.com/explore/dataset/all-vehicles-model/api/?sort=modifiedon&dataChart=eyJxdWVyaWVzIjpbeyJjaGFydHMiOlt7InR5cGUiOiJjb2x1bW4iLCJmdW5jIjoiQVZHIiwieUF4aXMiOiJiYXJyZWxzMDgiLCJzY2llbnRpZmljRGlzcGxheSI6dHJ1ZSwiY29sb3IiOiJyYW5nZS1jdXN0b20ifV0sInhBeGlzIjoieWVhciIsIm1heHBvaW50cyI6IiIsInRpbWVzY2FsZSI6InllYXIiLCJzb3J0IjoiIiwic2VyaWVzQnJlYWtkb3duIjoiZnVlbHR5cGUiLCJjb25maWciOnsiZGF0YXNldCI6ImFsbC12ZWhpY2xlcy1tb2RlbCIsIm9wdGlvbnMiOnsic29ydCI6Im1vZGlmaWVkb24ifX19XSwiZGlzcGxheUxlZ2VuZCI6dHJ1ZSwiYWxpZ25Nb250aCI6dHJ1ZX0%3D
class Car{

public:
    Car() = default;
    template <class Car2t>
    void convertC2(Car2t car2);

//Car(string make){this->make = make;
    //};
    ~Car() = default;
    float getMPG(){
        return max(mpg1,mpg2);
    };
    string getFuelType(){
        if (fuel2 != "NA"){
            return fuel1 + " and " + fuel2;
        }
        else{
            return fuel1;
        }
    };

/* Takes the following input:
* { Make, Model, DriveTrain, Class, Year, Type, Transmission, PSpace, SSpace,
* displacment, fuelecon, ghg, savings, mpg1, mpg2, fuel1, fuel2 }
*/
void getStringArr(vector<string>& vec) {
    string temp[17] = {this->make, model, drive, sizeClass, to_string(year), hybrid?"Hybrid":electric?"Electric":"Gas",
                    automatic?"Automatic":"Manual", to_string(passengerSpace),to_string(storageSpace),to_string(displacement),
                    to_string(fuelEconScore), to_string(ghgScore),to_string(savings),to_string(mpg1),to_string(mpg2),
                    fuel1, fuel2};
    int i = 0;
    for (string item : temp){
        vec.at(i) = item;
        i++;
    }
};



// Display variables, not used for search
string make;
string model;
string baseModel; // base model of the car. Intended for the final display
int cylinders; // a few are NA and = 0
int gears;

// Qualitative variables for search
string sizeClass; // size class of car. Set of options in CarData.h
bool hybrid = false;
bool electric = false;
string drive; // car's Drive Line. Set of options in CarData.h
bool automatic;
string fuel1; // primary fuel type. Set of options in CarData.h
string fuel2; // secondary fuel type

// Quantitative variables to be ranked for search
map<string,int> rankings; // Which quantile each of this car's quantifiable variables rank in.
// keys are identical to each variable name, ie rankings["passengerSpace"]  ;  or from a CarData object indexed like dataObject.cars[carIndex].rankings["year"]
// mpg rank is indexed by ["mpg"]
int year; // 40 year range 1984-2024
int passengerSpace; // space for passengers (cubic feet) ~1/2 are NA and = 0
int storageSpace; // space for luggage (cubic meters) ~1/2 are NA and = 0
float displacement; // Car engine's displacement, a few are NA and = 0
int fuelEconScore; // fuel Economy score from 1-10, with 10 being ideal. ~2/3 of observations are NA and = -1
int ghgScore; // greenhouse gas score from 1-10, with 10 being ideal. ~2/3 of observations are NA and = -1
int savings; // estimated amount saved/lost compared to the average vehicle over 5 years ($)

float mpg1; // mpg for primary fuel type
float mpg2 = 0; // mpg for secondary fuel type or blended mpg for hybrid cars
};
template <class Car2t>
void Car::convertC2(Car2t car2) {
make = car2.name;
model = "";
drive = car2.driveTrain;
sizeClass= car2.Class;
year = stoi(car2.year);
automatic = car2.trans == "Automatic";
passengerSpace = stoi(car2.pSpace);
storageSpace = stoi(car2.sSpace);
displacement = stof(car2.engDisp);
fuelEconScore = stoi(car2.fuelEcon);
ghgScore = stoi(car2.ghg);
savings = stoi(car2.savings);
mpg1 = stof(car2.mpg1);
mpg2 = stof(car2.mpg2);
fuel1 = car2.fuel1;
fuel2 = car2.fuel2;
}

#endif //DSAPROJ3_CAR_CPP
