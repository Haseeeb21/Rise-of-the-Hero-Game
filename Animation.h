#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Animation
{
	
public:
	//Public functions
	//Constructor/destructor
	Animation(Texture* text, Vector2u imagecount, float swtichtime);
	~Animation();
	//Function that is going to update the image of the enemy/hero as they move or even stand
	void update(int row, float deltatime,bool faceright);
	
public:
	//Public variables
	IntRect uvRect;

private:
	//Private variable
	//Variable to count the total number of images on the the given file  
	Vector2u imagecount;
	//Variable that store the location of the current image that is store on the screen
	Vector2u currentimage;
	//variables that deal with time/rate at which the images will change between them self
	float switchtime;
	double time;
};

