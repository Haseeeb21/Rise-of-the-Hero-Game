#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include"Animation.h"
#include"Health.h"


using namespace std;
using namespace sf;

class Enemy
{
public:
	//public funtions
	//constructor/destructors
	Enemy(Texture* text, Vector2u imagecount, float switchtime, Texture* heart, Vector2u imagecount_heart, float switchtime_heart);
	 ~Enemy();

	//functions......
	//Spawning enemy on the window 
	void Enemyspawn(RenderWindow* window);
	//Updating/moving enemy position on the screen
	void updateEnemy(float deltatime, RenderWindow* window, float speed);
	//Creating a function that will include other function so we have to write only one function in the main function 
	void update(float deltatime, RenderWindow* window, float speed);
	//Drawing enemy on the window
	void render(RenderWindow *window);
	//drawing health bar
	void healthbar(RenderWindow* window);
	//Funtion to close window 
	void pollevent( RenderWindow* window);
	//To record mouseposition
	void mousepositon(RenderWindow* window);
	//Get points by defeating enemy
	float getpoint();
	//ending the game
	int end();
	
private:
	//private functions
	//intilizing the variable and saveing some values in it
	void intivariable();
	//intilizing the enemy character 
	void intienemy();
	
private:
	//private variable
	//variable to recored ant function that may occure while the program run 
	Event ev;

	//Game logic
	//variables that are going to be used to store data for certain condition of the games
	int point;
	float enemyspawntimer;
	float enemyspawntimer_max;
	int maxenemies;
	int loss=0;
	int row_heart=1;
	//To recored mouse position
	Vector2i mouseposwindow;
	Vector2f mouseposview;

	//Objects on which the image will be created
	std::vector <RectangleShape>enemies;
	RectangleShape enemy;

	//other class involed 
	Animation animation;
	Health health;
};