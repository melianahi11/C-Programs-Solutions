#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main sudoku grid
int grid[9][9];

int unfinished[81][2]; //list of row/col pairs that are empty with state 0
int unfinishedCount = 0; //total count of empty cells 
int completedCount = 0; // total count of empty cells that have been filled 

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

//main sudoku driver
int sudoku() {
    int stuck = 1; //-1 if the entire grid had been passed through with no cell filled in during the pass
    
    int possibilities = 0; //counts the number of possible values for a cell
    int possibility;
    
    int row;
    int col;
    
    //keeps running until we are stuck
    while(stuck != -1) {
        stuck = -1;
    
	    //loop through the list of empty cells in unfinished[][]
	    for(int i=0;i<unfinishedCount;i++) {
            if(unfinished[i][0] != -1 || unfinished[i][1] != -1) {
                row = unfinished[i][0];
                col = unfinished[i][1];
               
		    //loop through 1-9 to check possible values
		    for(int j=1;j<10;j++) {
                   	
			 //if a valid value for cell, record and keep checking for more
			 if(valid(j, row, col)) {
                        possibility = j;
                        possibilities++;
                    }
                }
                  //if only one possible value, fill it in, mark row/col pair as finished, set to not stuck to continue looping
		  if(possibilities == 1) {
                    grid[row][col] = possibility;
                    
                    unfinished[i][0] = -1;
                    unfinished[i][1] = -1;
                    
                    stuck = 1;
                    completedCount++;
                }
                possibilities = 0;
            }
        }
      	    //if all are completed, exit success
	    if(completedCount == unfinishedCount) {
            return 1;
        }
    }
    //if we got stuck, exit failure
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
    //prefill unfinished[] with -1
    for(int i=0; i<81;i++) {
        for(int j=0; j<2;j++) {
            unfinished[i][j] = -1;
        }
    }
    //populate unfinished[] with row/col pairs
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            if (grid[i][j] == 0) {
                unfinished[unfinishedCount][0]=i;
                unfinished[unfinishedCount][1]=j;
                unfinishedCount++;
            }
        }
    }
    //run sudoku and print out solution if successful
    if (sudoku()) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
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
