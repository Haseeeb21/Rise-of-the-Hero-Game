#include "Time_animation.h"

Time_animation::Time_animation(Texture* text, Vector2u imagecount, float switchtime):
	animation(text, imagecount, switchtime)
{
	//Setting the postion,size,origin(mid point of the image), and scale(it is also the size)
	body.setPosition(1800.0f, 70.0f);
	body.setSize(Vector2f(250.0, 250.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setScale(Vector2f(1.0, 1.0));
	//loading image as texture
	body.setTexture(text);
}


Time_animation::~Time_animation()
{
}

void Time_animation::update(float deltatime)
{
	animation.update(0, deltatime, true);
	body.setTextureRect(animation.uvRect);
}

void Time_animation::rendertime(RenderWindow* window)
{
	window->draw(body);
}


