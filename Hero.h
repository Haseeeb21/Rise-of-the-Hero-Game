#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include<iostream>
using namespace sf;


class Hero
{
public:
	//public functions
	//constructor/destructor
	Hero(Texture* text, Vector2u imagecount, float switchtime);
	~Hero();
	//Function to update/move hero on the window 
	void updatehero(float deltatime, RenderWindow* window);
	//Function to draw hero on the screen
	void renderhero(RenderWindow* window);
private:
	//private variables
	//object on which the hero will be drawn
	RectangleShape body;
	//other class that is been used
	Animation animation;
};

