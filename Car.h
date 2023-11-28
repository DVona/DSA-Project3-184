//
// Created by dvdot on 11/22/2023.
//
#ifndef DSAPROJ3_CAR_H
#define DSAPROJ3_CAR_H
#include <string>
#include <tuple>
using namespace std;
// Data URL:
// https://public.opendatasoft.com/explore/dataset/all-vehicles-model/api/?sort=modifiedon&dataChart=eyJxdWVyaWVzIjpbeyJjaGFydHMiOlt7InR5cGUiOiJjb2x1bW4iLCJmdW5jIjoiQVZHIiwieUF4aXMiOiJiYXJyZWxzMDgiLCJzY2llbnRpZmljRGlzcGxheSI6dHJ1ZSwiY29sb3IiOiJyYW5nZS1jdXN0b20ifV0sInhBeGlzIjoieWVhciIsIm1heHBvaW50cyI6IiIsInRpbWVzY2FsZSI6InllYXIiLCJzb3J0IjoiIiwic2VyaWVzQnJlYWtkb3duIjoiZnVlbHR5cGUiLCJjb25maWciOnsiZGF0YXNldCI6ImFsbC12ZWhpY2xlcy1tb2RlbCIsIm9wdGlvbnMiOnsic29ydCI6Im1vZGlmaWVkb24ifX19XSwiZGlzcGxheUxlZ2VuZCI6dHJ1ZSwiYWxpZ25Nb250aCI6dHJ1ZX0%3D
class Car{

public:
    Car() = default;
    Car(string make){this->make = make;
    };
    ~Car() = default;
    float getMPG(){
        return max(mpg1,mpg2);
    };
    string getFuelType(){
        if (!fuel2.empty()){
            return fuel1 + " and " + fuel2;
        }
        else{
            return fuel1;
        }
    };

    string make;
    string model;
    int year;
    string sizeClass; // size class of car. Set of options in CarData.h
    string baseModel; // base model of the car. Intended for the final display
    bool hybrid = false;
    bool electric = false;
    string drive; // car's Drive Line. Set of options in CarData.h
    int passengerSpace; // space for passengers (cubic feet) ~1/2 are NA and = 0
    int storageSpace; // space for luggage (cubic meters) ~1/2 are NA and = 0
    int cylinders; // a few are NA and = 0
    float displacement; // Car engine's displacement, a few are NA and = 0
    bool automatic;
    int gears;
    int fuelEconScore; // fuel Economy score from 1-10, with 10 being ideal. ~2/3 of observations are NA and = -1
    int ghgScore; // greenhouse gas score from 1-10, with 10 being ideal. ~2/3 of observations are NA and = -1
    int savings; // estimated amount saved/lost compared to the average vehicle over 5 years ($)
    string fuel1; // primary fuel type
    string fuel2; // secondary fuel type
    // Separate into gas vs electric?
    float mpg1; // mpg for primary fuel type
    float mpg2; // mpg for secondary fuel type or blended mpg for hybrid cars
};

#endif //DSAPROJ3_CAR_H
