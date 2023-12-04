#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include "CarTree.h"
#include "Algo1.cpp"
#include "include/SFML/Graphics.hpp"
using namespace std;
using namespace sf;

void setText(Text& text, float x, float y) {
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(Vector2f(x, y));
}
void setTextLeft(Text& text, float x, float y) {
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left, textRect.top + textRect.height / 2.0f);
    text.setPosition(Vector2f(x, y));
}
void drawStart(RectangleShape* buttonRect, RenderWindow* window, Text* text){
    buttonRect->setSize(Vector2<float>(window->getSize().x,300));
    buttonRect->setPosition(0,window->getSize().y - 300);
    buttonRect->setFillColor(Color(0,255,0));
    window->draw(*buttonRect);
    text->setString("Click to Start");
    text->setFillColor(Color::Black);
    text->setStyle(Text::Regular);
    text->setCharacterSize(28);
    setText(*text,window->getSize().x/2.f,window->getSize().y - 150);
    window->draw(*text);
    text->setFillColor(Color::White);
    text->setStyle(Text::Bold | Text::Underlined);
    text->setString("Find Your Dream Car!");
    text->setCharacterSize(50);
    setText(*text,window->getSize().x/2.f,300);
    window->draw(*text);
}
void drawResults(RectangleShape* buttonRect, RenderWindow* window, Text* text, Car* car){
    buttonRect->setSize(Vector2<float>(window->getSize().x,300));
    buttonRect->setPosition(0,window->getSize().y - 300);
    buttonRect->setFillColor(Color(0,255,0));
    window->draw(*buttonRect);
    text->setString("Click to Restart");
    text->setFillColor(Color::Black);
    text->setStyle(Text::Regular);
    text->setCharacterSize(28);
    setText(*text,window->getSize().x/2.f,window->getSize().y - 150);
    window->draw(*text);
    text->setFillColor(Color::White);
    text->setStyle(Text::Bold | Text::Underlined);
    text->setString("Your Dream Car:");
    text->setCharacterSize(50);
    setTextLeft(*text,50,50);
    window->draw(*text);
    text->setCharacterSize(28);
    text->setString("Make/Model: "+car->make+" "+car->model);
    setTextLeft(*text,50,100);
    window->draw(*text);
    text->setStyle(Text::Regular);
    text->setString("Year: "+to_string(car->year));
    setTextLeft(*text,50,150);
    window->draw(*text);
    text->setString("Fuel Efficiency (m/g or m/kWh): "+to_string(max(car->mpg1,car->mpg2)).substr(0,4));
    setTextLeft(*text,50,200);
    window->draw(*text);
    text->setString("Size: "+car->sizeClass);
    setTextLeft(*text,50,250);
    window->draw(*text);
    if (car->automatic){
        text->setString("Transmission: Automatic Transmission");
    }
    else {
        text->setString("Transmission: Manual Transmission");
    }
    setTextLeft(*text,50,300);
    window->draw(*text);
    text->setString("Drive: "+car->drive);
    setTextLeft(*text,50,350);
    window->draw(*text);
    if (car->displacement == 0){
        text->setString("Engine Displacement(L): NA");
    }
    else{
        text->setString("Engine Displacement(L): "+to_string(car->displacement).substr(0,3));
    }
    setTextLeft(*text,50,400);
    window->draw(*text);
    if (car->cylinders == 0){
        text->setString("Engine Cylinders: NA");
    }
    else{
        text->setString("Engine Cylinders: "+to_string(car->cylinders));
    }
    setTextLeft(*text,50,450);
    window->draw(*text);
    text->setString("Primary Fuel Type: "+car->fuel1);
    setTextLeft(*text,window->getSize().x/2,150);
    window->draw(*text);
    text->setString("Secondary Fuel Type: "+car->fuel2);
    setTextLeft(*text,window->getSize().x/2,200);
    window->draw(*text);
    if (car->passengerSpace == 0){
        text->setString("Passenger Space(L): NA");
    }
    else{
        text->setString("Passenger Space(L): "+to_string(car->passengerSpace));
    }
    setTextLeft(*text,window->getSize().x/2,250);
    window->draw(*text);
    if (car->storageSpace == 0){
        text->setString("Storage Space(L): NA");
    }
    else{
        text->setString("Storage Space(L): "+to_string(car->storageSpace));
    }
    setTextLeft(*text,window->getSize().x/2,300);
    window->draw(*text);
    if (car->fuelEconScore == -1){
        text->setString("Fuel Economy Score: NA");
    }
    else{
        text->setString("Fuel Economy Score: "+to_string(car->fuelEconScore)+"/10");
    }
    setTextLeft(*text,window->getSize().x/2,350);
    window->draw(*text);
    if (car->ghgScore == -1){
        text->setString("Greenhouse Gas Score: NA");
    }
    else{
        text->setString("Greenhouse Gas Score: "+to_string(car->ghgScore)+"/10");
    }
    setTextLeft(*text,window->getSize().x/2,400);
    window->draw(*text);
    text->setString("5-year Savings: $"+to_string(car->savings));
    setTextLeft(*text,window->getSize().x/2,450);
    window->draw(*text);

}
void drawButtons(RectangleShape* buttonRect, int stageNum, RenderWindow* window, Text* text, vector<string>* variables, vector<string>* questions){
    int buttonNum = 0;
    float buttonLen = window->getSize().x/variables->size();
    text->setFillColor(Color::White);
    text->setStyle(Text::Bold | Text::Underlined);
    if (stageNum < 4){
        text->setString(questions->at(stageNum));
    }
    else if (stageNum < 12){
        text->setString("On a scale from 1-10, how important is it that\nyour car " + questions->at(stageNum));
    }
    else {
        text->setString("Which Algorithm would you like to use?");
    }
    text->setCharacterSize(50);
    setText(*text,window->getSize().x/2.f,(window->getSize().y-300)/2);
    window->draw(*text);
    text->setCharacterSize(24);
    buttonRect->setSize(Vector2f(buttonLen,300));
    text->setStyle(Text::Regular);
    text->setFillColor(Color::Black);
    for (string variable : *variables){
        buttonRect->setPosition(buttonLen*buttonNum,window->getSize().y - 300);
        buttonRect->setFillColor(Color(255 - 255/variables->size()*(buttonNum),255/variables->size()*(1+buttonNum),0));
        window->draw(*buttonRect);
        text->setString(variable);
        setText(*text,buttonLen*buttonNum+buttonLen/2,window->getSize().y - 150);
        window->draw(*text);
        buttonNum++;
    }
}

int main(){
    CarData dataset;
    float windowWidth = 900;
    float windowHeight = 1500;
    RenderWindow windowObj(VideoMode(int(windowHeight),int(windowWidth)), "Car Selector");
    RectangleShape background(Vector2f(windowHeight,windowWidth));
    background.setFillColor(Color::Black);
    Font font;
    font.loadFromFile("font.ttf");
    Text welcome_text;
    welcome_text.setFont(font);
    welcome_text.setString("Find Your Dream Car!");
    welcome_text.setCharacterSize(24);
    welcome_text.setFillColor(Color::White);
    welcome_text.setStyle(Text::Bold | Text::Underlined);
    setText(welcome_text, windowHeight / 2.0f, (windowWidth / 2.0f) - 150);
    RectangleShape buttonRect;
    Text buttonText;
    buttonText.setFont(font);
    buttonText.setFillColor(Color::White);
    vector<string> algNames = {"Tree Algorithm", "Ranking Algorithm"};
    vector<string> numStrings = {"1","2","3","4","5","6","7","8","9","10"};
    vector<string> categoryPrompts = {
            "What kind of fuel are you looking for?",
            "What size class are you looking for?",
            "What kind of transmission are you looking for?",
            "What type of drive are you looking for?",
            "is fuel efficient?",
            "was made recently?",
            "has lots of passenger space?",
            "has lots of storage space?",
            "is fast?",
            "has good fuel economy?",
            "produces little green house gasses?",
            "will save you gas money?"};
    vector<vector<string>> qualitativeVars  =
            {{"Gas",                     "Hybrid",                     "Electric"},
             {"Compact\nCar",             "Sport\nUtility\nVehicle",      "Two\nSeater","Large\nCars","Truck","Midsize\nCars","Van",                     "Special\nPurpos\nVehicle",    "Station\nWagon","NA"},
             {"Automatic Transmission",  "Manual Transmission"},
             {"Front-Wheel\nDrive",       "All-Wheel\nDrive",            "Rear-Wheel\nDrive","4-Wheel\nDrive","Part-time\n4-Wheel\nDrive", "4-Wheel\nor\nAll-Wheel\nDrive", "NA"}};
    vector<vector<string>> qualData  =
            {{},
             {"Compact Car","Sport Utility Vehicle","Two Seaters","Large Cars","Truck","Midsize Cars","Van","Special Purpose Vehicle","Station Wagon","NA"},
             {},
             {"Front-Wheel Drive","All-Wheel Drive","Rear-Wheel Drive","4-Wheel Drive","Part-time 4-Wheel Drive","4-Wheel or All-Wheel Drive","NA"}};
    int stageNum = -1;
    bool noCar = true;
    int selections[13];
    string algoInputs[15];
    Car bestCar;
    windowObj.setKeyRepeatEnabled(false);
    while (windowObj.isOpen())
    {
        Event event;
        while (windowObj.pollEvent(event))
        {
            //window close
            if (event.type == Event::Closed) {
                windowObj.close();
                break;
            }
            else if (event.type == Event::MouseButtonPressed) {
                Vector2i mouse_pos(Mouse::getPosition(windowObj));
                if (mouse_pos.y > windowObj.getSize().y - 300) {
                    if (stageNum < 0){
                        stageNum++;
                    }
                    else if (stageNum < 4){
                        int buttonWid = windowObj.getSize().x / qualitativeVars[stageNum].size();
                        for (int i = 0; i < qualitativeVars[stageNum].size(); i++){

                            if (mouse_pos.x < buttonWid * (1+i)){
                                selections[stageNum] = i;
                                stageNum++;
                                break;
                            }
                        }
                    }
                    else if (stageNum < 12){
                        int buttonWid = windowObj.getSize().x/10;
                        for (int i = 1; i < 11; i++){
                            if (mouse_pos.x < buttonWid * (i)){
                                selections[stageNum] = i;
                                stageNum++;
                                break;
                            }
                        }
                    }
                    else if (stageNum == 12){
                        if (mouse_pos.x < windowObj.getSize().x/2){
                            selections[12] = 1;
                        }
                        else{
                            selections[12] = 2;
                        }
                        stageNum++;
                    }
                    else{
                        stageNum = -1;
                        noCar = true;
                    }
                }
            }

        }
        if (stageNum == 13 && noCar){
            noCar = false;
            algoInputs[0] = qualData.at(3).at(selections[3]);
            algoInputs[1] = qualData.at(1).at(selections[1]);
            algoInputs[3] = qualitativeVars.at(0).at(selections[0]);
            algoInputs[4] = qualitativeVars.at(2).at(selections[2]);
            for (int i = 0; i < 3; i++){
                algoInputs[i+12] = "NA";
            }
            if (selections[12] == 1){
                //Run Tree
                algoInputs[2] = to_string(dataset.yearQuantiles[selections[4]]);
                algoInputs[5] = to_string(dataset.passSpaceQuantiles[selections[6]]);
                algoInputs[6] = to_string(dataset.storSpaceQuantiles[selections[7]]);
                algoInputs[7] = to_string(dataset.displacementQuantiles[selections[8]]);
                algoInputs[8] = to_string(dataset.econScoreQuantiles[selections[9]]);
                algoInputs[9] = to_string(dataset.ghgScoreQuantiles[selections[10]]);
                algoInputs[10] = to_string(dataset.savingsQuantiles[selections[11]]);
                algoInputs[11] = to_string(dataset.mpgQuantiles[selections[5]]);
                CarTree carTree;
                carTree.createTree();
                vector<CarTree::Car2> cars = carTree.findCar(algoInputs);
                bestCar.convertC2(cars[0]);
            }
            else{
                //Run Ranking
                algoInputs[11] = to_string(selections[5]);
                algoInputs[2] = to_string(selections[4]);
                for (int i = 5; i < 11; i++){
                    algoInputs[i] = to_string(selections[i+1]);
                }
                Algo1 rankingAlg;
                bestCar = rankingAlg.algo1(algoInputs);
            }
        }

        windowObj.clear();
        windowObj.draw(background);
        if (stageNum < 0){
            drawStart(&buttonRect,&windowObj,&buttonText);
        }
        else if (stageNum < 4){
            drawButtons(&buttonRect, stageNum, &windowObj, &buttonText, &qualitativeVars[stageNum], &categoryPrompts);
        }
        else if (stageNum < 12){
            drawButtons(&buttonRect,stageNum,&windowObj,&buttonText,&numStrings,&categoryPrompts);
        }
        else if (stageNum == 12){
            drawButtons(&buttonRect,stageNum,&windowObj,&buttonText,&algNames,&categoryPrompts);
        }
        else {
            drawResults(&buttonRect,&windowObj,&buttonText, &bestCar);
        }
        windowObj.display();
    }
    return 0;
}