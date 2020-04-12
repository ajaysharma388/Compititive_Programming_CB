#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
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

void printBoard(char**grid,int n){
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	return;
}

bool canPlace(char**grid,int i,int j,int n) {
	for(int r = i; r >= 0; --r)
		if(grid[r][j] == 'Q') return false;
	int c = j;
	for(int r = i-1; r >= 0 and c >= 0; --r) 
		if(grid[r][--c] == 'Q') return false;
	c = j;
	for(int r = i-1; r >= 0 and c < n; --r) 
		if(grid[r][++c] == 'Q') return false;
	return true;
}

bool placesQueens(char**grid,int i,int n,int &result) {
	// Base Case.
	if(i == n) {
		// printBoard(grid,n);
		result++;
		return false;		
	}
	// Recursive case.
	for(int j = 0; j < n; ++j) {
		if(canPlace(grid,i,j,n)) {
			grid[i][j] = 'Q';
			bool res = placesQueens(grid,i+1,n,result);
			if(res) return true;
			// backtracking step when solution not possible.
			grid[i][j] = '_';
		}
	}
	// If we have reached the end of this code then It means
	// We cannot place the queen in this row.
	return false;
}

int main() {
	fastio(true);
	int n;
	cin >> n;
	char**grid = new char*[n];
	for(int i = 0; i < n; ++i) {
		grid[i] = new char[n]();
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			grid[i][j] = '_';
		}
	}
	int result = 0;
	placesQueens(grid,0,n,result);
	cout << result << endl;
	return 0;
}

// Sample Input :

// 4

// Sample Output :

// _ Q _ _ 
// _ _ _ Q 
// Q _ _ _ 
// _ _ Q _ 

// _ _ Q _ 
// Q _ _ _ 
// _ _ _ Q 
// _ Q _ _ 