#include "../lib/Board.h"

#include <iostream>
#include <array>

// board constructor
Board::Board()
	: P{3, 0, 'P'}, A{2, 0, 'A'}, B{1, 0, 'B'}, C{0, 0, 'C'}
{
	placeTiles();
}

// copy constructor
Board::Board(const Board& Board)
{
	P = {Board.P.x_position, Board.P.y_position, Board.P.id};
	A = {Board.A.x_position, Board.A.y_position, Board.A.id};
	B = {Board.B.x_position, Board.B.y_position, Board.B.id};
	C = {Board.C.x_position, Board.C.y_position, Board.C.id};
	placeTiles();
}

// copy assignment operator 
Board& Board::operator=(const Board& Board)
{
	P = {Board.P.x_position, Board.P.y_position, Board.P.id};
	A = {Board.A.x_position, Board.A.y_position, Board.A.id};
	B = {Board.B.x_position, Board.B.y_position, Board.B.id};
	C = {Board.C.x_position, Board.C.y_position, Board.C.id};
	placeTiles();	

	return *this;
}

// move constructor
Board::Board(Board&& Board)
{
	P = {Board.P.x_position, Board.P.y_position, Board.P.id};
	A = {Board.A.x_position, Board.A.y_position, Board.A.id};
	B = {Board.B.x_position, Board.B.y_position, Board.B.id};
	C = {Board.C.x_position, Board.C.y_position, Board.C.id};
	placeTiles();

	Board.P = {-1, -1, 'P'};
	Board.A = {-1, -1, 'A'};
	Board.B = {-1, -1, 'B'};
	Board.C = {-1, -1, 'C'};
	Board.clearTiles();
}

// move assignment operator
Board& Board::operator=(Board&& Board)
{
	P = {Board.P.x_position, Board.P.y_position, Board.P.id};
	A = {Board.A.x_position, Board.A.y_position, Board.A.id};
	B = {Board.B.x_position, Board.B.y_position, Board.B.id};
	C = {Board.C.x_position, Board.C.y_position, Board.C.id};
	placeTiles();

	Board.P = {-1, -1, 'P'};
	Board.A = {-1, -1, 'A'};
	Board.B = {-1, -1, 'B'};
	Board.C = {-1, -1, 'C'};
	Board.clearTiles();

	return *this;
}

// destructor
Board::~Board()
{

}

// temporarily remove board tiles
void Board::clearTiles()
{
	configuration = 
	{{
		{'X', 'X', 'X', 'X'},
		{'X', 'X', 'X', 'X'},
		{'X', 'X', 'X', 'X'},
		{'X', 'X', 'X', 'X'}
	}};
}

// place the P, A, B and C tiles based on their positions
void Board::placeTiles()
{
	clearTiles();
	configuration[P.x_position][P.y_position] = P.id;
	configuration[A.x_position][A.y_position] = A.id;
	configuration[B.x_position][B.y_position] = B.id;
	configuration[C.x_position][C.y_position] = C.id;
}

void Board::movePUp()
{
	// if P can move upwards...
	if (P.y_position != height - 1)
	{
		// if the new position of P is taken...
		// swap the tile in the new position with P
		if (A.y_position == P.y_position + 1 and A.x_position == P.x_position)
		{
			A.y_position = P.y_position;
		}
		else if (B.y_position == P.y_position + 1 and B.x_position == P.x_position)
		{
			B.y_position = P.y_position;
		}
		else if (C.y_position == P.y_position + 1 and C.x_position == P.x_position)
		{
			C.y_position = P.y_position;
		}
		// move P up
		P.y_position += 1;
		placeTiles();
	}
	// otherwise do nothing
}

void Board::movePDown()
{
	// if P can move downwards...
	if (P.y_position != 0)
	{
		// if the new position of P is taken...
		// swap the tile in the new position with P
		if (A.y_position == P.y_position - 1 and A.x_position == P.x_position)
		{
			A.y_position = P.y_position;
		}
		else if (B.y_position == P.y_position - 1 and B.x_position == P.x_position)
		{
			B.y_position = P.y_position;
		}
		else if (C.y_position == P.y_position - 1 and C.x_position == P.x_position)
		{
			C.y_position = P.y_position;
		}
		// move P down
		P.y_position -= 1;
		placeTiles();
	}
	// otherwise do nothing
}

void Board::movePRight()
{
	// if P can move right...
	if (P.x_position != width - 1)
	{
		if (A.x_position == P.x_position + 1 and A.y_position == P.y_position)
		{	
			A.x_position = P.x_position;
		}
		else if (B.x_position == P.x_position + 1 and B.y_position == P.y_position)
		{
			B.x_position = P.x_position;
		}
		else if (C.x_position == P.x_position + 1 and C.y_position == P.y_position)
		{
			C.x_position = P.x_position;
		}
		// move P right
		P.x_position += 1;
		placeTiles();
	}
	// otherwise do nothing
}

void Board::movePLeft()
{
	// if P can move left...
	if (P.x_position != 0)
	{
		// if the new position of P is taken...
		// swap the tile in the new position with P
		if (A.x_position == P.x_position - 1 and A.y_position == P.y_position)
		{
			A.x_position = P.x_position;
		}
		else if (B.x_position == P.x_position - 1 and B.y_position == P.y_position)
		{
			B.x_position = P.x_position;
		}
		else if (C.x_position == P.x_position - 1 and C.y_position == P.y_position)
		{
			C.x_position = P.x_position;
		}
		// move P left
		P.x_position -= 1;
		placeTiles();
	}
	// otherwise do nothing
}