#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include<iostream>
using namespace sf;

class Health
{
public:
	//public functiond
	//condtructor / destructor
	Health(Texture* text, Vector2u imagecount, float switchtime);
	~Health();
	//Function to draw hero on the screen
	void renderhealth(RenderWindow* window);
	void update(float deltatime,int row);
private:
	//private variables
	//object on which the hero will be drawn
	RectangleShape body;
	//other class that is been used
	Animation animation;
};


