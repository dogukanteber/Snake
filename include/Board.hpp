#ifndef BOARD_H
#define BOARD_H

class Board {

	public:
		void draw() const;
		inline int getWidth() const { return width; };
		inline int getHeight() const { return height; };
	private:
		int width = 40;
		int height = 20;
};

#endif // BOARD_H