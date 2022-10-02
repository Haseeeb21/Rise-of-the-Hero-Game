#include "Animation.h"

//constructor
Animation::Animation(Texture* text, Vector2u imagecount,float swtichtime)
{
	//time at which the images will shufftle
	this->switchtime = swtichtime;
	//number of images in the texture
	this->imagecount = imagecount;

	time = 0.0f;
	currentimage.x = 0;
	//Saving the width of the single image from the file 
	uvRect.width =static_cast<int>(text->getSize().x /float(imagecount.x));
	//Saving the height of the single image from the file 
	uvRect.height = static_cast<int>( text->getSize().y /float(imagecount.y));
}

//Destructor
Animation::~Animation()
{
}

//Funtion to update/change images between the row of iamges
void Animation::update(int row, float deltatime, bool faceright)
{
	//cureent image
	currentimage.y = row;
	time +=deltatime;
	//setting condition to change the iamges at which speed
	if (time > switchtime)
	{
		//Reseting the time
		time -=switchtime ;
		//increment in the images
		currentimage.x++;

		//Setting condition that if the iamge reach the end of the row of the image
		if (currentimage.x>=imagecount.x)
		{
			currentimage.x = 0;
		}
	}

	uvRect.top = currentimage.y * uvRect.height;
	//Setting the condition which inverts the right moveing image to left moving image
	if (faceright)
	{

		uvRect.left = currentimage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentimage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	
}


