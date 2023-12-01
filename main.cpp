#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
/*
class Car {
private:
    std::map<std::string, double> data;
    std::map<std::string, int> ranking;

public:
    Car(const std::map<std::string, double>& newData) :
    data(newData) {}

    const std::map<std::string, double>& getData() const {
        return data;
    }

    double getFactorValue(const std::string& factor) const {
        auto it = data.find(factor);
        return (it != data.end()) ? it->second : 0.0;
    }

    // Setter function to set ranking for a factor
    void setFactorRank(const std::string& factor, int rank) {
        ranking[factor] = rank;
    }

    // Getter function to get the ranking for a factor
    int getFactorRank(const std::string& factor) const {
        auto it = ranking.find(factor);
        return (it != ranking.end()) ? it->second : 0;
    }

    // Getter function to get the overall rank for the car
    int getOverallRank() const {
        int overallRank = 0;
        for (const auto& factor : ranking) {
            overallRank += factor.second;
        }
        return overallRank;
    }
};

// Define weights for each factor
std::map<std::string, double> weights = {
        {"mpg", 0.33},
        {"year", 0.33},
        {"mileage", 0.33}
};

double calculateScore(const std::map<std::string, double>& userRankings, const std::map<std::string, double>& weights) {
    double totalScore = 0;
    for (const auto& factor : userRankings) {
        if (weights.find(factor.first) != weights.end()) {
            totalScore += weights.at(factor.first) * factor.second;
        }
    }
    return totalScore;
}

std::string findBestCar(const std::vector<Car>& cars, const std::map<std::string, double>& userRankings, const std::map<std::string, double>& weights) {
    int highestOverallRank = -1;
    std::string bestCar;

    for (size_t i = 0; i < cars.size(); ++i) {
        // Set ranking for each factor
        for (const auto& factor : weights) {
            double factorValue = cars[i].getFactorValue(factor.first);
            int factorRank = 1;

            // Compare with other cars to determine rank
            for (size_t j = 0; j < cars.size(); ++j) {
                if (i != j) {
                    if (factorValue > cars[j].getFactorValue(factor.first)) {
                        factorRank++;
                    }
                }
            }

            // Set factor rank for the car
            const_cast<Car&>(cars[i]).setFactorRank(factor.first, factorRank);
        }

        // Calculate overall rank for the car
        int overallRank = cars[i].getOverallRank();

        if (overallRank > highestOverallRank) {
            highestOverallRank = overallRank;
            bestCar = "Car " + std::to_string(i + 1);
        }
    }

    return bestCar;
}

int smain() {
    std::map<std::string, double> userRankings;

    // Get user rankings
    for (const auto& factor : weights) {
        std::cout << "Rank the importance of " << factor.first << " (0 to 10): ";
        double ranking;
        std::cin >> ranking;
        userRankings[factor.first] = ranking;
    }

    // Predefined car data
    std::vector<Car> cars = {
            { {{"mpg", 30}, {"year", 2011}, {"mileage", 15000}} },
            { {{"mpg", 25}, {"year", 2020}, {"mileage", 20000}} },
            // Add more cars as needed
    };

    // Find the best car based on the highest score
    std::string bestCar = findBestCar(cars, userRankings, weights);

    std::cout << "The best car to buy is: " << bestCar << std::endl;

    return 0;
}
*/
// Main function to test data import and runtime
#include "CarData.h"
int main(){
    /*time_t start, end;
    time(&start);

    time(&end);
    cout << end - start << endl;
    start = end;*/
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



    return 0;
}
