#include "../include/Board.hpp"
#include <ncurses.h>

void Board::draw() const {
	for ( int i=0; i<height; ++i ) {
		mvaddch(i,0,'|');
		mvaddch(i,width,'|');
	}
	for ( int i=0; i<width; ++i ) {
		mvaddch(0,i,'-');
		mvaddch(height,i,'-');
	}
	mvaddch(0,0,'+');
	mvaddch(0,width,'+');
	mvaddch(height,0,'+');
	mvaddch(height,width,'+');
}