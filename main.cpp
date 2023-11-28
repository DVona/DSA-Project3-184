#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>

class CarTmp {
private:
    std::map<std::string, double> data;
    std::map<std::string, int> ranking;

public:
    CarTmp(const std::map<std::string, double>& newData) :
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

std::string findBestCar(const std::vector<CarTmp>& cars, const std::map<std::string, double>& userRankings, const std::map<std::string, double>& weights) {
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
            const_cast<CarTmp&>(cars[i]).setFactorRank(factor.first, factorRank);
        }

        // Calculate overall rank for the car
        int overallRank = cars[i].getOverallRank();

        if (overallRank > highestOverallRank) {
            highestOverallRank = overallRank;
            bestCar = "CarTmp " + std::to_string(i + 1);
        }
    }

    return bestCar;
}

int main() {
    std::map<std::string, double> userRankings;

    // Get user rankings
    for (const auto& factor : weights) {
        std::cout << "Rank the importance of " << factor.first << " (0 to 10): ";
        double ranking;
        std::cin >> ranking;
        userRankings[factor.first] = ranking;
    }

    // Predefined car data
    std::vector<CarTmp> cars = {
            { {{"mpg", 30}, {"year", 2011}, {"mileage", 15000}} },
            { {{"mpg", 25}, {"year", 2020}, {"mileage", 20000}} },
            // Add more cars as needed
    };

    // Find the best car based on the highest score
    std::string bestCar = findBestCar(cars, userRankings, weights);

    std::cout << "The best car to buy is: " << bestCar << std::endl;

    return 0;
}
/*
// Main function to test data import and runtime
#include "CarData.h"
int main(){
    time_t start, end;
    time(&start);
    CarData dataset;
    dataset.loadDatatoVector();
    time(&end);
    cout << end - start << endl;
    start = end;
    for (Car car : dataset.cars){
        for (pair<string,int> ranking : car.rankings){
            cout << ranking.first << " " << ranking.second << " ";
        }
        cout << endl;
    }
    time(&end);
    cout << end - start << endl;
    return 0;
}
*/