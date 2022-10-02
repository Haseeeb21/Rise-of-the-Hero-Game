#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include<iostream>
using namespace sf;

class Time_animation
{
public:
	//public functiond
	//condtructor / destructor
	Time_animation(Texture* text, Vector2u imagecount, float switchtime);
	~Time_animation();
	//Function to draw hero on the screen
	void rendertime(RenderWindow* window);
	void update(float deltatime);
private:
	//private variables
	//object on which the hero will be drawn
	RectangleShape body;
	//other class that is been used
	Animation animation;
};

