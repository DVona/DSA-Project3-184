
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include "CarData.h"
#include <iostream>
using namespace std;

class Algo1{
public:
    void algo1(){
        CarData dataset;
        dataset.loadDatatoVector();

        cout<<"Gas, Hybrid, or electric - 0 for gas, 1 for electric, 2 for hybrid "<<endl;
        string ghe;
        cin >>ghe;
        cout<<"What type of drive is wanted:"<<endl;
        cout<<"0: Front-Wheel Drive"<<endl;
        cout<<"1: All-Wheel Drive"<<endl;
        cout<<"2: Rear-Wheel Drive"<<endl;
        cout<<"3: 4-Wheel Drive"<<endl;
        cout<<"4: Part-time 4-Wheel Drive "<<endl;
        cout<<"5: 4-Wheel or All-Wheel Drive"<<endl;
        string drive;
        cin >>drive;
        cout<<"How important is passenger space to you on a scale of 1-10"<<endl;
        string passenger;
        cin >>passenger;
        int pass_space_input = stoi((passenger));
        cout<<"How important is the year the car was built to you on a scale of 1-10"<<endl;
        string year_made;
        cin>>year_made;
        int year = stoi(year_made);
        cout<<"How important is the storage space to you on a scale of 1-10"<<endl;
        string storag;
        cin>>storag;
        int storage = stoi(storag);
        cout<<"How important is displacement to you on a scale of 1-10"<<endl;
        string dis;
        cin>>dis;
        int displacement = stoi(dis);
        cout<<"How important is fuel economy to you on a scale of 1-10"<<endl;
        string fuele;
        cin >>fuele;
        int fuelecon = stoi(fuele);
        cout<<"How important is ghg(Greenhouse gas)  to you on a scale of 1-10"<<endl;
        string ghg;
        cin>>ghg;
        int ghgscore = stoi (ghg);
        cout<<"How important is savings after 5 years to you on a scale of 1-10"<<endl;
        string sav;
        cin >>sav;
        int savings = stoi (sav);
        cout<<"How important is the mpg to you on a scale of 1-10"<<endl;
        string mpg;
        cin>>mpg;
        int mpgs = stoi(mpg);
        int maxscore = 0;
        Car maxcar = dataset.cars[0];





        for (Car car : dataset.cars){

            int rankscore = 0;

            rankscore+= pass_space_input *car.rankings["passengerSpace"];
            rankscore+= year * car.rankings["year"];
            rankscore+= storage * car.rankings["storageSpace"];
            rankscore+= displacement * car.rankings["displacement"];
            rankscore += fuelecon* car.rankings["fuelEconScore"];
            rankscore+= ghgscore * car.rankings["ghgScore"];
            rankscore+= savings*car.rankings["savings"];
            rankscore+=mpgs *car.rankings["mpg"];


            string ghe_real = dataset.getFuel(&car);
            if(ghe == ghe_real)
                rankscore+=50;
            string drive_real = dataset.getDrive(&car);
            if(drive== drive_real)
                rankscore+=50;
            //cout<<car.rankings["ghgScore"];

            if(rankscore > maxscore){
                maxscore = rankscore;
                maxcar = car;
            }
        }
        cout<< "You should get a " <<maxcar.year <<" "<<maxcar.make<<" "<< maxcar.model<< " because it has the highest score of: "<<maxscore<<endl;

    }

};