#include <bits/stdc++.h>
using namespace std;

#define ll long long int
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

bool ratInMaze(char**grid,char**soln,int i,int j,int m,int n,ll &possibleRoutes) {
	// Base Case.
	if(i == m and j == n) {
		possibleRoutes++;
		soln[i][j] = '1';
		for(int i = 0; i <= m; ++i) {
			for(int j = 0; j <= n; ++j) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}
	// If the rat goes out of the maze.
	if(i > m or j > n) return false;
	// If the current cell is blocked.
	if(grid[i][j] == 'X') return false;
	// Assume Solution Exist From current cell.
	soln[i][j] = '1';
	// Recursive Case as Rat Can either move forward
	// and in the downward direction.
	bool rightSuccess = ratInMaze(grid,soln,i,j+1,m,n,possibleRoutes);
	bool downSuccess = ratInMaze(grid,soln,i+1,j,m,n,possibleRoutes);
	// Backtraking.
	soln[i][j] = '0';
	if(rightSuccess or downSuccess) return true;
	return false;
} 

int main() {
	fastio(true);
	int m,n;
	cin >> m >> n;
	char**grid = new char*[m];
	for(int i = 0; i < m; ++i) {
		grid[i] = new char[n];
	}
	char**soln = new char*[m];
	for(int i = 0; i < m; ++i) {
		soln[i] = new char[n];
	}
	ll possibleRoutes = 0;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> grid[i][j];
			soln[i][j] = '0';
		}
	}
	ratInMaze(grid,soln,0,0,m-1,n-1,possibleRoutes);
	if(possibleRoutes == 0) {
		cout << "There Is No route Available.";
	} else {
		cout << "The No. of Available Routes are " << possibleRoutes << ".";
	}
	return 0;
}

// Sample Input :

// 4 4
// 0 0 0 0
// 0 0 X 0
// 0 0 0 X
// 0 X 0 0

// Sample Output :

// 1 1 0 0 
// 0 1 0 0 
// 0 1 1 0 
// 0 0 1 1 

// 1 0 0 0 
// 1 1 0 0 
// 0 1 1 0 
// 0 0 1 1 

// 1 0 0 0 
// 1 0 0 0 
// 1 1 1 0 
// 0 0 1 1 

// The No. of Available Routes are 3.