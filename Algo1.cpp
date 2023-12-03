
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include "CarData.h"
#include <iostream>
using namespace std;

class Algo1{
public:

    void algo1(string inputs[]){
        CarData dataset;
        dataset.loadDatatoVector();

        int maxscore = 0;
        Car maxcar = dataset.cars[0];

        for (Car car : dataset.cars){

            int rankscore = 0;
    //Quantitative variables
            rankscore+= stoi(inputs[5]) *car.rankings["passengerSpace"];
            rankscore+= stoi(inputs[2]) * car.rankings["year"];
            rankscore+= stoi(inputs[6]) * car.rankings["storageSpace"];
            rankscore+= stoi(inputs[7]) * car.rankings["displacement"];
            rankscore += stoi(inputs[8])* car.rankings["fuelEconScore"];
            rankscore+= stoi(inputs[9]) * car.rankings["ghgScore"];
            rankscore+= stoi(inputs[10])*car.rankings["savings"];
            rankscore+=stoi(inputs[11]) *car.rankings["mpg"];

    //Qualitative variables
            if(inputs[3] == dataset.getFuel(&car))
                rankscore+=50;
            string drive_real = dataset.getDrive(&car);
            if(inputs[0] == drive_real)
                rankscore+=50;
            if(inputs[1]== dataset.getBuild(&car))
                rankscore+=100;
            if(inputs[4] == dataset.gettransnsmision(&car))
                rankscore+= 100;

            if(rankscore > maxscore){
                maxscore = rankscore;
                maxcar = car;
            }
        }
        cout<< "You should get a " <<maxcar.year <<" "<<maxcar.make<<" "<< maxcar.model<< " because it has the highest score of: "<<maxscore<<endl;

    }

};