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

CarData::CarData() {
    ifstream file;
    file.open("quantileData.csv");
    string buffer;
    getline(file,buffer,'\n');
    for (int i = 0; i < 11; i++){
        getline(file,buffer,',');
        getline(file,buffer,',');
        yearQuantiles[i] = stoi(buffer);
        getline(file,buffer,',');
        passSpaceQuantiles[i] = stoi(buffer);
        getline(file,buffer,',');
        storSpaceQuantiles[i] = stoi(buffer);
        getline(file,buffer,',');
        displacementQuantiles[i] = stof(buffer);
        getline(file,buffer,',');
        mpgQuantiles[i] = stof(buffer);
        getline(file,buffer,',');
        econScoreQuantiles[i] = stoi(buffer);
        getline(file,buffer,',');
        ghgScoreQuantiles[i] = stoi(buffer);
        getline(file,buffer,'\n');
        savingsQuantiles[i] = stoi(buffer);
    }
}
string CarData::getFuel(Car *x) {
    if(x->hybrid ==true)
        return "2";
    if (x->electric == true)
        return "1";
    else
        return "0";
}
string CarData::getBuild(Car *x) {
    if (x->sizeClass == "Compact Car")
        return "0";
    if (x->sizeClass == "Sport Utility Vehicle")
        return "1";
    if (x->sizeClass == "Two Seaters")
        return "2";
    if (x->sizeClass == "Large Cars")
        return "3";
    if (x->sizeClass == "Truck")
        return "4";
    if (x->sizeClass == "Midsize Cars")
        return "5";
    if (x->sizeClass == "Van")
        return "6";
    if (x->sizeClass == "Special Purpose Vehicle")
        return "7";
    if (x->sizeClass == "Station Wagon")
        return "7";
    else{
        return "-1";
    }
}

string CarData::getDrive(Car *x) {
    if(x->drive== "Front-Wheel Drive")
        return "0";
    if(x->drive== "All-Wheel Drive")
        return "1";
    if(x->drive== "Rear-Wheel Drive")
        return "2";
    if(x->drive== "4-Wheel Drive")
        return "3";
    if(x->drive== "Part-time 4-Wheel Drive")
        return "4";
    if(x->drive== "4-Wheel or All-Wheel Drive")
        return "5";
    else{
        return "-1";
    }
}

string CarData::getTransmission(Car *x) {
    if (x->automatic){
        return "0";
    }
    else{
        return "1";
    }
}

vector<Car> CarData::getCar(){
    return cars;
}



void CarData::loadDatatoVector() {
    ifstream file("carsData.csv");
    string buffer;
    getline(file,buffer,'\n');
    while(cars.size() < 46771){
        cars.push_back(loadCar(&file));
    }
}

Car CarData::loadCar(ifstream* fileptr) {
    Car newCar;

    string buffer;
    getline(*fileptr,newCar.make,',');
    getline(*fileptr,newCar.model,',');
    getline(*fileptr,buffer,',');
    newCar.year = stoi(buffer);
    for (int i = 10; i > 0; i--){
        if (newCar.year > yearQuantiles[i-1]){
            newCar.rankings["year"] = i;
            break;
        }
    }
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
    if (newCar.passengerSpace == 0){
        newCar.rankings["passengerSpace"] = 4;
    }
    else{
        for (int i = 10; i > 0; i--){
            if (newCar.passengerSpace > passSpaceQuantiles[i-1]){
                newCar.rankings["passengerSpace"] = i;
                break;
            }
        }
    }
    getline(*fileptr,buffer,',');
    newCar.storageSpace = stoi(buffer);
    if (newCar.storageSpace == 0){
        newCar.rankings["storageSpace"] = 4;
    }
    else{
        for (int i = 10; i > 0; i--){
            if (newCar.storageSpace > storSpaceQuantiles[i-1]){
                newCar.rankings["storageSpace"] = i;
                break;
            }
        }
    }
    getline(*fileptr,buffer,',');
    newCar.hybrid = buffer == "Y";
    getline(*fileptr,buffer,',');
    newCar.cylinders = stoi(buffer);
    getline(*fileptr,buffer,',');
    newCar.displacement = stof(buffer);
    if (newCar.displacement == 0){
        newCar.rankings["displacement"] = 4;
    }
    else{
        for (int i = 10; i > 0; i--){
            if (newCar.displacement > displacementQuantiles[i-1]){
                newCar.rankings["displacement"] = i;
                break;
            }
        }
    }
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
    for (int i = 10; i > 0; i--){
        if (max(newCar.mpg1,newCar.mpg2) > mpgQuantiles[i-1]){
            newCar.rankings["mpg"] = i;
            break;
        }
    }
    getline(*fileptr,buffer,',');
    newCar.fuelEconScore = stoi(buffer);
    if (newCar.fuelEconScore == -1){
        newCar.rankings["fuelEconScore"] = 4;
    }
    else{
        for (int i = 10; i > 0; i--){
            if (newCar.fuelEconScore > econScoreQuantiles[i-1]){
                newCar.rankings["fuelEconScore"] = i;
                break;
            }
        }
    }
    getline(*fileptr,buffer,',');
    newCar.ghgScore = stoi(buffer);
    if (newCar.ghgScore == -1){
        newCar.rankings["ghgScore"] = 4;
    }
    else{
        for (int i = 10; i > 0; i--){
            if (newCar.ghgScore > ghgScoreQuantiles[i-1]){
                newCar.rankings["ghgScore"] = i;
                break;
            }
        }
    }
    getline(*fileptr,buffer,'\n');
    newCar.savings = stoi(buffer);
    for (int i = 10; i > 0; i--){
        if (newCar.savings > savingsQuantiles[i-1]){
            newCar.rankings["savings"] = i;
            break;
        }
    }
    return newCar;
}




