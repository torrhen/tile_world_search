#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <cstddef>

class Board
{
	private:
		// store board structure
		const static std::size_t width = 4;
		const static std::size_t height = 4;
		
		std::array<std::array<char, width>, height> configuration;

		struct Tile
		{
			int x_position;
			int y_position;
			char id;
		};

		Tile P;
		Tile A;
		Tile B;
		Tile C;

	public:
		Board();
		// copy constructor
		Board(const Board& Board);
		// copy assignment operator
		Board& operator=(const Board& Board);
		// move constructor
		Board(Board&& Board);
		// move assignment operator
		Board& operator=(Board&& Board);
		~Board();

		// remove all tiles
		void clearTiles();

		// add tiles 
		void placeTiles();

		// move the P tile
		void movePUp();
		void movePDown();
		void movePLeft();
		void movePRight();
};

#endif
