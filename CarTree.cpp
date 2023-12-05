#ifndef DSAPROJ3_CARTREE_CPP
#define DSAPROJ3_CARTREE_CPP
#include "CarTree.h"
void CarTree::createTree() {
    string info[15] = {"driveTrain","class","year","type"/*gas,elec,hybrid*/,"transmission","passengerSpace","storageSpace","engnDisplacement"/*CCs*/,"fuelEcon","ghg","savings","mpg1","mpg2","fuel1","fuel2"};
    for(int i=0; i<15; i++) {
        Node *temp = new Node(false, {nullptr}, info[i]);
        roots[i] = temp;
        switch (i) { // need to convert quantiles
            case 0: {
                string info2[] = {"Front-Wheel Drive", "All-Wheel Drive", "Rear-Wheel Drive", "4-Wheel Drive",
                                  "Part-time 4-Wheel Drive", "4-Wheel or All-Wheel Drive", "NA"}; // driveTrain
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 1: {
                string info2[] = {"Compact Car","Sport Utility Vehicle","Two Seaters","Large Cars","Truck","Midsize Cars",
                                  "Van","Special Purpose Vehicle","Station Wagon","NA"}; // class
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 2: {
                string info2[] = {"1984","1986","1990","1995","2000","2005","2009","2013","2017","2020","2024","NA"}; // year
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 3: {
                string info2[] = {"Gas","Electric","Hybrid","NA"}; // type
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 4: {
                string info2[] = {"Automatic","Manual","NA"}; // transmission
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 5: {
                string info2[] = {"1","78","84","87","90","92","94","97","100","104","195","NA"}; // Passenger Space
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 6: {
                string info2[] = {"1","9","11","12","13","14","15","16","19","27","55","NA"}; // Storage space
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 7: {
                string info2[] = {"0.6","1.8","2","2.3","2.5","3","3.5","3.8","4.6","5.3","8.4","NA"}; // engnDisplacement
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 8: {
                string info2[] = {"1","3","4","4","4","5","5","6","7","8","10","NA"}; // fuelEcon
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 9: {
                string info2[] = {"1","3","4","4","4","5","5","6","7","8","10","NA"}; // ghg
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 10: {
                string info2[] = {"-40750","-12000","-9000","-7750","-6500","-5250","-4000","-3250","-2000","-250","8000","NA"}; // savings
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 11: {
                string info2[] = {"NA","15.2827","17.3254","18.9908","20.498","21.847","23.3291","25.0797","27.333","31","133.2662"}; // mpg1
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 12: {
                string info2[] = {"NA","15.2827","17.3254","18.9908","20.498","21.847","23.3291","25.0797","27.333","31","133.2662"}; // mpg2
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 13: {
                string info2[] = {"Premium Gasoline", "Regular Gasoline", "Midgrade Gasoline", "Diesel", "Electricity",
                                  "Natural Gas", "E85", "Propane", "NA"}; // fuel1
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
            case 14: {
                string info2[] = {"Premium Gasoline", "Regular Gasoline", "Midgrade Gasoline", "Diesel", "Electricity",
                                  "Natural Gas", "E85", "Propane", "NA"}; // fuel2
                for (int j = 0; j < size(info2); j++) {
                    Node *temp2 = new Node(false, {roots[0]}, info2[j]);
                    roots[i]->childs.push_back(temp2);
                }
                break;
            }
        }
    }
}
/* Takes the following input:
 * { Make, Model, DriveTrain, Class, Year, Type, Transmission, PSpace, SSpace,
 * displacment, fuelecon, ghg, savings, mpg1, mpg2, fuel1, fuel2 }
 * */
void CarTree::insert(vector<string>& carstr) {
    Car2 d = Car2(carstr);
    string Sparents[] = {d.driveTrain,d.Class,d.year,d.type,d.trans,d.pSpace,d.sSpace,d.engDisp,d.fuelEcon,d.ghg,d.savings,d.mpg1,d.mpg2,d.fuel1,d.fuel2};
    vector<Node*> temps;
    for (int i=0; i<15;i++)  {
        Node* t = new Node(false, {nullptr}, "");
        for(auto c:roots[i]->childs) {
            if(c->key==Sparents[i]) {
                t=c;
            }
        }
        temps.push_back(t);
    }
    Node* temp = new Node(true, temps, d.name);
    temp->data = d;
    for (auto p:temps) {
        p->childs.push_back(temp);
    }
}

/* Takes the following input:
 * { DriveTrain, Class, Year, Type, Transmission, PSpace, SSpace,
 * displacment, fuelecon, ghg, savings, mpg1, mpg2, fuel1, fuel2 }
 * */
vector<CarTree::Car2> CarTree::findCar(string params[]) {
    vector<Car2> idealCars;
    vector<Car2> tempCars;
    for(int i=0; i<15; i++) {
        if(params[i] != "NA") {
            if (idealCars.empty()) {
                for (auto key: roots[i]->childs) {
                    if (key->key == params[i]) {
                        for (auto leaf: key->childs) {
                            idealCars.push_back(leaf->data);
                        }
                    }
                }
                tempCars = idealCars;
            }
            else {
                for (int j = 0; j < idealCars.size(); j++) {
                    switch (i) {
                        case 0: {
                            if (idealCars.at(j).driveTrain != params[i] && idealCars.at(j).driveTrain != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 1: {
                            if (idealCars.at(j).Class != params[i] && idealCars.at(j).Class != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 2: {
                            if (idealCars.at(j).year != params[i] && idealCars.at(j).year != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 3: {
                            if (idealCars.at(j).type != params[i] && idealCars.at(j).type != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 4: {
                            if (idealCars.at(j).trans != params[i] && idealCars.at(j).trans != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 5: {
                            if (idealCars.at(j).pSpace != params[i] && idealCars.at(j).pSpace != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 6: {
                            if (idealCars.at(j).sSpace != params[i] && idealCars.at(j).sSpace != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 7: {
                            if (idealCars.at(j).engDisp != params[i] && idealCars.at(j).engDisp != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 8: {
                            if (idealCars.at(j).fuelEcon != params[i] && idealCars.at(j).fuelEcon != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 9: {
                            if (idealCars.at(j).ghg != params[i] && idealCars.at(j).ghg != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 10: {
                            if (idealCars.at(j).savings != params[i] && idealCars.at(j).savings != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 11: {
                            if (idealCars.at(j).mpg1 != params[i] && idealCars.at(j).mpg1 != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 12: {
                            if (idealCars.at(j).mpg2 != params[i] && idealCars.at(j).mpg2 != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 13: {
                            if (idealCars.at(j).fuel1 != params[i] && idealCars.at(j).fuel1 != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                        case 14: {
                            if (idealCars.at(j).fuel2 != params[i] && idealCars.at(j).fuel2 != "NA") {
                                idealCars.erase(idealCars.begin() + j);
                            }
                            break;
                        }
                    }
                }
            }
            if (idealCars.empty()) {
                break;
            }
        }
    }
    
    return idealCars;
}
~CarTree() {
    for(auto root:roots) {
        for(auto child:root.childs) {
            for(auto car:child.childs) {
                delete car;
            }
            delete child;
        }
        delete root;
    }
}
#endif
