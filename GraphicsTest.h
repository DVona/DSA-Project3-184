//
// Created by dvdot on 12/1/2023.
//
#include "include/SFML/Config.hpp"
#include "include/SFML/System.hpp"
#include "include/SFML/Window.hpp"
#include "include/SFML/Graphics.hpp"
using namespace std;
using namespace sf;

#ifndef DSAPROJ3_GRAPHICSTEST_H
#define DSAPROJ3_GRAPHICSTEST_H

void setText(Text& text, float x, float y);
void drawButtons(RectangleShape* buttonRect, int count, RenderWindow* window, Text* text, vector<string>* variables);
void genGraphics();

#endif //DSAPROJ3_GRAPHICSTEST_H
