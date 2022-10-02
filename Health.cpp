#include "Health.h"

Health::Health(Texture* text, Vector2u imagecount, float switchtime):
	animation(text, imagecount, switchtime)
{
	
	//Setting the postion,size,origin(mid point of the image), and scale(it is also the size)
	body.setPosition(110.0f, 70.0f);
	body.setSize(Vector2f(220.0, 200.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setScale(Vector2f(1.0, 1.0));
	//loading image as texture
	body.setTexture(text);
	body.setTextureRect(animation.uvRect);
	//we are updating the animation so the updated animation draws on the screen 
	animation.update(1, 0.12, true);
}

//destrutor
Health::~Health()
{
}

//drawing health bar on screen
void Health::renderhealth(RenderWindow* window)
{
	window->draw(body);
}

void Health::update(float deltatime, int row)
{
	//updating the animation of health bar
	body.setTextureRect(animation.uvRect);
	animation.update(row, deltatime, true);
}
