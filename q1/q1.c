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
		BuildTree();
		
	}
}


SingleSourceMovesTree BuildTree(Board board, checkersPos *src){
	SingleSourceMovesTree tree;
	tree.source = BuildTreeRec(board, src,Player,0);

	return tree;
}

SingleSourceMovesTreeNode * BuildTreeRec(Board board, checkersPos *src,Player player,unsigned short cap_so_far ){
	int row, col;
	//row and cols starts with 0
	row = src->row - 'A';
	col = src->col - '0' - 1;

	if (rows > 8)
		return NULL;
	if (cols < 0)
		rerturn NULL;
	if (board[row][col] == player)
		return NULL;
	


	SingleSourceMovesTreeNode * newNode;

	newNode = CreatenewTreeNode(board, src, 0);
	if (player == 'B')
	{
		checkersPos* left;
		checkersPos* right;
		left->row = row - 1;
		left->col = col - 1;
		right->row = row - 1;
		right->col = col + 1;

		if (board[left->row][col] != player && board[row][col] != '\0')
		{
			

		}

		newNode->next_move[0] = BuildTreeRec(board, left, player);
		newNode->next_move[1] = BuildTreeRec(board, right, player);

		return newNode;
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