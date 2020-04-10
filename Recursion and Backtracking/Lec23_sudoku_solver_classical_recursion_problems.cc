#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define endl "\n"

void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		#endif	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

void printSudoku(vii &sudoku) {
	for(int r = 0; r < 9; ++r) { 
		for(int c = 0 ; c < 9; ++c) { 
			cout << sudoku[r][c] << " ";
		}
		cout << endl;
	}
}

bool canPlace(vii &sudoku,int i,int j,int num) {
	for(int k = 0; k < 9; ++k) {
		if(sudoku[i][k] == num) return false;
		if(sudoku[k][j] == num) return false;
	}
	int rStart = i/3*3;
	int cStart = j/3*3;
	int rEnd = rStart + 3;
	int cEnd = cStart + 3;
	for(int r = rStart; r < rEnd; ++r) 
		for(int c = cStart ; c < cEnd; ++c) 
			if(sudoku[r][c] == num) return false;
	return true;
}

bool solveSudoku(vii &sudoku,int i,int j) {
	// Base Case If the Solution Exist.
	if(i == 9) {
		printSudoku(sudoku);
		return true;
	}
	// If We Have Processed the Entire Row.
	if(j == 9) return solveSudoku(sudoku,i+1,0);
	// If The current cell is prefilled skip it.
	if(sudoku[i][j] != 0) return solveSudoku(sudoku,i,j+1);
	// We will Try to fill Each digit at current cell.
	for(int curNum = 1; curNum <= 9; ++curNum) {
		if(canPlace(sudoku,i,j,curNum)) {
			sudoku[i][j] = curNum;
			bool res = solveSudoku(sudoku,i,j+1);
			if(res) return true;
			sudoku[i][j] = 0;
		}
	}
	return false;
}

int main() {
	fastio(true);
	vii sudoku(9,vi(9,0));
	for(int i = 0; i < 9; ++i) {
		for(int j = 0 ; j < 9; ++j) {
			cin >> sudoku[i][j];
		}
	}
	bool ans = solveSudoku(sudoku,0,0);
	if(!ans) cout << "No Possible Solution" << endl;
	// printSudoku(sudoku);
	return 0;
}

// Sample Input :

// 7 0 1 0 2 0 8 0 6
// 0 6 0 0 8 0 0 9 0
// 5 0 2 6 0 9 0 1 0
// 9 0 0 2 0 0 7 0 5
// 0 4 5 0 7 6 0 2 0
// 2 0 0 0 5 0 0 0 4
// 1 5 0 4 0 0 0 7 0
// 0 0 8 0 1 0 2 0 0
// 4 0 0 7 0 8 0 5 3

// 5 3 0 0 7 0 0 0 0
// 6 0 0 1 9 5 0 0 0
// 0 9 8 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 8 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 4 1 9 0 0 5
// 0 0 0 0 8 0 0 7 9

// Sample Output :

// 7 9 1 5 2 4 8 3 6 
// 3 6 4 1 8 7 5 9 2 
// 5 8 2 6 3 9 4 1 7 
// 9 1 6 2 4 3 7 8 5 
// 8 4 5 9 7 6 3 2 1 
// 2 3 7 8 5 1 9 6 4 
// 1 5 3 4 9 2 6 7 8 
// 6 7 8 3 1 5 2 4 9 
// 4 2 9 7 6 8 1 5 3 

// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9 