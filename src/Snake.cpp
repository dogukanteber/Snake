#include "../include/Snake.hpp"

void Snake::draw() const {
	for ( std::list<std::pair<int,int> >::const_iterator it = position.cbegin();
			it != position.cend(); ++it )
		mvaddch((*it).first,(*it).second, 'O');
}

bool Snake::isEatItself() const {
	int headY = position.front().first;
	int headX = position.front().second;

	int flag = false;

	auto it = position.cbegin();
	++it;

	for ( ; it != position.cend(); ++it )
		if ( (*it).first == headY && (*it).second == headX )
			flag = true;

	return flag;
}

bool Snake::isHitWall() const {
	return getHeadX() == 0 || getHeadY() == 0
		|| getHeadX() == board.getWidth() || getHeadY() == board.getHeight();
}

void Snake::grow() {
	int posY = position.back().first;
	int posX = position.back().second;

	if ( direction == LEFT )
		position.push_back(std::pair<int,int> (posY, posX+1));
	else if ( direction == RIGHT )
		position.push_back(std::pair<int,int> (posY, posX-1));
	else if ( direction == UP )
		position.push_back(std::pair<int,int> (posY+1, posX));
	else if ( direction == DOWN )
		position.push_back(std::pair<int,int> (posY-1, posX));
}

void Snake::move() {
	if ( direction == LEFT ) {
		moveLeft();
	}
	else if ( direction == RIGHT ) {
		moveRight();
	}
	else if ( direction == UP ) {
		moveUp();
	}
	else if ( direction == DOWN ) {
		moveDown();
	}
}


// ------------- PRIVATE METHODS ------------- //
void Snake::moveLeft() {
	position.pop_back();
	std::pair<int,int> head = position.front();
	head.second--;
	position.push_front(head);
}


void Snake::moveRight() {
	position.pop_back();
	std::pair<int,int> head = position.front();
	head.second++;
	position.push_front(head);
}

void Snake::moveUp() {
	position.pop_back();
	std::pair<int,int> head = position.front();
	head.first--;
	position.push_front(head);
}

void Snake::moveDown() {
	position.pop_back();
	std::pair<int,int> head = position.front();
	head.first++;
	position.push_front(head);
}