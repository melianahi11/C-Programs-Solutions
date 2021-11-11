#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main sudoku grid
int grid[9][9];

//checks for next empty cell, if there is none, it is finished
int isFinished(int *row, int *col) {
    int i;
    int j;
    
    for(i=0;i<9;i++) {
        for(j=0;j<9;j++) {
            if(grid[i][j] == 0) {
                *row = i;
                *col = j;

                return 0;
            }
        }
    }
    return 1;
}

//checks if a value n can be put into a row/col/3x3 square
int valid(int n, int row, int col) {
    int i;
    int j;

    //checks for value in row
    for(i=0;i<9;i++) {
        if(grid[row][i] == n) {
            return 0;
        }
    }

    //checks for value in col
    for(i=0;i<9;i++) {
        if(grid[i][col] == n) {
            return 0;
        }
    }

    int rowStart = (row/3)*3;
    int colStart = (col/3)*3;
    
    //checks for value in square
    for(i=rowStart;i<rowStart+3;i++) {
        for(j=colStart;j<colStart+3;j++) {
            if(grid[i][j]==n) {
                return 0;
            }
        }
    }
    return 1;
}

//main sudoku driver (recursive)
int sudoku() {
    int row;
    int col;
    
    //if finished, end this recursive iteration
    if(isFinished(&row, &col) == 1) {
        return 1;
    }
    
    int i;

    //loop through 1-9 to check possible values
    for(i=1;i<10;i++) {
        //if a valid value for the cell, set sudoku grid and continue this recursive branch
        if(valid(i, row, col)) {
            grid[row][col] = i;
           
	    //continue recursive branch, return 1 on full success
            if(sudoku()) {
                return 1;
            }
            //if failed, reset this cell backtracking all the way to initial state
            grid[row][col]=0;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    //populate sudoku grid
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        return EXIT_FAILURE;
    }
    
    int rowCursor = 0;
    
    char col0;
    char col1;
    char col2;
    char col3;
    char col4;
    char col5;
    char col6;
    char col7;
    char col8;
    
    while(fscanf(fp, "%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", &col0, &col1, &col2, &col3, &col4, &col5, &col6, &col7, &col8) != EOF) {
        grid[rowCursor][0] = (col0 == '-') ? 0 : (col0 - '0');
        grid[rowCursor][1] = (col1 == '-') ? 0 : (col1 - '0');
        grid[rowCursor][2] = (col2 == '-') ? 0 : (col2 - '0');
        grid[rowCursor][3] = (col3 == '-') ? 0 : (col3 - '0');
        grid[rowCursor][4] = (col4 == '-') ? 0 : (col4 - '0');
        grid[rowCursor][5] = (col5 == '-') ? 0 : (col5 - '0');
        grid[rowCursor][6] = (col6 == '-') ? 0 : (col6 - '0');
        grid[rowCursor][7] = (col7 == '-') ? 0 : (col7 - '0');
        grid[rowCursor][8] = (col8 == '-') ? 0 : (col8 - '0');

        rowCursor++;
    }
    
    if (sudoku()) {
        int i;
        int j;
    
        for(i=0;i<9;i++) {
            for(j=0;j<9;j++) {
                printf("%d\t",grid[i][j]);
            }
            printf("\n");
        }
    }
    else {
	printf("no-solution\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
