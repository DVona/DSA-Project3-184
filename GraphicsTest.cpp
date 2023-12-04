//
// Created by dvdot on 11/29/2023.
//
#ifndef DSAPROJ3_GRAPHICSTEST_CPP
#define DSAPROJ3_GRAPHICSTEST_CPP
#include "GraphicsTest.h"
using namespace std;
using namespace sf;

void setText(Text& text, float x, float y) {
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(Vector2f(x, y));
}
void drawButtons(RectangleShape* buttonRect, int stageNum, RenderWindow* window, Text* text, vector<string>* variables, vector<string>* questions){
    int buttonNum = 0;
    float buttonLen = window->getSize().x/variables->size();
    text->setFillColor(Color::White);
    text->setStyle(Text::Bold | Text::Underlined);
    if (stageNum < 4){
        text->setString(questions->at(stageNum));
    }
    else if (stageNum < 11){
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
        buttonRect->setFillColor(Color(255/variables->size()*(1+buttonNum),255 - 255/variables->size()*(1+buttonNum),0));
        window->draw(*buttonRect);
        text->setString(variable);
        setText(*text,buttonLen*buttonNum+buttonLen/2,window->getSize().y - 150);
        window->draw(*text);
        buttonNum++;
    }
}

void genGraphics(){
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
            "was made recently?",
            "has lots of passenger space?",
            "has lots of storage space?",
            "is fast?",
            "has good fuel economy?",
            "produces little green house gasses?",
            "will save you gas money?"};
    vector<vector<string>> quantitativeVars  =
            {{"Gas",                     "Hybrid",                     "Electric"},
             {"Compact\nCar",             "Sport\nUtility\nVehicle",      "Two\nSeater","Large\nCars","Truck","Midsize\nCars","Van",                     "Special\nPurpos\nVehicle",    "Station\nWagon","NA"},
             {"Automatic Transmission",  "Manual Transmission"},
             {"Front-Wheel\nDrive",       "All-Wheel\nDrive",            "Rear-Wheel\nDrive","4-Wheel\nDrive","Part-time\n4-Wheel\nDrive", "4-Wheel\nor\nAll-Wheel\nDrive", "NA"}};
    int stageNum = 0;
    int selections[12];
    string algoInputs[15];

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
                    if (stageNum < 4){
                        int buttonWid = windowObj.getSize().x/quantitativeVars[stageNum].size();
                        for (int i = 0; i < quantitativeVars[stageNum].size(); i++){

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
                    else{
                        stageNum = 0;
                    }
                }
            }

        }

        windowObj.clear();
        windowObj.draw(background);
        if (stageNum < 4){
            drawButtons(&buttonRect,stageNum,&windowObj,&buttonText,&quantitativeVars[stageNum],&categoryPrompts);
        }
        else if (stageNum < 11){
            drawButtons(&buttonRect,stageNum,&windowObj,&buttonText,&numStrings,&categoryPrompts);
        }
        else if (stageNum == 11){
            drawButtons(&buttonRect,stageNum,&windowObj,&buttonText,&algNames,&categoryPrompts);
        }
        else{
            if (selections[11] == 1){
                //Run Tree
                CarTree();
            }
            else{

            }
        }
        windowObj.display();
    }
}
#endif