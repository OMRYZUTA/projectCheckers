#pragma once

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// defintion of structs
typedef struct _checkersPos
{
	char row, col;
} checkersPos;

typedef unsigned char Board[BOARD_SIZE][BOARD_SIZE];

typedef unsigned char Player;

typedef struct _SingleSourceMovesTreeNode {
	Board board;
	checkersPos * pos;
	unsigned short total_captures_so_far; // number of captures so far
	struct _SingleSourceMovesTreeNode * next_move[2]; //destination moves
}SingleSourceMovesTreeNode;

typedef struct _SingleSourceMovesTree {
	SingleSourceMovesTreeNode * source;
}SingleSourceMovesTree;

SingleSourceMovesTree * FindSingleSourceMoves(Board board, checkersPos *src);

SingleSourceMovesTree * FindSingleSourceMovesRec(Board board, checkersPos *src);

SingleSourceMovesTreeNode * CreatenewTreeNode(Board board, checkersPos * pos, unsigned short cap_so_far);

void checkMemoryAllocation(void *ptr);

void copyBoard(Board source, Board *dest);