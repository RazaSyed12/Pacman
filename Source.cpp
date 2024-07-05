#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mygraphics.h"

using namespace std;

int score = 0;
bool gameover = false;
bool win = false;
int powercounter = 0;
bool poweractive = false;

void DisplayGameOver();
void draw(int x1, int y1, int x2, int y2);

class Character {
protected:
	int xpos;
	int ypos;
public:
	Character();
	void setPos(int x, int y);  ////////-----------------
	virtual bool checkmove(char direction, int** m);
	void makemove(char direction);
	int getxpos();
	int getypos();
	void setxpos(int x);
	void setypos(int y);
};

Character::Character()
{
	poweractive = false;
}

void Character::setPos(int x, int y) {
	int xpos = x;
	int ypos = y;
}

bool Character::checkmove(char direction, int** m) {
	if (direction == 'w') {
		if (m[xpos][ypos - 1] == 0) {
			return 0;
		}
	}
	else if (direction == 's') {
		if (m[xpos][ypos + 1] == 0) {
			return 0;
		}
	}
	else if (direction == 'd') {
		if (m[xpos + 1][ypos] == 0) {
			return 0;
		}
	}
	else if (direction == 'a') {
		if (m[xpos - 1][ypos] == 0) {
			return 0;
		}
	}
	return 1;
}

void Character::makemove(char direction) {
	if (direction == 'w') {
		ypos--;
	}
	else if (direction == 's') {
		ypos++;
	}
	else if (direction == 'd') {
		xpos++;
	}
	else if (direction == 'a') {
		xpos--;
	}
}

int Character::getxpos() {
	return xpos;
}

int Character::getypos() {
	return ypos;
}

void Character::setxpos(int x) {
	xpos = x;
}

void Character::setypos(int y) {
	ypos = y;
}

class Pacman : public Character {
private:

public:
	Pacman();
	bool checkdeath(char direction, int** m);
};

Pacman::Pacman() {

}

bool Pacman::checkdeath(char direction, int** m) {
	if (direction == 'w') {
		if (m[xpos][ypos - 1] == 4 || m[xpos][ypos - 1] == 6 || m[xpos][ypos - 1] == 7  || m[xpos][ypos - 1] == 9 || m[xpos][ypos - 1] == 10) {
			return 0;
		}
	}
	else if (direction == 's') {
		if (m[xpos][ypos + 1] == 4 || m[xpos][ypos + 1] == 6 || m[xpos][ypos + 1] == 7 || m[xpos][ypos + 1] == 9 || m[xpos][ypos + 1] == 10) {
			return 0;
		}
	}
	else if (direction == 'd') {
		if (m[xpos + 1][ypos] == 4 || m[xpos + 1][ypos] == 6 || m[xpos + 1][ypos] == 7 || m[xpos + 1][ypos] == 9 || m[xpos + 1][ypos] == 10) {
			return 0;
		}
	}
	else if (direction == 'a') {
		if (m[xpos - 1][ypos] == 4 || m[xpos - 1][ypos] == 6 || m[xpos - 1][ypos] == 7 || m[xpos - 1][ypos] == 9 || m[xpos - 1][ypos] == 10) {
			return 0;
		}
	}
	return 1;
}

class Ghost : public Character {
private:

public:
	Ghost();
	char randomdirectiongenerator();
	bool checkdeath(char direction, int** m);
	bool checkmove(char direction, int** m);
};

Ghost::Ghost() {

}

char Ghost::randomdirectiongenerator() {
	int randomnumber = (rand() % 4);
	if (randomnumber == 0) {
		return 'w';
	}
	else if (randomnumber == 1) {
		return 'a';
	}
	else if (randomnumber == 2) {
		return 's';
	}
	else if (randomnumber == 3) {
		return 'd';
	}
}

bool Ghost::checkdeath(char direction, int** m) {
	if (direction == 'w') {
		if (m[xpos][ypos - 1] == 3 || m[xpos][ypos - 1] == 8) {
			return 0;
		}
	}
	else if (direction == 's') {
		if (m[xpos][ypos + 1] == 3 || m[xpos][ypos + 1] == 8) {
			return 0;
		}
	}
	else if (direction == 'd') {
		if (m[xpos + 1][ypos] == 3 || m[xpos + 1][ypos] == 8) {
			return 0;
		}
	}
	else if (direction == 'a') {
		if (m[xpos - 1][ypos] == 3 || m[xpos - 1][ypos] == 8) {
			return 0;
		}
	}
	return 1;
}

bool Ghost::checkmove(char direction, int** m) {
	if (Character::checkmove(direction, m)) {
		if (direction == 'w') {
			if (m[xpos][ypos - 1] == 4 || m[xpos][ypos - 1] == 6 || m[xpos][ypos - 1] == 7 || m[xpos][ypos - 1] == 9 || m[xpos][ypos - 1] == 10) {
				return 0;
			}
		}
		else if (direction == 's') {
			if (m[xpos][ypos + 1] == 4 || m[xpos][ypos + 1] == 6 || m[xpos][ypos + 1] == 7 || m[xpos][ypos + 1] == 9 || m[xpos][ypos + 1] == 10) {
				return 0;
			}
		}
		else if (direction == 'd') {
			if (m[xpos + 1][ypos] == 4 || m[xpos + 1][ypos] == 6 || m[xpos + 1][ypos] == 7 || m[xpos + 1][ypos] == 9 || m[xpos + 1][ypos] == 10) {
				return 0;
			}
		}
		else if (direction == 'a') {
			if (m[xpos - 1][ypos] == 4 || m[xpos - 1][ypos] == 6 || m[xpos - 1][ypos] == 7 || m[xpos - 1][ypos] == 9 || m[xpos - 1][ypos] == 10) {
				return 0;
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}

class Maze {
private:
	int** maze;
	bool** dots;
	Pacman player;
	Ghost* enemy;
	int ghostcount;
	int mazex;
	int mazey;
public:
	Maze();
	void Display();
	void MoveMade(char input);
	bool checkempty();

};


Maze::Maze() {
	//DECLARING THE MAZE 2D ARRAY
	mazex = 15;
	mazey = 20;

	maze = new int* [mazex];
	for (int i = 0; i < 15; i++) {
		maze[i] = new int[mazey];
	}

	dots = new bool* [mazex];
	for (int i = 0; i < 15; i++) {
		dots[i] = new bool[mazey];
	}

	for (int i = 0; i < mazex; i++) {
		for (int j = 0; j < mazey; j++) {
			maze[i][j] = 0;
		}
	}


	//INITIALIZING MAZE PATH

	fstream mazefile;
	mazefile.open("maze.txt");
	string line;
	ghostcount = 0;

	for (int i = 0; i < mazey; i++) {
		getline(mazefile, line);
		for (int j = 0; j < mazex; j++) {
			maze[j][i] = (line.at(j) - 48);
			if (maze[j][i] == 3) {
				player.setxpos(j);
				player.setypos(i);
			}
			if (maze[j][i] == 6) {
				ghostcount++;
			}
		}
	}

	enemy = new Ghost[ghostcount];
	int currentghostcount = 0;

	for (int j = 0; j < mazex; j++) {
		for (int k = 0; k < mazey; k++) {
			if (maze[j][k] == 6) {
				//enemy[i].setPos(j, k);
				enemy[currentghostcount].setxpos(j);
				enemy[currentghostcount].setypos(k);
				currentghostcount++;
			}
		}
	}


	//Dots keeper
	for (int i = 0; i < mazex;i++) {
		for (int j = 0; j < mazey; j++) {
			if (maze[i][j] == 2 || maze[i][j] == 6) {
				dots[i][j] = true;
			}
			else {
				dots[i][j] = false;
			}
		}
	}
}

void Maze::Display() {
	cls();
	system("CLS");
	gotoxy(450, 200);
	cout << "\n\nScore: " << score << endl;
	//\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t
	int x = 0, y = 0;
	for (int i = 100; i < 400; i = i + 20) {
		for (int j = 0; j < 400; j = j + 20) {
			if (maze[x][y] == 0) {										//BLOCK
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 2, j + 2, i + 18, j + 18, 0, 0, 255, 0, 0, 255);
			}
			else if (maze[x][y] == 1) {									//PATH
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
			}
			else if (maze[x][y] == 2) {									//PATH + BEAN
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 8, j + 8, i + 12, j + 12, 255, 0, 0, 255, 0, 0);
			}
			else if (maze[x][y] == 3) {									//PACMAN
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 2, j + 2, i + 18, j + 18, 255, 255, 0, 255, 255, 0);
				drawRectangle(i + 14, j + 6, i + 18, j + 14, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 12, j + 8, i + 14, j + 10, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 6, j + 6, i + 8, j + 8, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 10, j + 10, i + 14, j + 14, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 8, j + 12, i + 10, j + 14, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 16, j + 4, i + 18, j + 6, 0, 0, 0, 0, 0, 0);
			}
			else if (maze[x][y] == 4) {									//GHOST
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 2, j + 2, i + 18, j + 14, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 2, j + 8, i + 4, j + 18, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 6, j + 8, i + 8, j + 17, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 12, j + 8, i + 14, j + 18, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 16, j + 8, i + 18, j + 17, 129, 129, 129, 129, 129, 129);
				drawEllipse(i + 4, j + 6, i + 8, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 12, j + 6, i + 16, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 8, j + 10, i + 12, j + 12, 255, 255, 255, 255, 255, 255);
			}
			else if (maze[x][y] == 5) {									//POWER
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 4, j + 4, i + 10, j + 10, 0, 255, 0, 0, 255, 0);
				drawEllipse(i + 10, j + 4, i + 16, j + 10, 0, 255, 0, 0, 255, 0);
				drawEllipse(i + 7, j + 10, i + 13, j + 16, 0, 255, 0, 0, 255, 0);
			}
			else if (maze[x][y] == 6) {									//GHOST + BEAD
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 2, j + 2, i + 18, j + 14, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 2, j + 8, i + 4, j + 18, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 6, j + 8, i + 8, j + 17, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 12, j + 8, i + 14, j + 18, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 16, j + 8, i + 18, j + 17, 129, 129, 129, 129, 129, 129);
				drawEllipse(i + 4, j + 6, i + 8, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 12, j + 6, i + 16, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 8, j + 10, i + 12, j + 12, 255, 255, 255, 255, 255, 255);
			}
			else if (maze[x][y] == 7) {									//GHOST + POWER
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 2, j + 2, i + 18, j + 14, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 2, j + 8, i + 4, j + 18, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 6, j + 8, i + 8, j + 17, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 12, j + 8, i + 14, j + 18, 129, 129, 129, 129, 129, 129);
				drawRectangle(i + 16, j + 8, i + 18, j + 17, 129, 129, 129, 129, 129, 129);
				drawEllipse(i + 4, j + 6, i + 8, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 12, j + 6, i + 16, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 8, j + 10, i + 12, j + 12, 255, 255, 255, 255, 255, 255);
			}
			else if (maze[x][y] == 8) {									//PACMAN WHEN POWER
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 2, j + 2, i + 18, j + 18, 255, 0, 0, 255, 0, 0);
				drawRectangle(i + 14, j + 6, i + 18, j + 14, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 12, j + 8, i + 14, j + 10, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 6, j + 6, i + 8, j + 8, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 10, j + 10, i + 14, j + 14, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 8, j + 12, i + 10, j + 14, 0, 0, 0, 0, 0, 0);
				drawRectangle(i + 16, j + 4, i + 18, j + 6, 0, 0, 0, 0, 0, 0);
			}
			else if (maze[x][y] == 9) {									//GHOST WHEN POWER
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 2, j + 2, i + 18, j + 14, 100, 255, 255, 100, 255, 255);
				drawRectangle(i + 2, j + 8, i + 4, j + 18, 100, 255, 255, 100, 255, 255);
				drawRectangle(i + 6, j + 8, i + 8, j + 17, 100, 255, 255, 100, 255, 255);
				drawRectangle(i + 12, j + 8, i + 14, j + 18, 100, 255, 255, 100, 255, 255);
				drawRectangle(i + 16, j + 8, i + 18, j + 17, 100, 255, 255, 100, 255, 255);
				drawEllipse(i + 4, j + 6, i + 8, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 12, j + 6, i + 16, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 8, j + 10, i + 12, j + 12, 255, 255, 255, 255, 255, 255);
			}
			else if (maze[x][y] == 10) {									//GHOST WHEN POWER + BEAD
				drawRectangle(i, j, i + 20, j + 20, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 2, j + 2, i + 18, j + 14, 100, 255, 255, 100, 255, 255);
				drawRectangle(i + 2, j + 8, i + 4, j + 18, 100, 255, 255, 100, 255, 255);
				drawRectangle(i + 6, j + 8, i + 8, j + 17, 100, 255, 255, 100, 255, 255);
				drawRectangle(i + 12, j + 8, i + 14, j + 18, 100, 255, 255, 100, 255, 255);
				drawRectangle(i + 16, j + 8, i + 18, j + 17, 100, 255, 255, 100, 255, 255);
				drawEllipse(i + 4, j + 6, i + 8, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 12, j + 6, i + 16, j + 8, 0, 0, 0, 0, 0, 0);
				drawEllipse(i + 8, j + 10, i + 12, j + 12, 255, 255, 255, 255, 255, 255);
			}
			y++;
		}
		x++;
		y = 0;
	}
	//box
	drawRectangle(450, 50, 740, 115, 0, 255, 0, 0, 0, 0);
	//P
	drawLine(465, 65, 465, 100, 255, 0, 0);
	drawLine(465, 65, 480, 65, 255, 0, 0);
	drawLine(480, 65, 480, 80, 255, 0, 0);
	drawLine(480, 80, 465, 80, 255, 0, 0);
	//A
	drawLine(500, 65, 500, 100, 255, 0, 0);
	drawLine(515, 65, 515, 100, 255, 0, 0);
	drawLine(500, 65, 515, 65, 255, 0, 0);
	drawLine(500, 80, 515, 80, 255, 0, 0);
	//C
	drawLine(530, 65, 530, 100, 255, 0, 0);
	drawLine(530, 65, 550, 65, 255, 0, 0);
	drawLine(530, 100, 550, 100, 255, 0, 0);
	//M
	drawLine(565, 65, 565, 100, 255, 0, 0);
	drawLine(565, 65, 580, 80, 255, 0, 0);
	drawLine(580, 80, 595, 65, 255, 0, 0);
	drawLine(595, 65, 595, 100, 255, 0, 0);
	//A
	drawLine(615, 65, 615, 100, 255, 0, 0);
	drawLine(630, 65, 630, 100, 255, 0, 0);
	drawLine(615, 65, 630, 65, 255, 0, 0);
	drawLine(615, 80, 630, 80, 255, 0, 0);
	//N
	drawLine(650, 65, 650, 100, 255, 0, 0);
	drawLine(665, 65, 665, 100, 255, 0, 0);
	drawLine(650, 65, 665, 100, 255, 0, 0);
	//PACMAN
	drawEllipse(680, 60, 725, 105, 255, 255, 0, 255, 255, 0);
	drawRectangle(695, 86, 725, 90, 0, 0, 0, 0, 0, 0);
	drawRectangle(699, 82, 725, 90, 0, 0, 0, 0, 0, 0);
	drawRectangle(703, 78, 725, 90, 0, 0, 0, 0, 0, 0);
	drawRectangle(707, 74, 725, 90, 0, 0, 0, 0, 0, 0);
	drawRectangle(711, 70, 725, 90, 0, 0, 0, 0, 0, 0);
	drawRectangle(715, 67, 725, 90, 0, 0, 0, 0, 0, 0);
	drawEllipse(690, 65, 700, 75, 0, 0, 0, 0, 0, 0);
}

void Maze::MoveMade(char input) {
	if (powercounter == 0) {
		poweractive = false;
		for (int i = 0; i < ghostcount; i++) {
			if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 10) {
				maze[enemy[i].getxpos()][enemy[i].getypos()] = 6;
			}
			else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 9) {
				maze[enemy[i].getxpos()][enemy[i].getypos()] = 4;
			}
		}
	}
	
	if (poweractive == false) {
		if (player.checkmove(input, maze) && (player.checkdeath(input, maze))) {
			maze[player.getxpos()][player.getypos()] = 1;
			player.makemove(input);
			if (maze[player.getxpos()][player.getypos()] == 5) {
				poweractive = true;
				powercounter = 25;
				for (int i = 0; i < ghostcount; i++) {
					if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 6) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 10;
					}
					else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 4) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 9;
					}
				}
				maze[player.getxpos()][player.getypos()] = 8;
				Display();
				delay(10);
			}
			else {
				maze[player.getxpos()][player.getypos()] = 3;
			}
			if (dots[player.getxpos()][player.getypos()] == true) {
				score = score + 5;
			}
			dots[player.getxpos()][player.getypos()] = false;
		}
		else if (player.checkdeath(input, maze) == 0 && poweractive == false) {
			gameover = true;
		}

		if (checkempty()) {
			gameover = true;
			win = true;
		}
		if (poweractive == false) {
			char ghostinput;
			for (int i = 0; i < ghostcount && gameover == false; i++) {
				ghostinput = enemy[i].randomdirectiongenerator();
				if (enemy[i].checkmove(ghostinput, maze) && (enemy[i].checkdeath(ghostinput, maze))) {
					if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 6) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 2;
					}
					else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 4) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 1;
					}
					enemy[i].makemove(ghostinput);
					if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 2) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 6;
					}
					else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 1) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 4;
					}
				}
				else if (enemy[i].checkdeath(ghostinput, maze) == 0) {
					gameover = true;
				}
			}
		}
		else {
			char ghostinput;
			for (int i = 0; i < ghostcount && gameover == false; i++) {
				ghostinput = enemy[i].randomdirectiongenerator();
				if (enemy[i].checkmove(ghostinput, maze) && (enemy[i].checkdeath(ghostinput, maze))) {
					if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 10) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 2;
					}
					else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 9) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 1;
					}
					enemy[i].makemove(ghostinput);
					if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 2) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 10;
					}
					else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 1) {
						maze[enemy[i].getxpos()][enemy[i].getypos()] = 9;
					}
				}
				else if (enemy[i].checkdeath(ghostinput, maze) == 0) {
					int whichghost = -1;
					score = score + 100;
					for (int i = 0; i < ghostcount; i++) {
						if (player.getxpos() == enemy[i].getxpos() && player.getypos() == enemy[i].getypos()) {
							whichghost = i;
						}
					}
					enemy[whichghost].setxpos(6);
					enemy[whichghost].setypos(9);
					maze[6][9] == 4;

					maze[player.getxpos()][player.getypos()] = 8;
				}
			}
			powercounter--;
		}
		
		
	}
	else {
		if (player.checkmove(input, maze) && (player.checkdeath(input, maze))) {
			maze[player.getxpos()][player.getypos()] = 1;
			player.makemove(input);
			maze[player.getxpos()][player.getypos()] = 8;
			if (dots[player.getxpos()][player.getypos()] == true) {
				score = score + 5;
			}
			dots[player.getxpos()][player.getypos()] = false;
		}
		else if (player.checkdeath(input, maze) == 0) {
			maze[player.getxpos()][player.getypos()] = 1;
			player.makemove(input);
			maze[player.getxpos()][player.getypos()] = 8;
			if (dots[player.getxpos()][player.getypos()] == true) {
				score = score + 5;
			}
			dots[player.getxpos()][player.getypos()] = false;
			int whichghost = -1;
			score = score + 100;
			for (int i = 0; i < ghostcount; i++) {
				if (player.getxpos() == enemy[i].getxpos() && player.getypos() == enemy[i].getypos()) {
					whichghost = i;
				}
			}
			enemy[whichghost].setxpos(6);
			enemy[whichghost].setypos(9);
			maze[6][9] == 4;
		}

		if (checkempty()) {
			gameover = true;
			win = true;
		}

		char ghostinput;
		for (int i = 0; i < ghostcount && gameover == false; i++) {
			ghostinput = enemy[i].randomdirectiongenerator();
			if (enemy[i].checkmove(ghostinput, maze) && (enemy[i].checkdeath(ghostinput, maze))) {
				if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 10) {
					maze[enemy[i].getxpos()][enemy[i].getypos()] = 2;
				}
				else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 9) {
					maze[enemy[i].getxpos()][enemy[i].getypos()] = 1;
				}
				enemy[i].makemove(ghostinput);
				if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 2) {
					maze[enemy[i].getxpos()][enemy[i].getypos()] = 10;
				}
				else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 1) {
					maze[enemy[i].getxpos()][enemy[i].getypos()] = 9;
				}
			}
			else if (enemy[i].checkdeath(ghostinput, maze) == 0) {
				int whichghost = -1;
				score = score + 100;
				for (int i = 0; i < ghostcount; i++) {
					if (player.getxpos() == enemy[i].getxpos() && player.getypos() == enemy[i].getypos()) {
						whichghost = i;
					}
				}
				enemy[whichghost].setxpos(6);
				enemy[whichghost].setypos(9);
				maze[6][9] == 4;

				maze[player.getxpos()][player.getypos()] = 8;
			}
		}
		powercounter--;
	}
	return;

	/*
	if (player.checkmove(input, maze) && (player.checkdeath(input, maze) || poweractive)) {
		maze[player.getxpos()][player.getypos()] = 1;
		player.makemove(input);
		if (maze[player.getxpos()][player.getypos()] == 5) {
			poweractive = true;
			powercounter = 50;
			for (int i = 0; i < ghostcount; i++) {
				poweractive = true;
				if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 6) {
					maze[enemy[i].getxpos()][enemy[i].getypos()] = 10;
				}
				else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 4) {
					maze[enemy[i].getxpos()][enemy[i].getypos()] = 9;
				}
			}

			maze[player.getxpos()][player.getypos()] = 8;
		}
		else if (maze[player.getxpos()][player.getypos()] == 9 || maze[player.getxpos()][player.getypos()] == 10) {
			int whichghost = -1;
			score = score + 100;
			for (int i = 0; i < ghostcount; i++) {
				if (player.getxpos() == enemy[i].getxpos() && player.getypos() == enemy[i].getypos()) {
					whichghost = i;
				}
			}
			enemy[whichghost].setxpos(6);
			enemy[whichghost].setypos(9);
			maze[6][9] == 4;

			maze[player.getxpos()][player.getypos()] = 8;
		}
		else if (poweractive == true) {
			maze[player.getxpos()][player.getypos()] = 8;
		}
		else {
			maze[player.getxpos()][player.getypos()] = 3;
		}
		if (dots[player.getxpos()][player.getypos()] == true) {
			score = score + 5;
		}
		dots[player.getxpos()][player.getypos()] = false;
	}
	else if (player.checkdeath(input, maze) == 0 && poweractive == false) {
		gameover = true;
	}

	if (checkempty()) {
		gameover = true;
		win = true;
	}

	char ghostinput;
	for (int i = 0; i < ghostcount && gameover == false; i++) {
		ghostinput = enemy[i].randomdirectiongenerator();
		if (enemy[i].checkmove(ghostinput, maze) && (enemy[i].checkdeath(ghostinput, maze) || poweractive)) {
			if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 6) {
				maze[enemy[i].getxpos()][enemy[i].getypos()] = 2;
			}
			else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 4) {
				maze[enemy[i].getxpos()][enemy[i].getypos()] = 1;
			}
			enemy[i].makemove(ghostinput);
			if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 2) {
				maze[enemy[i].getxpos()][enemy[i].getypos()] = 6;
			}
			else if (maze[enemy[i].getxpos()][enemy[i].getypos()] == 1) {
				maze[enemy[i].getxpos()][enemy[i].getypos()] = 4;
			}
		}
		else if (enemy[i].checkdeath(ghostinput, maze) == 0) {
			gameover = true;
		}
	}
	powercounter--;
	return;
	*/
}

bool Maze::checkempty() {
	bool check = true;
	for (int i = 0; i < mazex && check; i++) {
		for (int j = 0; j < mazey && check; j++) {
			if (dots[i][j] == true) {
				check = false;
			}
		}
	}
	return check;
}

int main() {
	Maze Game;
	Game.Display();
	srand(time(0));
	char input;
	while (gameover == false) {
		input = ' ';
		while (input != 'w' && input != 'a' && input != 's' && input != 'd') {
			input = getKey();
		}

		//char input = getKey();

		if (input == 'w') {
			Game.MoveMade(input);
		}
		else if (input == 'a') {
			Game.MoveMade(input);
		}
		else if (input == 's') {
			Game.MoveMade(input);
		}
		else if (input == 'd') {
			Game.MoveMade(input);
		}

		Game.Display();

	}

	if (win) {
		cls();
		system("CLS");
		cout << "GAME WIN";
	}
	else {
		DisplayGameOver();
	}


	delay(10000);

}

void DisplayGameOver() {
	cls();
	system("CLS");
	draw(1, 1, 9, 3);
	draw(1, 1, 3, 11);
	draw(1, 9, 9, 11);
	draw(7, 5, 9, 11);
	draw(5, 5, 9, 7);

	draw(11, 1, 13, 11);
	draw(11, 1, 19, 3);
	draw(17, 3, 19, 11);
	draw(11, 5, 19, 7);

	


}

void draw(int x1, int y1, int x2, int y2) {
	drawRectangle(x1 * 10, y1 * 10, x2 * 10, y2 * 10, x1 * 10, y1 * 10, x2 * 10, y2 * 10, (x2 + y2) * 10, (x1 + y1) * 10);
	delay(100);
}