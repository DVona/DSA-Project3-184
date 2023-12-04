//
// Created by dvdot on 12/3/2023.
//

#ifndef DSAPROJ3_CARTREE_H
#define DSAPROJ3_CARTREE_H
#include <iostream>
#include <vector>
#include "Car.cpp"

using namespace std;

/* TODO:
 *  1. Should change to use Car.cpp
 *  2. Search function should output vector full of Cars
 */

class CarTree {

public:
    struct Car2 {
        string name = "NA";
        string driveTrain = "NA";
        string Class = "NA";
        string year = "NA";
        string type = "NA";
        string trans = "NA";
        string pSpace = "NA";
        string sSpace = "NA";
        string engDisp = "NA";
        string fuelEcon = "NA";
        string ghg = "NA";
        string savings = "NA";
        string mpg1 = "NA";
        string mpg2 = "NA";
        string fuel1 = "NA";
        string fuel2 = "NA";
        Car2() = default;
        Car2(string car[]) {
            name = car[0] + " " + car[1];
            driveTrain = car[2];
            Class = car[3];
            year = car[4];
            type = car[5];
            trans = car[6];
            pSpace = car[7];
            sSpace = car[8];
            engDisp = car[9];
            fuelEcon = car[10];
            ghg = car[11];
            savings = car[12];
            mpg1 = car[13];
            mpg2 = car[14];
            fuel1 = car[15];
            fuel2 = car[16];
        }
    };
private:
    struct Node {
        string key;
        Car2 data;
        bool isLeaf;
        vector<Node*> parent;
        vector<Node*> childs;
        ~Node() = default;
        Node(bool isLeaf, vector<Node*> parent, string key) : isLeaf(isLeaf), parent(parent), key(key){}
    };
public:
    Node *roots[8];
    void createTree();
    void insert(string carstr[]);
    vector<Car2> findCar(string params[]);
};
#endif //DSAPROJ3_CARTREE_H
