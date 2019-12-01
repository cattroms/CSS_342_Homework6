#include "gtest/gtest.h"
#include "sudoku.h"

void setTestAnswer(int answer[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			answer[i][j] = 9 * i + j;
		}
	}
}

TEST(sudoku, constructor) {
	int answer[9][9];
	setTestAnswer(answer);

	Sudoku sudoku(answer);
	sudoku.print();
	Sudoku otherSudoku(sudoku);

	// test sudoku object == with array overload
	ASSERT_TRUE(sudoku == answer);
	answer[0][0] = -99;
	ASSERT_FALSE(sudoku == answer);

	setTestAnswer(answer);
	answer[3][3] = -99;
	ASSERT_FALSE(sudoku == answer);

	setTestAnswer(answer);
	answer[8][8] = -99;
	ASSERT_FALSE(sudoku == answer);

	// test sudoku object == overload
	ASSERT_TRUE(sudoku == otherSudoku);
	otherSudoku.set(0, 0, 9);
	ASSERT_FALSE(sudoku == otherSudoku);

	otherSudoku.set(0, 0, sudoku.get(0, 0)); // reset grid
	ASSERT_TRUE(sudoku == otherSudoku);

	otherSudoku.set(3, 3, -99);
	ASSERT_FALSE(sudoku == otherSudoku);

	otherSudoku.set(3, 3, sudoku.get(3, 3)); // reset grid
	ASSERT_TRUE(sudoku == otherSudoku);
	otherSudoku.set(8, 8, -99);
	ASSERT_FALSE(sudoku == otherSudoku);
#ifdef PRINT
	otherSudoku.print();
#endif
}

TEST(sudoku, case1) {
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int answer[9][9] = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                        {5, 2, 9, 1, 3, 4, 7, 6, 8},
                        {4, 8, 7, 6, 2, 9, 5, 3, 1},
                        {2, 6, 3, 4, 1, 5, 9, 8, 7},
                        {9, 7, 4, 8, 6, 3, 1, 2, 5},
                        {8, 5, 1, 7, 9, 2, 6, 4, 3},
                        {1, 3, 8, 9, 4, 7, 2, 5, 6},
                        {6, 9, 2, 3, 5, 1, 8, 7, 4},
                        {7, 4, 5, 2, 8, 6, 3, 1, 9}};

    Sudoku sudoku(grid);
    sudoku.print();
    sudoku.solve();
    ASSERT_TRUE(sudoku==answer);
}

TEST(sudoku, case2) {
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int answer[9][9] = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                        {5, 2, 9, 1, 3, 4, 7, 6, 8},
                        {4, 8, 7, 6, 2, 9, 5, 3, 1},
                        {2, 6, 3, 4, 1, 5, 9, 8, 7},
                        {9, 7, 4, 8, 6, 3, 1, 2, 5},
                        {8, 5, 1, 7, 9, 2, 6, 4, 3},
                        {1, 3, 8, 9, 4, 7, 2, 5, 6},
                        {6, 9, 2, 3, 5, 1, 8, 7, 4},
                        {7, 4, 5, 2, 8, 6, 3, 1, 9}};

    Sudoku sudoku(grid);
    sudoku.solve();
    ASSERT_TRUE(sudoku==answer);
}

// https://www.telegraph.co.uk/news/science/science-news/9359579/Worlds-hardest-sudoku-can-you-crack-it.html
TEST(sudoku, case3) {
    int grid[9][9] = {{8, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 3, 6, 0, 0, 0, 0, 0},
                      {0, 7, 0, 0, 9, 0, 2, 0, 0},
                      {0, 5, 0, 0, 0, 7, 0, 0, 0},
                      {0, 0, 0, 0, 4, 5, 7, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 3, 0},
                      {0, 0, 1, 0, 0, 0, 0, 6, 8},
                      {0, 0, 8, 5, 0, 0, 0, 1, 0},
                      {0, 9, 0, 0, 0, 0, 4, 0, 0}};

    int answer[9][9] = {{8, 1, 2, 7, 5, 3, 6, 4, 9},
                        {9, 4, 3, 6, 8, 2, 1, 7, 5},
                        {6, 7, 5, 4, 9, 1, 2, 8, 3},
                        {1, 5, 4, 2, 3, 7, 8, 9, 6},
                        {3, 6, 9, 8, 4, 5, 7, 2, 1},
                        {2, 8, 7, 1, 6, 9, 5, 3, 4},
                        {5, 2, 1, 9, 7, 4, 3, 6, 8},
                        {4, 3, 8, 5, 2, 6, 9, 1, 7},
                        {7, 9, 6, 3, 1, 8, 4, 5, 2}};

    Sudoku sudoku(grid);
    sudoku.solve();
    ASSERT_TRUE(sudoku==answer);
}

// https://dingo.sbs.arizona.edu/~sandiway/sudoku/examples.html
TEST(sudoku, case4) {
	int grid[9][9] = {{0, 0, 0, 2, 6, 0, 7, 0, 1},
					  {6, 8, 0, 0, 7, 0, 0, 9, 0},
					  {1, 9, 0, 0, 0, 4, 5, 0, 0},
					  {8, 2, 0, 1, 0, 0, 0, 4, 0},
					  {0, 0, 4, 6, 0, 2, 9, 0, 0},
					  {0, 5, 0, 0, 0, 3, 0, 2, 8},
					  {0, 0, 9, 3, 0, 0, 0, 7, 4},
					  {0, 4, 0, 0, 5, 0, 0, 3, 6},
					  {7, 0, 3, 0, 1, 8, 0, 0, 0}};

	int answer[9][9] = {{4, 3, 5, 2, 6, 9, 7, 8, 1},
				 	    {6, 8, 2, 5, 7, 1, 4, 9, 3},
				 	    {1, 9, 7, 8, 3, 4, 5, 6, 2},
					    {8, 2, 6, 1, 9, 5, 3, 4, 7},
					    {3, 7, 4, 6, 8, 2, 9, 1, 5},
					    {9, 5, 1, 7, 4, 3, 6, 2, 8},
				 	    {5, 1, 9, 3, 2, 6, 8, 7, 4},
				        {2, 4, 8, 9, 5, 7, 1, 3, 6},
				   	    {7, 6, 3, 4, 1, 8, 2, 5, 9}};

	Sudoku sudoku(grid);
	sudoku.solve();
	ASSERT_TRUE(sudoku == answer);
}

/* This one has some... funky issue sometimes. This is another "hardest sudoku puzzle ever"
   and it takes a longer time to solve on my machine than the others (Solves in 400ms
   compared to the next longest case3 at 15ms). For whatever reason it 
   was broken when I tried it the first time, hence why I created the test above. Then I
   uncommented it, changed nothing, and it works fine now. If it breaks again, I PROMISE
   it worked on my machine... haha.
*/

// https://freethoughtblogs.com/atrivialknot/2016/08/04/paper-the-chaos-within-sudoku/
TEST(sudoku, case5) {
	int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 1, 2},
					  {0, 0, 0, 0, 0, 0, 0, 0, 3},
					  {0, 0, 2, 3, 0, 0, 4, 0, 0},
					  {0, 0, 1, 8, 0, 0, 0, 0, 5},
					  {0, 6, 0, 0, 7, 0, 8, 0, 0},
					  {0, 0, 0, 0, 0, 9, 0, 0, 0},
					  {0, 0, 8, 5, 0, 0, 0, 0, 0},
					  {9, 0, 0, 0, 4, 0, 5, 0, 0},
					  {4, 7, 0, 0, 0, 6, 0, 0, 0}};

	int answer[9][9] = {{8, 3, 9, 4, 6, 5, 7, 1, 2},
						{1, 4, 6, 7, 8, 2, 9, 5, 3},
						{7, 5, 2, 3, 9, 1, 4, 8, 6},
						{3, 9, 1, 8, 2, 4, 6, 7, 5},
						{5, 6, 4, 1, 7, 3, 8, 2, 9},
						{2, 8, 7, 6, 5, 9, 3, 4, 1},
						{6, 2, 8, 5, 3, 7, 1, 9, 4},
						{9, 1, 3, 2, 4, 8, 5, 6, 7},
						{4, 7, 5, 9, 1, 6, 2, 3, 8}};

	Sudoku sudoku(grid);
	sudoku.solve();
	ASSERT_TRUE(sudoku == answer);
}
