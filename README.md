# Rise-of-the-Hero-Game
The website that was developed was of this game. In this game a Hero defends his nation by killing the enemies attacking on his nation if he survives 2 minutes then he wins otherwise if he loses all his health then the game is over.

<br/>

## Title:
<h1 align="center">Rise of the Hero</h1>

## Introduction:

This project is a `2D game` in which our hero is defending his motherland from the Enemy Boss minions who are attacking on his motherland. The hero is fighting against the minions who are attacking his motherland. Each kill the Hero does he achieves 10 points. He has a limited health which he will be losing if he misses the minions. The time limit of the game is 2 minutes, either he survives and will be successful in defending his motherland, or the hero loses his all health (chances) then he dies, and the game will be over. 

## How to Play:

At start the user will be displayed the instructions of the game (How to play), using keyboard buttons `A`, `W`, `S`, `D` the user can do movement of the hero. The button `J` is used to attack, the hero attacks with the sword in his hand. Health bar will show the current health of the hero, and the 2 minutes timer will also be running on the top right corner. Each kill will add 10 points, and if he misses 10 enemies then he will lose, and the game will be over and total points will be displayed at the end of the game with the name of the user.

## Techniques Used:

In this project we used Visual Studio 2019 as a platform to write the code of our project, we used basic commands of `C++` which are cout, cin, while loop, for loop etc.
The group focus was on the `SFML` (Simple and Fast Multimedia Library) which is the key to success in completing our project. We used the Graphic & Window library from `SFML`. We have used the concept of `OOPS` in `C++` and created `Classes`.

Different concepts such as:
- SFML Windows
- SFML Graphics
- SFML System
- SFML Clock
- SFML Time
- Inheritance
- Encapsulation
- Abstraction
- Condition loops
- Input statements
- Output statements
- Classes 
etc., were used.

The project is divided into six Classes and six `.cpp` files which are `Game1 (main)`, `Animation`, `Enemy`, `Hero`, `Health`, and `Time`.


- In main (game1.cpp) function we are using SFML Graphics, Window& System library and we are calling all the other classes and using their function to perfume specific takes like updating the characters and drawing the characters on the window. Main function is also used to load the background image and the score that the hero gets after killing an enemy.

- In Enemy.cpp file we are using the functions that were declared in the header file. We have made different functions like update function which is being used to move the enemy on the x-axis automatically without any key pressed with a fix speed, spawn function which is being used to spawn enemy on the window with position which is fixed on the x-axis but random on the y-axis.

- In Animation.cpp we are defining values to variables in the constructor function which are going to help in the process of running the animation. The update function is basically changing the images from the sprite sheet which was load in with the Texture command (contents of game).

Animation class is being used in Enemy and Hero class to load the image that we see on the screen and the moving image that we see while moving or attacking the hero

- In the Hero.cpp file we are making our hero move and attack the enemy. In the constructor function we are defining the body and the animation of the hero.  In the render function we are just drawing the hero on the screen as he moves on the window.

- In Health.cpp the heart picture is loaded and displayed. After each enemy miss half heart is lost and if all health is 

- In Time.cpp the time is loaded and starts from 0:00 after the game is started by the user.




## Screen Shots:
 
![image](https://user-images.githubusercontent.com/91841622/193602038-1d9e1efb-55f9-4f4b-8136-01c21b9939e7.png)

![image](https://user-images.githubusercontent.com/91841622/193602050-5383f054-f8e0-43a0-92e3-d119fe22438b.png)

![image](https://user-images.githubusercontent.com/91841622/193602069-3e3349d4-8418-48f5-bd28-b8e8e7a2cfaf.png)

![image](https://user-images.githubusercontent.com/91841622/193602090-b5809aa1-d840-4ee5-93fe-388fdfc90f03.png)


 
 

