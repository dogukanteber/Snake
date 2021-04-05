#ifndef FOOD_H
#define FOOD_H

#include <ncurses.h>

class Food {

	public:
		void createFood(int,int);
		inline void draw() const { mvaddch(y,x,'@'); };
		inline void removeFood() const { mvaddch(y,x,' '); };
		inline int getX() const { return x; };
		inline int getY() const { return y; };
		inline void setX(int x) { this->x = x; };
		inline void setY(int y) { this->y = y; };
	private:
		int x = { 0 };
		int y = { 0 };
		int generateRandomNumber(int,int) const;
};

#endif // FOOD_H