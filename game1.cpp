#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include"Enemy.h"
#include"Hero.h"
#include "Time_animation.h"
#include<iostream>
#include<string>

using namespace sf;
using namespace std;

int main()
{
	string y;
	cout << ".................................\"How to play the game\".....................................\n";
	cout << ".....................................\"For movemennt\"........................................\n";
	cout << ".....................................\"W for going Up\".......................................\n";
	cout << ".....................................\"S for going Down\".....................................\n";
	cout << ".....................................\"A for going Left\".....................................\n";
	cout << ".....................................\"D for going Right\"....................................\n";
	cout << "...............................\"Hold J for attacking the enemy\".............................\n";
	cout << "...............................\"For each kill you get 10 points\"............................\n";
	cout << "....................\"If 11 enemies passes you and get to the castle you lose\"................\n";
	cout << "....................\"You have 2 minutes to kill as many enemies as you can\"..................\n";
	cout << "..............................\"Hopefully you will enjoy the game\"...........................\n";
	cout << "\n\nPlease enter \"Your name\" to start the game: ";
	cin >> y;
	
	//Creating window
	RenderWindow window(VideoMode(1920,1080), "THE RISE OF THE HERO", Style::Close|Style::Fullscreen);
	//setting frame reate
	window.setFramerateLimit(60);

	//Creating a texture variable for health
	Texture HEALTH;
	//Smoothing the texture loaded
	HEALTH.setSmooth(true);
	//Loading images from the file 
	HEALTH.loadFromFile("content/Heart.png");
	//Creating a texture variable for enemy
	Texture EMEMY;
	//Smoothing the texture loaded
	EMEMY.setSmooth(true);
	//Loading images from the file 
	EMEMY.loadFromFile("content/Enemy1.png");
	//Creating Enemy class variable and passing the required variable
	Enemy enemy(&EMEMY, Vector2u(4, 1), 0.1, &HEALTH, Vector2u(1, 11), 0.1);

	//Creating a tecture variable for Hero
	Texture HERO;
	//Smoothing the texture
	HERO.setSmooth(true);
	//Loading the images
	HERO.loadFromFile("content/Hero.png");
	//Creating hero class variable
	Hero hero(&HERO, Vector2u(5, 5), 0.1);
	
	//Background
	Texture bg;
	bg.loadFromFile("content/bg01.png");
	//creating a rectangle shape in which the background will print/exisit
	RectangleShape bx;
	bx.setTexture(&bg);
	bg.setSmooth(true);
	//setting size of background
	bx.setSize(Vector2f(1920,1080));
	

	//ANIMATION FOR TIME
	Texture TM;
	TM.loadFromFile("content/TIME1.png");
	TM.setSmooth(true);
	Time_animation time_obj(&TM,Vector2u(120,1),1);

	//variable to store time
	float deltatime;
	//A class that record time
	Clock cll,dll;
	//A class that handle time 
	Time time;
	//variable to decied the speed of enemy
	float speed = 4.0;
	//condition to run the game
	while (window.isOpen())
	{
		//setting an end condition
		if (enemy.end() <= 10 && time.asSeconds() < 120)
		{
			//Storeing time
			deltatime = cll.restart().asSeconds();
			//updating/moving positon of enemy and hero 
			enemy.update(deltatime, &window, speed);
			hero.updatehero(deltatime, &window);
			time_obj.update(deltatime);
			///clearing the frame of window
			window.clear();
			//drawing enemy,hero and background on the window
			window.draw(bx);
			enemy.healthbar(&window);
			enemy.render(&window);
			hero.renderhero(&window);
			time_obj.rendertime(&window);
			//displaying the the things that we had drawn on the window 
			window.display();
			//saving the time elapsed kind of a stop watch
			time = dll.getElapsedTime();
		}
		else
		{
			//closing the  game window when the end condition reach at some point
			window.close();
		}
	
		
	}
	if (enemy.end() >= 10)
	{
		cout << y << "! you have lost the game. \n";
	}
	else
	{
		cout << y << "! you hav won the game. \n";
	}
	//displaying the point on the console 
	cout << y << "! you have killed " << enemy.getpoint() / 10 << " enemies. \n";
	cout << y << "! your score is " << enemy.getpoint() << "." << endl;
}
