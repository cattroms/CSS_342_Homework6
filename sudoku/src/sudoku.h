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
		int row;
		int col;

		if (FindUnassignedLocation(row, col) == false) {
			return true;
		}
			
		for (int num = 1; num <= 9; num++) {		  
			if (isSafe(row, col, num)) {		
				grid[row][col] = num;
				if (solve()) {
					return true;
				}
				grid[row][col] = 0;
			}
		}
		return false; 
    }

	bool FindUnassignedLocation(int& row, int& col ) {
		for (row = 0; row < 9; row++) {
			for (col = 0; col < 9; col++) {
				if (grid[row][col] == 0)
					return true;
			}
		}
		return false;
	}

	bool UsedInRow(int row, int num) {
		for (int col = 0; col < 9; col++) {
			if (grid[row][col] == num) {
				return true;
			}
		}
		return false;
	}

	bool UsedInCol(int col, int num) {
		for (int row = 0; row < 9; row++) {
			if (grid[row][col] == num) {
			return true;
			}
		}
		return false;
	}

	bool UsedInBox(int row, int col, int num) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (grid[i + row][j + col] == num) {
					return true;
				}
			}
		}
		return false;
	}

	bool isSafe(int row, int col, int num) {
		
		if (UsedInRow(row, num) == true) {
			return false;
		}
		if (UsedInCol(col, num) == true) {
			return false;
		}
		if (UsedInBox(row - row % 3, col - col % 3, num) == true) {
			return false;
		}
		if (grid[row][col] == 0) {
			return true;
		}
		
	}
};
