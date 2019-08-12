#include "windows.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include "glut.h"

#include "CGameHandler.h"
#include "Common.h"
#include "CSquare.h"
#include "CModel.h"
#include "CCube.h"
#include "CPolygon.h"
#include "Scoreboard.h"

#include "Map_Ouside.h"
#include "Sun.h"
#include "Penguin.h"
#include "Poop.h"
#include "Toy_Rabbid.h"
#include "Bowl.h"

#define DAYCYCLESPEEDMODIFIER 10
#define MAXSPEED 0.0004
#define MAX_POOPS 10

// Models 
Sun sun, moon;
Map_Ouside map_outside;

// timeTotal
int time_Start, timeTotal, oldTime, isNext, // Save the current time to see if the time changed
clockSec, clockMin; // Clock (Min:Sec)

// Scoreboard
Scoreboard scoreboard;

// Penguin
Poop poop [10]; // Array of poops
Penguin penguin;
double SPEED; // The penguin speed
int poopClean, numOfPoop; // Count the number of times you have cleaned after the penguin and if % 2 clean one poop | Count the number of poops drawn
bool slept; // if the penguin slept
string name;
bool nameSize;

// Toy
Toy_Rabbid rabbid;

// Bowl
Bowl bowl;

// Misc
double red, green, blue; // background colors
int state; // The state of the Sun & Moon
bool DontHaveEnoughMoney; // If you dont have enough money set to true (to display the message)
GLuint texture;
// Score
int SCORE, MONEY; // amit you fuck ?! how can you not know what are those ?!?!

// GAME STATE - the state of the game
enum GameState {
	MainMenu,
	Play,
	Working,
	GameOver,
	EnterName,
	Exit
};
GameState gameState; // Holds the game state

// Main Menu
CSquare mainMenuBG; // The main menu background

extern void renderBitmapString(float x, float y, void *font, char *string);
extern void renderVerticalBitmapString(float x, float y, int bitmapHeight, void *font, char *string);

bool PayMoney(int value){
	if (MONEY >= value){
		MONEY -= value;
		return true;
	}
	else { DontHaveEnoughMoney = true; return false; }
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN)
			if (gameState == Play){
				if (y > 0 && y < 25){
					if (x > 275 && x < 355){
						if (penguin.sleep <= 95)
							if (PayMoney(50)){
								PlaySoundA("Sound_pills.wav", NULL, SND_ASYNC | SND_FILENAME);
								penguin.sleep += 5;
							}
					}
					if (x > 660 && x < 760){
						if (bowl.AmountLeft() < 5)
							if (PayMoney(100)){
								PlaySoundA("Sound_fill.wav", NULL, SND_ASYNC | SND_FILENAME);
								bowl.Fill();
							}
					}
					if (x > 380 && x < 465){
						if (penguin.clean < 10)
							if (PayMoney(75)){
								PlaySoundA("Sound_clean.wav", NULL, SND_ASYNC | SND_FILENAME);
								penguin.clean++;
								poopClean++;
							}
					}
					if (x > 495 && x < 551){
						if (penguin.fun < 10 && !rabbid.GetPlayed())
							if (PayMoney(200)){
								PlaySoundA("Sound_drop.wav", NULL, SND_ASYNC | SND_FILENAME);
								rabbid.MoveCenter(RandNum(-0.4, 0.4), -0.2, RandNum(-2.2, -1.2));
								rabbid.RotateSelf(Y_AXIS, RandNum(-90, 90));
								rabbid.SetPlayed(true);
							}	
					}
					if (x > 580 && x < 652){
						if (penguin.sick)
							if (PayMoney(200)){
								PlaySoundA("Sound_pills.wav", NULL, SND_ASYNC | SND_FILENAME);
								penguin.sick = false;
							}
					}
					if (x > 1790 && x < 1920 && y > 0){ // Main Menu Button
						gameState = MainMenu;
					}
				}
				if (x > 660 && x < 760 && y > 25 && y < 52){
					if (penguin.hunger < 10 && bowl.Eat()){
						PlaySoundA("Sound_eat.wav", NULL, SND_ASYNC | SND_FILENAME);
						penguin.hunger++;
					}
				}
			}

		if (gameState == MainMenu){
			if (y > 480 && y < 530 && x > 870 && x < 1050){ // Play Button
				gameState = Play;
			}
			if (y < 600 && y > 530 && x > 870 && x < 1050){ // Exit Button
				exit(0);
			}
		}
		if (gameState == GameOver){
			if (x > 905 && x < 1000 && y > 285 && y < 320){
				exit(0);
			}
		}
	}
}

void motion(int x, int y)
{
		std::cout << "Mouse dragged with left button at "
		<< "(" << x << "," << y << ")" << "\n";
}

void CGameHandler::StartOfGame()
{
	/* C++ Stuff */
	srand((unsigned)time(NULL));


	/* Game Initialize */
	ChangeBackgroundColors(0, 0.5, 1); // Sets the background color (blueish)
	// Sun & Moon
	moon.SetColor(0.77, 0.77, 0.77);
	moon.MoveCenterTo(Z_AXIS, -18);
	moon.MoveCenterTo(0, -1, -14);
	sun.MoveCenterTo(0, 0, -18);
	sun.MoveByValue(Y_AXIS, -1);
	// Penguin
	penguin.ScaleAndMoveToCenter(0, -0.2, -2, 0.3, 0.3, 0.3);
	// MainMenu Background
	mainMenuBG.ScalePolygon(0.17, 0.12, 0.001);
	mainMenuBG.MovePolygonCenter(0, 0, -2);
	// Map
	map_outside.RotateTrees(Y_AXIS, RandNum(-360, 360));
	// Toy (Rabbid)
	rabbid.Scale(0.4, 0.3, 0.4);
	rabbid.RotateSelf(X_AXIS, -90);
	// Bowl
	bowl.MoveCenterTo(-0.23, -0.28, -1.3);
	bowl.Scale(0.2, 0.2, 0.2);
	bowl.RotateSelf(Y_AXIS, 34);

	/* Vars Initialize */
	red = green = blue = SCORE = isNext = poopClean = numOfPoop = clockMin = clockSec = state = nameSize = 0;
	MONEY = 200;
	SPEED = 0.0001;
	time_Start = glutGet(GLUT_ELAPSED_TIME); // First Time Initalize
	DontHaveEnoughMoney = false;
	slept = true;
	name = "";
	gameState = EnterName;

	// Bg Sound
	PlaySoundA("Sound_bg.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

//on each frame:
void CGameHandler::DrawScene()
{
	if (gameState != Working){
		// Draw map
		map_outside.DrawMap();
		sun.Draw();
		moon.Draw();

		// Draw poops
		for (int i = 0; i < MAX_POOPS; i++)
			if (poop[i].isPooped())
				poop[i].Draw();

		// Draw Bowl
		bowl.Draw();

		// Draw Toy
		if (rabbid.GetPlayed())
			rabbid.Draw();

		// Draw pets
		penguin.Draw();
	}

	// Main Menu
	if (gameState == MainMenu && gameState != Working){
		mainMenuBG.DrawPolygon();
	}

	if (gameState == Working){
		bowl.Draw();
	}
}

void CGameHandler::LogicPart()
{
	glutMouseFunc(mouse);
	timeTotal = glutGet(GLUT_ELAPSED_TIME); // Setting the time 
	int deltaTime = timeTotal - oldTime; // substract the previous time from the current time
	oldTime = timeTotal; // Sets the old time to the current time
	int timeInCentisecond = timeTotal / 10; // TotalTime in Centisecond (0.01s)

	if (deltaTime > 0){ // Checks if frame has passed
		if (isNext != timeInCentisecond){
			if (timeInCentisecond % 400 == 0)
				PlaySoundA("Sound_bg.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
#pragma region PLAY
			if (gameState == Play){
				if (penguin.health <= 0){
					gameState = GameOver;
				}
				if (state == 1 && timeInCentisecond % 100 == 0 && !slept){
					if (penguin.sleep < 100){
						penguin.sleep += 3;
						penguin.Blink_Close();
						SPEED = 0;
					}
					else{ slept = true; penguin.Blink_Open(); }
					if (timeInCentisecond % 100 == 0){
						SCORE += penguin.health * 0.1; // SCORE !
						MONEY += penguin.health * 0.1 * 2; // MONAAYYYY !

						// Clock Stuff
						clockSec++;
					}
					if (DontHaveEnoughMoney){
						if (timeInCentisecond % 200 == 0)
							DontHaveEnoughMoney = false;
					}
					DayNightCycle();
				}
				else{
					if (state == 0){
						slept = false;
					}
					if (timeInCentisecond % 100 == 0){
						SCORE += penguin.health * 0.1; // SCORE !
						MONEY += penguin.health * 0.1 * 2; // MONAAYYYY !
						penguin.sleep--; // Sub the penguin sleep amout

						// Clock Stuff
						clockSec++;
					}
					if (rabbid.GetPlayed()){
						if (timeInCentisecond % 50 == 0){
							penguin.fun++;
						}
						if (timeInCentisecond % 2000 == 0){
							rabbid.SetPlayed(false);
							rabbid.ResetRotation(Y_AXIS);
						}
					}
					if (DontHaveEnoughMoney){
						if (timeInCentisecond % 200 == 0)
							DontHaveEnoughMoney = false;
					}
					if (timeInCentisecond % 1000 == 0){
						penguin.age++; // Adds to the penguin age
						MONEY += 50;
						penguin.GrowAge(); // Makes the penguin bigger ("aging")
						for (int i = 0; i < MAX_POOPS; i++){
							if (!poop[i].isPooped()){ // Check if the poop is not already drawn
								poop[i].Bigger(penguin.age); // Makes the penguin's poop bigger
							}
						}
					}
					if (timeInCentisecond % 500 == 0){
						penguin.hunger--;
					}
					if (timeInCentisecond % 1500 == 0){
						penguin.fun--; // Sub the penguin fun
					}
					if (timeInCentisecond % 2000 == 0){
						for (int i = 0; i < MAX_POOPS; i++){ // Looping the poop array
							if (!poop[i].isPooped() && numOfPoop < 5){ // If the poop has not been drawn, makes it available for drawing
								poop[i].MoveCenter(penguin.posX, -0.26, penguin.posZ); // Makes the poop's center the penguin's center
								poop[i].RotateSelf(Y_AXIS, RandNum(0, 360)); // Rotates the poop
								poop[i].Pooping(); // Change the state of the poop (isPooped = True)
								penguin.clean -= 2; // Sub the penguin's clean
								numOfPoop++;
								break;
							}
						}
					}
					if (timeInCentisecond % 200 == 0){
						int rndSick = RandNum(0, 50);
						if (rndSick == 1){
							penguin.sick = true;
						}
						if (penguin.health <= 65){
							rndSick = RandNum(0, 30);
							if (rndSick == 1){
								penguin.sick = true;
							}
						}
						if (penguin.health <= 45){
							rndSick = RandNum(0, 10);
							if (rndSick == 1){
								penguin.sick = true;
							}
						}
					}
					if (penguin.sick){
						if (timeInCentisecond % 400 == 0){
							penguin.sleep--;
							penguin.fun--;
						}
						if (timeInCentisecond % 600 == 0){
							penguin.clean--;
						}
					}
					if (poopClean % 2 == 0 && poopClean != 0){
						if (Poop_Clean()){
							poopClean -= 2;
						}
					}
#pragma region PENGUIN RANDOM MOVEMENT
					double penguinVeloX = SPEED * sin(DegreesToRadians(penguin.GetRotation(Y_AXIS)));
					double penguinVeloZ = SPEED * cos(DegreesToRadians(penguin.GetRotation(Y_AXIS)));
					if (timeInCentisecond % 200 == 0){
						SPEED = RandNum(0, MAXSPEED); // Sets the speed to a random value
						int randomZero = (int)RandNum(0, 8); // Random number for making the penguin rotate randomly
						// Randomly rotates the penguin
						if (randomZero > 1 && randomZero < 4){ penguin.RotateSelf(Y_AXIS, RandNum(10, 20)); }
						if (randomZero > 4 && randomZero < 8){ penguin.RotateSelf(Y_AXIS, -RandNum(10, 20)); }
						if (randomZero == 0) { SPEED = 0; } // Rnadomly sets the penguin's speed to 0
					}
					int rndDirection = RandNum(0, 1), rndRotate = 0; // Random numbers for the pengin random movement (use in the borders)
					if (rndDirection == 0)
						rndRotate = RandNum(45, 180);
					if (rndDirection == 1)
						rndRotate = RandNum(-180, -45);
#pragma endregion
#pragma region BORDERS FOR THE PENGUIN
					if (penguin.GetCenter(X_AXIS) > 0.4){
						penguin.RotateSelf(Y_AXIS, rndRotate);
						penguin.MoveByValue(X_AXIS, -0.01);
					}
					if (penguin.GetCenter(X_AXIS) < -0.4){
						penguin.RotateSelf(Y_AXIS, rndRotate);
						penguin.MoveByValue(X_AXIS, 0.01);
					}
					if (penguin.GetCenter(Z_AXIS) < -2.4){
						penguin.RotateSelf(Y_AXIS, rndRotate);
						penguin.MoveByValue(Z_AXIS, 0.01);
					}
					if (penguin.GetCenter(Z_AXIS) > -1.2){
						penguin.RotateSelf(Y_AXIS, rndRotate);
						penguin.MoveByValue(Z_AXIS, -0.01);
					}
#pragma endregion
					penguin.posX += penguinVeloX; // Moves the penguin Xis (by the velocity of the X axis)
					penguin.posZ += penguinVeloZ; // Moves the penguin Zis (by the velocity of the Z axis)
					DayNightCycle(); // Day night cycle
					penguin.SetPos(); // Setting the penguin position by posX posY posZ
				}
				penguin.health = (2.5 * penguin.fun) + (2.5 * penguin.clean) + (0.25 * penguin.sleep) + (2.5 * penguin.hunger);
				penguin.health = MaxVarValue(penguin.health, 100);
				penguin.health = MinVarValue(penguin.health, 0);
				penguin.sleep = MaxVarValue(penguin.sleep, 100);
				penguin.sleep = MinVarValue(penguin.sleep, 0);
				penguin.clean = MaxVarValue(penguin.clean, 10);
				penguin.clean = MinVarValue(penguin.clean, 0);
				penguin.fun = MaxVarValue(penguin.fun, 10);
				penguin.fun = MinVarValue(penguin.fun, 0);
				penguin.hunger = MaxVarValue(penguin.hunger, 10);
				penguin.hunger = MinVarValue(penguin.hunger, 0);
				SCORE = MaxVarValue(SCORE, 999999);
				MONEY = MaxVarValue(MONEY, 999999);
				MONEY = MinVarValue(MONEY, 0);
			}
#pragma endregion

#pragma region GAME OVER
			if (gameState == GameOver){
				penguin.Blink_Close();
			}
#pragma endregion

			isNext = timeInCentisecond;
		}
	}
}

void CGameHandler::WriteText()
{
	int x_pos = glutGet(GLUT_SCREEN_WIDTH) / 2 - 100; // to be at the center of the screen
	int y_pos = 30;
	int x_left_top = 0, y_left_top = 10;
	char buffer_age[5], buffer_sleep[5], buffer_fun[5], buffer_clean[5],buffer_health[5], buffer_hunger[5], // Penguin Stats
	buffer_score[7], buffer_money[7], // Score && Money
	buffer_timeSec[5], buffer_timeMin[5], // Clock
	buffer_bestscore[5]; // Best score

	if (gameState == Play){
		_itoa_s(penguin.age, buffer_age, 10);
		_itoa_s(penguin.sleep, buffer_sleep, 10);
		_itoa_s(penguin.fun, buffer_fun, 10);
		_itoa_s(penguin.health, buffer_health, 10);
		_itoa_s(penguin.clean, buffer_clean, 10);
		_itoa_s(penguin.hunger, buffer_hunger, 10);

		_itoa_s(SCORE, buffer_score, 10);
		_itoa_s(MONEY, buffer_money, 10);

		// Clock
		if (clockSec >= 60){
			clockMin++;
			clockSec = 0;
		}
		_itoa_s(clockMin, buffer_timeMin, 10);
		_itoa_s(clockSec, buffer_timeSec, 10);
	}

	if (gameState == GameOver){
		_itoa_s(SCORE, buffer_score, 10);
		_itoa_s(MONEY, buffer_money, 10);
		scoreboard.AddScore(name, SCORE);
		_itoa_s(scoreboard.BestScore(), buffer_bestscore, 10);
		_itoa_s(clockMin, buffer_timeMin, 10);
		_itoa_s(clockSec, buffer_timeSec, 10);
	}

	glColor3f(0.7, 0.7, 0.7);  // grey something stuff color
	renderBitmapString(x_left_top, y_left_top, (void *)(int)GLUT_BITMAP_9_BY_15, "MATE: Raise your pet");
	if (gameState == Play){
		renderBitmapString(x_left_top, y_left_top + 14, (void *)(int)GLUT_BITMAP_9_BY_15, "Age: ");
		renderBitmapString(x_left_top + 40, y_left_top + 14, (void *)(int)GLUT_BITMAP_9_BY_15, buffer_age);
		renderBitmapString(x_left_top, y_left_top + 30, (void *)(int)GLUT_BITMAP_9_BY_15, "Sleep: ");
		renderBitmapString(x_left_top + 55, y_left_top + 30, (void *)(int)GLUT_BITMAP_9_BY_15, buffer_sleep);
		renderBitmapString(x_left_top + 90, y_left_top + 30, (void *)(int)GLUT_BITMAP_9_BY_15, "Fun: ");
		renderBitmapString(x_left_top + 130, y_left_top + 30, (void *)(int)GLUT_BITMAP_9_BY_15, buffer_fun);
		renderBitmapString(x_left_top, y_left_top + 45, (void *)(int)GLUT_BITMAP_9_BY_15, "Clean: ");
		renderBitmapString(x_left_top + 55, y_left_top + 45, (void *)(int)GLUT_BITMAP_9_BY_15, buffer_clean);
		renderBitmapString(x_left_top + 90, y_left_top + 45, (void *)(int)GLUT_BITMAP_9_BY_15, "Hunger: ");
		renderBitmapString(x_left_top + 155, y_left_top + 45, (void *)(int)GLUT_BITMAP_9_BY_15, buffer_hunger);
		renderBitmapString(x_left_top, y_left_top + 66, (void *)(int)GLUT_BITMAP_HELVETICA_18, "Health: ");
		renderBitmapString(x_left_top + 60, y_left_top + 66, (void *)(int)GLUT_BITMAP_HELVETICA_18, buffer_health);

		glColor3f(1, 1, 1); // White Color
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - 123, 20, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "Main Menu");
		glColor3f(0.7, 0.7, 0.7);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - 95, 45, (void *)(int)GLUT_BITMAP_HELVETICA_12, "Score: ");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - 52, 45, (void *)(int)GLUT_BITMAP_HELVETICA_12, buffer_score);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - 95, 63, (void *)(int)GLUT_BITMAP_HELVETICA_12, "Money: ");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - 52, 63, (void *)(int)GLUT_BITMAP_HELVETICA_12, buffer_money);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - 94, 80, (void *)(int)GLUT_BITMAP_HELVETICA_12, "Time: ");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - 52, 80, (void *)(int)GLUT_BITMAP_HELVETICA_12, buffer_timeMin);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - 38, 80, (void *)(int)GLUT_BITMAP_HELVETICA_12, ":");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) - 35, 80, (void *)(int)GLUT_BITMAP_HELVETICA_12, buffer_timeSec);

		glColor3f(1, 0, 0);  // red color
		if (penguin.sick)
			renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 20, 20, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "SICK");

		glColor3f(1, 1, 1);  // white color

		// BUY BAR
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 5 - 100, 20, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "SLEEP");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 5, 20, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "CLEAN");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 5 + 115, 20, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "TOY");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 5 + 200, 20, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "CURE");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 5 + 300, 20, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "FOOD");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 5 + 300, 50, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "EAT");

		if (DontHaveEnoughMoney)
			renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 125, 50, (void *)GLUT_BITMAP_HELVETICA_18, "You don't have enough money");
	}

	if (gameState == MainMenu){
		glColor3f(1, 1, 1);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 20, glutGet(GLUT_WINDOW_HEIGHT) / 2 - 25, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "Play");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 20, glutGet(GLUT_WINDOW_HEIGHT) / 2 + 27, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "Exit");
	}

	if (gameState == GameOver){
		glColor3f(1, 0, 0);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 75, glutGet(GLUT_WINDOW_HEIGHT) / 8, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");
		glColor3f(0.9, 0.9, 0.9);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 50, glutGet(GLUT_WINDOW_HEIGHT) / 8 + 20, (void *)(int)GLUT_BITMAP_9_BY_15, "SCORE:");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 + 5, glutGet(GLUT_WINDOW_HEIGHT) / 8 + 20, (void *)(int)GLUT_BITMAP_HELVETICA_18, buffer_score);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 50, glutGet(GLUT_WINDOW_HEIGHT) / 8 + 35, (void *)(int)GLUT_BITMAP_9_BY_15, "TIME:");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 + 6, glutGet(GLUT_WINDOW_HEIGHT) / 8 + 35, (void *)(int)GLUT_BITMAP_HELVETICA_12, buffer_timeMin);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 + 20, glutGet(GLUT_WINDOW_HEIGHT) / 8 + 35, (void *)(int)GLUT_BITMAP_HELVETICA_12, ":");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 + 23, glutGet(GLUT_WINDOW_HEIGHT) / 8 + 35, (void *)(int)GLUT_BITMAP_HELVETICA_12, buffer_timeSec);
		glColor3f(1, 1, 1);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 43, glutGet(GLUT_WINDOW_HEIGHT) / 8 + 65, (void *)(int)GLUT_BITMAP_9_BY_15, "BEST SCORE:");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 23, glutGet(GLUT_WINDOW_HEIGHT) / 8 + 82, (void *)(int)GLUT_BITMAP_HELVETICA_18, StringToCharArray(scoreboard.BestScoreName()));
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 23, glutGet(GLUT_WINDOW_HEIGHT) / 8 + 98, (void *)(int)GLUT_BITMAP_HELVETICA_18, buffer_bestscore);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2  - 33, glutGet(GLUT_WINDOW_HEIGHT) / 4 + 40, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "EXIT");
	}

	if (gameState == EnterName){
		glColor3f(1, 1, 1);
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 145, 60, (void *)(int)GLUT_BITMAP_9_BY_15, "DEL/BACKSPACE for delete the name");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 145, 85, (void *)(int)GLUT_BITMAP_9_BY_15, "ENTER to continue");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 110, glutGet(GLUT_WINDOW_HEIGHT) / 5, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "ENTER YOUR NAME");
		renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 110, glutGet(GLUT_WINDOW_HEIGHT) / 5 + 25, (void *)GLUT_BITMAP_TIMES_ROMAN_24, StringToCharArray(name));
		if (nameSize){
			glColor3f(1, 0, 0);
			renderBitmapString(glutGet(GLUT_WINDOW_WIDTH) / 2 - 80, glutGet(GLUT_WINDOW_HEIGHT) / 5 + 55, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "MAX 16 CHARS");
		}
	}
}

//keys:
void CGameHandler::KeyPressed(char key)
{
	if (gameState == EnterName){
		if (key == 8 || key == 127) name = "";
		else if (key == 13){
			penguin.SetName(StringToCharArray(name));
			gameState = MainMenu;
			nameSize = NULL;
		}
		if (name.size() <= 16){
			name += key;
			nameSize = false;
		}
		else nameSize = true;
	}

	switch (key)
	{
	case ' '://spacebar
		break;
	case 13: //Enter
		break;
	case 27://Esc
		if (gameState == MainMenu) gameState = Play;
		else if (gameState == Play) gameState = MainMenu;
		else if (gameState == Working) exit(0);
		else if (gameState == GameOver) exit(0);
		else if (gameState == EnterName) exit(0);
		break;
	case '1':
		gameState = Play;
		break;
	case '2':
		gameState = MainMenu;
		break;
	case '3':
		SPEED = 0.01;
		break;
	case '4':
		gameState = GameOver;
		break;
	case '5':
		bowl.Eat();
		break;
	case 'd':
		break;
	case 'a':
		break;
	case 'w':
		break;
	case 's':
		break;
	default:
		break;
	}
}

void CGameHandler::SpecialKeyPressed(char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		bowl.RotateSelf(Y_AXIS, 2);
		break;
	case GLUT_KEY_RIGHT:
		bowl.RotateSelf(Y_AXIS, -2);
		break;
	case GLUT_KEY_UP:
		bowl.RotateSelf(X_AXIS, 2);
		break;
	case GLUT_KEY_DOWN:
		bowl.RotateSelf(X_AXIS, -2);
		break;
	default:
		break;
	}
}

void CGameHandler::DayNightCycle(){
	if (state == 0){
		ChangeBackgroundColors(0, MaxVarValue(green, 0.5), MaxVarValue(blue, 0.86));
		if (green <= 0.5) green += 0.00004 * DAYCYCLESPEEDMODIFIER / 2;
		if (blue <= 0.86) blue += 0.00004 * DAYCYCLESPEEDMODIFIER / 2;
	}
	else if (state == 1){
		ChangeBackgroundColors(0, MinVarValue(green, 0), MinVarValue(blue, 0));
		if (green >= 0) green -= 0.0004 * DAYCYCLESPEEDMODIFIER / 2;
		if (blue >= 0) blue -= 0.00004 * DAYCYCLESPEEDMODIFIER / 2;
	}
	sun.RotateSelf(Y_AXIS, 0.0008 * DAYCYCLESPEEDMODIFIER);
	sun.RotateSelf(X_AXIS, 0.0008 * DAYCYCLESPEEDMODIFIER);
	moon.RotateSelf(Y_AXIS, 0.0008 * DAYCYCLESPEEDMODIFIER);
	moon.RotateSelf(X_AXIS, 0.0008 * DAYCYCLESPEEDMODIFIER);

	if (sun.GetCenter().GetCoordinate(Y_AXIS) < 5.3 && sun.GetCenter().GetCoordinate(Y_AXIS) > -3 && state == 0){
		sun.MoveByValue(Y_AXIS, 0.00009 * DAYCYCLESPEEDMODIFIER);
	}
	else{ sun.MoveCenterTo(0, -1, -18); sun.MoveByValue(Y_AXIS, -1); state = 1; }
	
	if (moon.GetCenter().GetCoordinate(Y_AXIS) < 5.3 && moon.GetCenter().GetCoordinate(Y_AXIS) > -3 && state == 1){
		moon.MoveByValue(Y_AXIS, 0.0001 * DAYCYCLESPEEDMODIFIER);
	}
	else { moon.MoveCenterTo(0, -1, -18); moon.MoveByValue(Y_AXIS, -0.5); state = 0; }

}

//getting backgroundColor
float CGameHandler::GetBeckgroundColorR()
{
	return BGColor_R;
}

float CGameHandler::GetBeckgroundColorG()
{
	return BGColor_G;
}

float CGameHandler::GetBeckgroundColorB()
{
	return BGColor_B;
}

//internal procedures:
void CGameHandler::ChangeBackgroundColors(float R, float G, float B)
{
	BGColor_R = R;
	BGColor_G = G;
	BGColor_B = B;
}

bool CGameHandler::Poop_Clean(){
	static int frameCounter = 0;
	static bool finished = false;
	static int poop_index = -1;

	for (int i = 0; i < 10; i++){
		if (poop[i].isPooped()){
			poop_index = i;
			break;
		}
	}

	frameCounter++;
	if (poop_index != -1){
		if (frameCounter < 15){
			poop[poop_index].MoveLayer(Y_AXIS, -0.0009, 2);
		}
		if (frameCounter < 9){
			poop[poop_index].MoveLayer(Y_AXIS, -0.0009, 1);
		}
		if (frameCounter > 15 && frameCounter < 35){
			poop[poop_index].MoveByValue(Y_AXIS, -0.008);
		}
		if (frameCounter > 35 && !finished){
			finished = true;
		}
	}
	if (finished){
		frameCounter = 0;
		poop[poop_index].Clean();
		numOfPoop--;
		finished = false;

		return true;
	}
	return false;
}