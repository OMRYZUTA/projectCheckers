#include "q1.h";

SingleSourceMovesTree * FindSingleSourceMoves(Board board, checkersPos *src){
	int rows, cols;
	//row and cols starts with 0
	rows = src->row - 'A';
	cols = src->col - '0'-1;
	if (board[rows][cols] == '\0') {
		return NULL;
	}
	else {
		FindTree();
		
	}
}

//create new treeNode

SingleSourceMovesTreeNode * CreatenewTreeNode(Board board1, checkersPos * pos, unsigned short cap_so_far) {
	SingleSourceMovesTreeNode * newTreeNode = (SingleSourceMovesTreeNode *)malloc(sizeof(SingleSourceMovesTreeNode));
	checkMemoryAllocation(newTreeNode);
	newTreeNode->pos = pos;
	copyBoard(board1, &newTreeNode->board);
	newTreeNode->total_captures_so_far = cap_so_far;
	newTreeNode->next_move[0] = NULL; //left
	newTreeNode->next_move[1] = NULL; //right
	return newTreeNode;
}

// to check the dynamic allocation
void checkMemoryAllocation(void *ptr) {
	if (ptr == NULL) {
		puts(" memory allocation error! ");
		exit(1);
	}
}

//this function copy the given boards
void copyBoard(Board source, Board *dest) {
	int i,j;
	for ( i = 0; i < BOARD_SIZE; i++) {
		for ( j = 0; j < BOARD_SIZE; j++) {
			*(dest)[i][j] = source[i][j];
		}
	}
}