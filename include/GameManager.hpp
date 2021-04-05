#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <ncurses.h>
#include "Board.hpp"
#include "Snake.hpp"
#include "Food.hpp"


class GameManager {
	public:
		void init();
		void render() const;
		void input();
		void gameLoop();
		bool isGameOver();
		void printScore() const;
		void start();
	private:
		int score = 0;
		int speed = 200;
		bool quit = false;
		Board board;
		Snake snake;
		Food food;

		bool isFoodEaten() const;
		void growSnake();
		bool isHitWall() const;
};



#endif // GAMEMANAGER_H