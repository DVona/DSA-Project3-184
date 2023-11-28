//
// Created by dvdot on 11/27/2023.
//

#include "CarData.h"

int findInt(string buffer){
    int num = 0;
    for (char c : buffer){
        if (isdigit(c)){
            num = num*10 + c - '0';
        }
    }
    return num;
}

void CarData::loadDatatoVector() {
    ifstream file("carsData.csv");
    string makeBuff;
    getline(file,makeBuff,'\n');
    getline(file,makeBuff,',');
    while(makeBuff != "MINVAL"){
        cars.push_back(loadCar(&file,makeBuff));
        getline(file,makeBuff,',');
    }
    loadStats(&file);

}

Car CarData::loadCar(ifstream* fileptr,string make) {
    Car newCar(std::move(make));
    string buffer;
    getline(*fileptr,newCar.model,',');
    getline(*fileptr,buffer,',');
    newCar.year = stoi(buffer);
    getline(*fileptr,newCar.sizeClass,',');
    getline(*fileptr,newCar.baseModel,',');
    getline(*fileptr,buffer,',');
    newCar.hybrid = buffer == "true";
    getline(*fileptr,newCar.fuel1,',');
    newCar.electric = newCar.fuel1 == "Electricity";
    getline(*fileptr,newCar.fuel2,',');
    if (!newCar.hybrid){
        newCar.hybrid = newCar.fuel2 == "Electricity";
    }
    getline(*fileptr,newCar.drive,',');
    getline(*fileptr,buffer,',');
    newCar.passengerSpace = stoi(buffer);
    getline(*fileptr,buffer,',');
    newCar.storageSpace = stoi(buffer);
    getline(*fileptr,buffer,',');
    newCar.hybrid = buffer == "Y";
    getline(*fileptr,buffer,',');
    newCar.cylinders = stoi(buffer);
    getline(*fileptr,buffer,',');
    newCar.displacement = stof(buffer);
    getline(*fileptr,buffer,' ');
    newCar.automatic = buffer == "Automatic";
    getline(*fileptr,buffer,',');
    newCar.gears = findInt(buffer);
    getline(*fileptr,buffer,',');
    newCar.mpg1 = stof(buffer);
    getline(*fileptr,buffer,',');
    newCar.mpg2 = stof(buffer);
    getline(*fileptr,buffer,',');
    if (stof(buffer) > 1){
        newCar.mpg2 = stof(buffer);
    }
    getline(*fileptr,buffer,',');
    newCar.fuelEconScore = stoi(buffer);
    getline(*fileptr,buffer,',');
    newCar.ghgScore = stoi(buffer);
    getline(*fileptr,buffer,'\n');
    newCar.savings = stoi(buffer);
    return newCar;
}

void CarData::loadStats(ifstream *fileptr) {
    //wip
}
