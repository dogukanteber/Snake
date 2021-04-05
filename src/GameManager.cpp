#include "../include/GameManager.hpp"

bool GameManager::isFoodEaten() const {
	return food.getX() == snake.getHeadX() && food.getY() == snake.getHeadY();
}

void GameManager::growSnake() {
	if ( isFoodEaten() ) {
		food.removeFood();
		food.createFood(board.getHeight(), board.getWidth());
		++score;
		snake.grow();
	}
}

void GameManager::init() {
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	timeout(speed);
}

void GameManager::printScore() const {
	mvprintw(board.getHeight()+2, 0, "%s : %d", "Score", score);
}


void GameManager::render() const {
	clear();
	refresh();
	board.draw();
	snake.draw();
	food.draw();
	printScore();
}

void GameManager::input() {
	int ch = getch();

	switch (ch) {
		case 'w':
			if ( snake.getDirection() != DOWN )
				snake.setDirection(UP);
			break;
		case 's':
			if ( snake.getDirection() != UP )
				snake.setDirection(DOWN);
			break;
		case 'd':
			if ( snake.getDirection() != LEFT )
				snake.setDirection(RIGHT);
			break;
		case 'a':
			if ( snake.getDirection() != RIGHT )
				snake.setDirection(LEFT);
			break;
		case 'q':
			quit = true;
			break;
		default:
			break;
	}
}

bool GameManager::isGameOver() {
	return snake.isHitWall() || snake.isEatItself();
}

void GameManager::gameLoop() {
	while ( !isGameOver() && !quit ) {
		render();
		input();
		snake.move();
		growSnake();
	}
}

void GameManager::start() {
	init();
	food.createFood(board.getHeight(), board.getWidth());
	gameLoop();
	endwin();
}