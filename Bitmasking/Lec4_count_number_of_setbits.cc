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

// this method takes O(LogN) time in the worst case.
int countSetBits(int n) {
	int ans = 0;
	while(n) {
		ans += (n&1);
		n >>= 1;
	}
	return ans;
}

// this method is slightly faster than the above as in worst case.
// it takes K iteration to count the set bits.
// Where, K is the number of set bits.
int countSetBitsFast(int n) {
	int ans = 0;
	while(n) {
		n = n & (n-1);
		ans++;
	}
	return ans;
}

int main() {
	fastio(true);
	int n;
	cin >> n;
	cout << countSetBits(n) << endl;
	cout << countSetBitsFast(n) << endl; 
	cout << __builtin_popcount(n) << endl;
	return 0;
}

// Sample Input :

// 15

// Sample Output :

// 4
// 4
// 4