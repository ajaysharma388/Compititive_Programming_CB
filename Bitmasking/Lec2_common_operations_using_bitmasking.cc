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

bool isOdd(int num) {
	return (num & 1);
}

int findIthBit(int num,int i) {
	int mask = 1 << i;
	int bit = (mask & num) ? 1 : 0;
	return bit;
}

int setIthBit(int num,int i) {
	int mask = (1 << i);
	num = (num | mask);
	return num;
}

int clearIthBit(int num,int i) {
	int mask = ~(1 << i);
	int ans = num & mask;
	return ans; 
}

int updateBit(int num,int i,int v) {
	int mask = ~(1 << i);
	int cleared_num = (num & mask);
	return (cleared_num | (v << i));
}

int clearIbits(int num,int i) {
	int mask = (~0 << i);
	return (num & mask);
}

int clearRangeItoJ(int num,int i,int j) {
	int once = (~0);
	int a = once << (j+1);
	int b = (1 << i) - 1;
	int mask = a | b;
	return num & mask;
}

int main() {
	fastio(true);
	int n = 15;
	int i = 3;
	(isOdd(9)) ? cout << "Odd No.\n" : cout << "Even No.\n";
	cout << clearIbits(n,i) << endl;  
	cout << clearRangeItoJ(31,1,3) << endl;
	return 0;
}