#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <utility>
#include "Board.hpp"
#include <ncurses.h>

enum Direction {
	NONE,
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

class Snake {

	public:
		void draw() const;
		void move();
		void grow();
		bool isEatItself() const;
		bool isHitWall() const;
		inline int getHeadY() const { return position.front().first; };
		inline int getHeadX() const { return position.front().second; };
		inline Direction getDirection() const { return direction; };
		inline void setDirection(Direction direction) { this->direction = direction; };
	private:
		std::list<std::pair<int,int> > position = { { 6,5 }, { 6,4 }, { 6,3 }, { 6,2 } };
		Board board;
		Direction direction = RIGHT;

		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
};



#endif // SNAKE_H