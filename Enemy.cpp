#include "Enemy.h"
#include <ctime>
#include <thread>
#include<chrono> 

//Constructor
Enemy::Enemy(Texture* text, Vector2u imagecount, float switchtime, Texture* heart, Vector2u imagecount_heart, float switchtime_heart) :
	animation(text, imagecount, switchtime), health(heart, imagecount_heart, switchtime_heart)
{

	this->intivariable();
	this->intienemy();
	this->mouseposwindow;
	//Seting the texture of the Enemy
	this->enemy.setTexture(text);
	
}
//Destructor
Enemy::~Enemy()
{
}

void Enemy::intivariable()
{
	 
	//Game logics
	//Setting the points,spawn timer and the limit of maximum enemies on the screen
	this->point = 0;
	this->enemyspawntimer_max = 40.f;
	this->enemyspawntimer = this->enemyspawntimer_max;
	this->maxenemies = 6;
}

//initlizing the enemy
void Enemy::intienemy()
{
	//Setting the positon,size,origin and scle of enemy
	enemy.setPosition(0.0f, 0.0f);
	this->enemy.setSize(Vector2f(170.f, 130.f));
	this->enemy.setOrigin(this->enemy.getSize() / 2.0f);
	this->enemy.setScale(Vector2f(1, 1));
}


//Function to Draw
void Enemy::render(RenderWindow* window)
{
	//drawing all the enemies
	for (auto& e : this->enemies)
	{
		window->draw(e);
	}
}

//function to draw health on screen 
void Enemy::healthbar(RenderWindow* window)
{
	health.renderhealth(window);
}

//updating window
void Enemy::update(float deltatime, RenderWindow* window,float speed)
{
	//calling the events
	this->pollevent(window);
	//mousepostion
	this->mousepositon( window);
	//updating the enemy
	this->updateEnemy( deltatime,window,speed);

}

//Doing something / events
void Enemy::pollevent(RenderWindow *window)
{
	
	//taking some action  /  event
	while (window->pollEvent(this->ev))
	{
		switch (ev.type)
		{
		case Event::Closed:
		{

			window->close();

		}
		//Closing the window when Esc key is press
		case Event::KeyPressed: 
		{
			if (ev.key.code == Keyboard::Escape)
			{
				window->close();
				break;
			}

		}
		default:
			break;
		}
	}

}

//mouse postion
void Enemy::mousepositon(RenderWindow *window)
{
	//Recoding the mouse position on the screen
	this->mouseposwindow = Mouse::getPosition(*window);
	this->mouseposview = window->mapPixelToCoords(this->mouseposwindow);
}

//Function to automatically spawn Enemy
void Enemy::Enemyspawn(RenderWindow* window)
{
	//Setting position of the Enemy
	this->enemy.setPosition(
		1920,
	20+(static_cast<float>(rand() % static_cast<int>(window->getSize().y - this->enemy.getSize().y))
	));
	
	//spawn the enemy
	this->enemies.push_back(this->enemy);

}

//updating / moving the enemies
void Enemy::updateEnemy(float deltatime, RenderWindow* window,float speed)
{	

	//Drawing the enemy on the window
	animation.update(0, deltatime, true);
	enemy.setTextureRect(animation.uvRect);
	//updating the timer for enemy spawning 
	if (this->enemies.size() < this->maxenemies)
	{

		if (this->enemyspawntimer >= this->enemyspawntimer_max)
		{
			//spawning the enemies
			this->Enemyspawn(window);
			this->enemyspawntimer = 0.f;
		}
		else
		{
			this->enemyspawntimer += 1.f;
		}
	}

	//moves and udates the enemies
	for (int i = 0; i < this->enemies.size(); i++)
	{
		//variable to delete the enemy 
		bool deleted = false;
		//moving the enemies
		this->enemies[i].move(-(speed), 0.f);
		this->enemies[i].setTextureRect(animation.uvRect);

		//geting the position of the enemies
		Vector2f poss;
		poss = enemies[i].getPosition();
		if (Keyboard::isKeyPressed(Keyboard::J))
		{
			if (this->enemies[i].getGlobalBounds().contains(this->mouseposview.x,this->mouseposview.y))
			{
				//deleting the enemy
				deleted = true;
				//Gain points
				this->point += 10;
			}
		}
		//if the enemy pass the left side of the screen
		if ((enemies[i].getPosition().x<-1))
		{
			//changeing the row of the health animation
			this->row_heart++;
			health.update(deltatime, row_heart);
			//destroying the enemy object
			this->enemies.erase(this->enemies.begin() + i);
			this->loss++;
			
		}
		//erase the enemy
		if (deleted)
		{
			this->enemies.erase(this->enemies.begin() + i);	
		}

	}
	
}//updateing enemy end 


//Returning the points
float Enemy::getpoint()
{
	return this->point;
}
//ending condition
int Enemy::end()
{
	return this->loss;
}