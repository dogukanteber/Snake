#include "../include/Food.hpp"
#include <random>


void Food::createFood(int height, int width) {
	int foodX = generateRandomNumber(1,width-1);
	int foodY = generateRandomNumber(1,height-1);

	setX(foodX);
	setY(foodY);
}


int Food::generateRandomNumber(int beginBound, int endBound) const {
	std::random_device random_device;
	std::mt19937 random_engine(random_device());
	std::uniform_int_distribution<int> distribution_1_100(beginBound, endBound);

	auto const randomNumber = distribution_1_100(random_engine);

	return  randomNumber;
}