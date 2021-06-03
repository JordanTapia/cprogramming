#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWSIZE 3
#define COLSIZE 4
#define TARGET  9

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
	printf("%d\n", matrix[0][1]);
	return 0;
}

int main() {

	int matrixSize = ROWSIZE;
	int colsize = COLSIZE;
	int *matrixColsize = &colsize;

	int matrix[3][4] = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	};


	int target = TARGET;
	bool foo = searchMatrix((int**)matrix, matrixSize, matrixColsize, target);
	
	return 0;
}