#include "Hero.h"

//constructor
Hero::Hero(Texture* text, Vector2u imagecount, float switchtime):
	animation(text,imagecount,switchtime)
{
	//Setting the postion,size,origin(mid point of the image), and scale(it is also the size)
	body.setPosition(200.0f, 200.0f);
	body.setSize(Vector2f(150.0, 160.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setScale(Vector2f(1.0, 1.0));
	//loading image as texture
	body.setTexture(text);

}

//destructor
Hero::~Hero()
{
}
//Funtion that is responsible for the movement of the hero
void Hero::updatehero(float deltatime,RenderWindow *window)
{
	//creating a variable that is going to be used in condition 
	bool faceright = true;
	//location of the image that should be shown on screen 
	unsigned int row;
	//Speed at which the hero will move
	float speed = 170;
	//setting movement speed
	Vector2f movement(0.0f, 0.0f);
	//setting some conditions that will help in moving the hero 
	if (Keyboard::isKeyPressed(Keyboard::Key::A))
	{
		//checking if we are moving in right or left direction 
		faceright = false;
		//location of image that is to be loaded
		row = 0;
		//new location at which the hero will stad after moveing 
		movement.x -= speed * deltatime;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D))
	{
		//checking if we are moving in right or left direction 
		faceright = true;
		//location of image that is to be loaded
		row = 0;

		//new location at which the hero will stad after moveing
		movement.x += speed * deltatime;
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Key::W))
	{
		faceright = true;
		row = 1;
		movement.y -= speed * deltatime;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S))
	{
		row = 2;
		movement.y += speed * deltatime;
	}
	if (movement == Vector2f(0.0f, 0.0f))
	{
		//location of image that iz to be loaded when no movement command is detected
		row = 3;
	}
	if (Keyboard::isKeyPressed(Keyboard::J))
	{
		//location of image that hase to be loaded when the hero attack
		row = 4;
	}
	//using animation class to load images
	animation.update(row, deltatime, faceright);
	//setting texture rect(it help us to load the part of image we need from the whole image)
	body.setTextureRect(animation.uvRect);
	//moving the hero
	body.move(movement);
	//getting te boundry of the hero
	body.getGlobalBounds().contains(window->mapPixelToCoords(Mouse::getPosition(*window)));
	//Setting mouse mostion according to the window
	Mouse::getPosition(*window);
	Mouse::setPosition(Vector2i(body.getPosition()));

}
//drawing hero on the frame
void Hero::renderhero(RenderWindow *window)
{
	window->draw(body);
}
