#pragma once

#include "q1.h"


typedef struct _SingleSourceMovesListCell{
	checkersPos * position;
	unsigned short captures;
	struct _SingleSourceMovesListCell * next;

}SingleMovesListCell;


typedef struct _SingleSourceMovesList{
	SingleSourceMovesListCell *head;
	SingleSourceMovesListCell *tail;
}SingleSourceMovesList;

SingleSourceMovesList * FindSingleSourceOptimalMove(SingleSourceMovesTree * moves_tree);