/*==========================
Author : Ajay Sharma
date : 04.05.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define vi(n) vector<long long int>
#define vii(m,n) vector<m, vector<long long int>(n,0)>
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
	cin.tie(NULL);
	cout.tie(NULL);
	return;
}

void printMat(char**mat,int m,int n) {
	for(int i = 0; i < m; ++i) { 
		for(int j = 0; j < n; ++j) 
			cout << mat[i][j];
		cout << endl;
	} 
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void flodFill(char**mat,int m,int n,int i,int j,char ch,char color) {
	// base case if we go outside of matrix bound.
	if(i < 0 or j < 0 or i >= m or j >= n) return;
	// check if we are inside the figure boundary.
	if(mat[i][j] != ch) return;
	// paint the current cell.
	mat[i][j] = color;
	// use four neighbour approach.
	for(int dir = 0; dir < 4; ++dir) {
		flodFill(mat,m,n,i + dx[dir],j + dy[dir],ch,color);
	}
	return;
}

int main() {
	fastio(true);
	int m,n;
	cin >> m >> n;
	char **mat = new char*[m];
	for(int i = 0; i < m; ++i) 
		mat[i] = new char[n];
	for(int i = 0; i < m; ++i) 
		for(int j = 0; j < n; ++j) 
			cin >> mat[i][j];
	flodFill(mat,m,n,7,7,'.','r');
	flodFill(mat,m,n,2,16,'.','b');
	flodFill(mat,m,n,7,0,'.','w');
	printMat(mat,m,n);
	return 0;
}

// Sample Input :

// 15 30
// ..............................
// .............#####............
// .............#...#............
// .....#########...#######......
// ...###......######.....###....
// ...##....................##...
// ..##......................##..
// ..##......................##..
// ..###....................###..
// ....###................###....
// ......###............###......
// ........###........###........
// ..........##########..........
// ..............................
// ..........A.P.P.L.E...........


// Sample Output :

// wwwwwwwwwwwwwwwwwwwwwwwwwwwwww
// wwwwwwwwwwwww#####wwwwwwwwwwww
// wwwwwwwwwwwww#bbb#wwwwwwwwwwww
// wwwww#########bbb#######wwwwww
// www###rrrrrr######rrrrr###wwww
// www##rrrrrrrrrrrrrrrrrrrr##www
// ww##rrrrrrrrrrrrrrrrrrrrrr##ww
// ww##rrrrrrrrrrrrrrrrrrrrrr##ww
// ww###rrrrrrrrrrrrrrrrrrrr###ww
// wwww###rrrrrrrrrrrrrrrr###wwww
// wwwwww###rrrrrrrrrrrr###wwwwww
// wwwwwwww###rrrrrrrr###wwwwwwww
// wwwwwwwwww##########wwwwwwwwww
// wwwwwwwwwwwwwwwwwwwwwwwwwwwwww
// wwwwwwwwwwAwPwPwLwEwwwwwwwwwww