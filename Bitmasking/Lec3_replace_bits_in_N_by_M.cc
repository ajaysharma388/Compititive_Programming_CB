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

int clearRangeItoJ(int num,int i,int j) {
	int once = (~0);
	int a = once << (j+1);
	int b = (1 << i) - 1;
	int mask = a | b;
	return num & mask;
}

int repalceBits(int n,int m,int i,int j) {
	int _n = clearRangeItoJ(n,i,j);
	int ans = _n | (m << i);
	return ans;
}

int main() {
	fastio(true);
	int n,m,i,j;
	cin >> n >> m >> i >> j;
	cout << repalceBits(n,m,i,j) << endl;
	return 0;
}

// Sample Input :

// 15 2 1 3

// Sample Output :

// 5