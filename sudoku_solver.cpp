#include<bits/stdc++.h>
using namespace std;
#define unassigned 0 
#define n 9 

// 0 means unassigned cells 
int	grid[n][n] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
					{5, 2, 0, 0, 0, 0, 0, 0, 0}, 
					{0, 8, 7, 0, 0, 0, 0, 3, 1}, 
					{0, 0, 3, 0, 1, 0, 0, 8, 0}, 
					{9, 0, 0, 8, 6, 3, 0, 0, 5}, 
					{0, 5, 0, 0, 9, 0, 6, 0, 0}, 
					{1, 3, 0, 0, 0, 0, 2, 5, 0}, 
					{0, 0, 0, 0, 0, 0, 0, 7, 4}, 
					{0, 0, 5, 2, 0, 6, 3, 0, 0}}; 

bool FindUnassignedLocation(int &row, int &col) 
{ 
	for (row = 0; row < n; row++) 
		for (col = 0; col < n; col++) 
			if (grid[row][col] == 0) 
				return true; 
	return false; 
} 

bool safe_row(int row, int num) 
{ 
	for (int i = 0; i < n; i++) 
		if (grid[row][i] == num) 
			return false; 
	return true; 
} 

bool safe_col(int col, int num) 
{ 
	for (int i = 0; i < n; i++) 
		if (grid[i][col] == num) 
			return false; 
	return true; 
} 

bool safe_box(int boxStartRow, int boxStartCol, int num) 
{ 
	for (int row = 0; row < 3; row++) 
		for (int col = 0; col < 3; col++) 
			if (grid[row + boxStartRow][col + boxStartCol] == num) 
				return false; 
	return true; 
} 


bool isSafe(int row, int col, int num) 
{ 
	return grid[row][col] == 0 && safe_row(row, num) && safe_col(col, num) && safe_box(row - row % 3 ,col - col % 3, num); 
} 

bool SolveSudoku() 
{ 
	int row=0, col=0; 

	// If there is no unassigned location, 
	// we are done 
	if (!FindUnassignedLocation(row, col)) 
	return true;

	// consider digits 1 to 9 
	for (int num = 1; num <= 9; num++) 
	{ 
		// if looks promising 
		if (isSafe(row, col, num)) 
		{ 
			// make tentative assignment 
			grid[row][col] = num; 

			// return, if success, yay! 
			if (SolveSudoku()) 
				return true; 

			// failure, unmake & try again 
			grid[row][col] = 0; 
		} 
	} 
	return false; // this triggers backtracking 
} 


void printGrid() 
{ 
	for (int row = 0; row < n; row++) 
	{ 
	for (int col = 0; col < n; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 

int main() 
{ 
	if (SolveSudoku() == true) 
		printGrid(); 
	else
		cout << "no solution exists"; 

	return 0; 
} 
