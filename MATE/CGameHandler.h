#pragma once

class CGameHandler
{
public:
	//the beginning
	CGameHandler(){};
	void StartOfGame();
	
	//on each frame:
	void DrawScene();
	void LogicPart();
	void WriteText();
	void KeyPressed(char key);
	void SpecialKeyPressed(char key);

	//getting backgroundColor
	float GetBeckgroundColorR();
	float GetBeckgroundColorG();
	float GetBeckgroundColorB();

private:
	//other procedures
	void ChangeBackgroundColors(float R, float G, float B);

	//internal variables:
	float BGColor_R,BGColor_G,BGColor_B; //BackGround colors.
	int def_font; //determine the font to the text written.
	char* WrongKeyText;

	void DayNightCycle(); // Day night cycle (makes the scene pretty)
	bool Poop_Clean();
};
