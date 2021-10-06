#include <iostream>
#include <SDL.h>
#include <string>
#include "Background.h"  
#include "Explosion.h"  
#include "GameObjects.h"
#include "Input.h"
#include "Player.h"
#include "Score.h"
#include "Screen.h"
#include "Sprites.h"
#include "Stone.h"
#include "Text.h"
#include "Vector2D.h"
#include "Win.h"

bool isGameRunning = true;

int main(int argc, char* argv[])
{
	srand(time(NULL));

//==================INITIALIZING CLASSES==================

	Screen screen;         //Screen class
	Input input;          //Input class 
	Music::Initialize(); //Initialize music class
	Text::Initialize(); //Initialize text class

	if (screen.Initialize() == false)   //create game window
	{
		return 0;
	}

	Background background(screen);   //background game object class
	background.SetPosition(0, 0);
	background.SetSize(1280, 720);
	background.BackgroundNoise();

	Player player(screen);   //Player game object class 
	player.SetSpeed(7);
	player.SetPosition(50, 550);
	player.IsAlive(true);

	Stone stone(screen);   //Asteroid game object class
	stone.SetRandPos(0, -150);
	stone.SetAngle(25.0 + rand() % 360);   
	stone.SetAsteroidFall(1, 5);

	Explosion explosion(screen);   //Class for explosions
	explosion.SetPosition(stone.GetPosition());

	Score* score = new Score;   //class for score
	score->SetScore(0);

	Win win(screen);   //class for win scene
	win.SetPosition(400, 200);

//==================MAIN GAME LOOP==================

	while (isGameRunning)
	{
		screen.ClearScreen();   //Clear screen for a fresh start

		input.Update();       //Mouse/keyboard input 

		if (input.IsWindowClosed())
		{
			isGameRunning = false; 
		}
		if (input.GetKeyDown() == SDLK_ESCAPE)
		{
			isGameRunning = false;
		}

		background.Render(screen);		
		
		stone.Update(input);
		stone.Render(screen);
		
		player.Update(input);
		player.Render(screen);		
		
		for (int a = 0; a < 100; a++)   //asteroids looping for 100 loops
		{
			if (stone.GetPosition().y > 550)  //If the asteroids reach 550 on y
			{
				explosion.SetPosition(stone.GetPosition());  //Explosion animation is triggered at the asteroids latest position
				explosion.IsActive(true);
				explosion.IsVisible(true);
				explosion.Update(input);   
				explosion.Render(screen);
				score->ScoreAdd(1);   //1 score is added
				stone.SetRandPos(0, -150);   //reset asteroid position
			}
		}

		if (score->GetScore() >= 10)   //Miss 10 asteroids to win
		{
			stone.SetVelocity(0);
			player.IsActive(false);

			win.Applause();
			win.Update(input);
			win.Render(screen);
		}
		
		BoxCollider playerCollider = player.GetCollider();    //box collider
		BoxCollider stoneCollider = stone.GetCollider();

		if (playerCollider.IsColliding(stoneCollider))   //other functions stated in Player.cpp
		{
			stone.SetVelocity(0);
			player.IsAlive(false);
		}

		score->Render(screen);   //Make score appear on screen

		screen.Present();   //Presenting game screen
	}

	delete score;

//==================SHUTDOWN TASKS==================

	Text::Shutdown();

	screen.ShutDown();

	return 0;
}