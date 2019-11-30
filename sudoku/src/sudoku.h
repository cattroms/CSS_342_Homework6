#include <iostream>
#include <cstring>

class Sudoku {
private:
    int grid[9][9]{};

public:
    explicit Sudoku(int (*grid)[9]) {
        memcpy(this->grid, grid, 9 * 9 * sizeof(int));
    }

    bool operator ==(const int (*otherGrid)[9]) {
        for (int i=0; i<9*9; i++) {
            if (grid[i%3][i/3] != otherGrid[i%3][i/3]) {
                return false;
            }
        }
        return true;
    }

    bool operator ==(const Sudoku & other) {
        for (int i=0; i<9*9; i++) {
            if (grid[i%3][i/3] != other.grid[i%3][i/3]) {
                return false;
            }
        }
        return true;
    }

    int get(int i, int j) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j];
        }

        return -1;
    }

    int set(int i, int j, int val) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j] = val;
        }
        return -1;
    }

    void print() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                printf(" [%d] ", get(i, j));
                if (j == 8) {
                    printf("\n");
                }
            }
        }
    }

    bool solve() {
		/* Masive, massive help from this website: https://www.geeksforgeeks.org/sudoku-backtracking-7/
		Modified version stemming from their ideas.
		*/
		int row;
		int col;

		if (gridIncomplete(row, col) == false) { // If there are no more squares to complete, return true
			return true;
		}
			
		// Tests all possible numbers, 1-9
		for (int num = 1; num <= 9; num++) {		  
			if (isValid(row, col, num) == true) { // In this particular square, is this number valid, if so, fill it in
				grid[row][col] = num;

				if (solve() == true) { // If this breaks nothing else, return true
					return true;
				}

				grid[row][col] = 0; // Otherwise, empty the square and start again
			}
		}
		return false; 
    }

	bool gridIncomplete(int& row, int& col ) { // Checks if there are any more incomplete squares
		for (row = 0; row < 9; row++) {
			for (col = 0; col < 9; col++) {
				if (grid[row][col] == 0) { // If something is incomplete, go there to test things
					return true;
				}
			}
		}
		return false;
	}


	bool isValid(int row, int col, int num) {
		
		// if there is no match in the row, continue
		for (int rowTest = 0; rowTest < 9; rowTest++) {
			if (grid[row][rowTest] == num) {
				return false;
			}
		}
		
		// if there is no match in the column, continue
		for (int colTest = 0; colTest < 9; colTest++) {
			if (grid[colTest][col] == num) {
				return false;
			}
		}

		// if there is no match in this box, continue
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (grid[i + (row - (row % 3))][j + (col - (col % 3))] == num) {
					return false;
				}
			}
		}

		// if the space is not occupied, continue
		if (grid[row][col] != 0) {
			return false;
		}
		
		// it is a valid number
		return true;
	}
};
