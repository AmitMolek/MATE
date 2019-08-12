#include "Scoreboard.h"

#pragma region CONSTRUCTOR
Scoreboard::Scoreboard(){

}
#pragma endregion

#pragma region ACTIONS
void Scoreboard::AddScore(std::string name, int score){
	if (score > BestScore()){
		ofstream scoreWrite("scoreboard.txt");
		if (scoreWrite.is_open()){
			scoreWrite << name << endl << score << endl;
		}
		scoreWrite.close();
	}
}
int Scoreboard::BestScore(){
	ifstream scoreRead;
	string line;
	int lineCount = 0;
	scoreRead.open("scoreboard.txt");
	if (scoreRead.is_open()){
		while (getline(scoreRead, line)){
			if (lineCount == 1){
				return atoi(StringToCharArray(line));
			}
			lineCount++;
		}
	}
	scoreRead.close();
	return 0;
}
std::string Scoreboard::BestScoreName(){
	ifstream scoreRead;
	string line;
	int lineCount = 0;
	scoreRead.open("scoreboard.txt");
	if (scoreRead.is_open()){
		while (getline(scoreRead, line)){
			if (lineCount == 0){
				return line;
			}
			lineCount++;
		}
	}
	scoreRead.close();
	return "none";
}
#pragma endregion