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

int main() {
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			int cur;
			cin >> cur;
			ans ^= cur;
		}
		cout << ans << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 7
// 5 4 4 2 2 8 5
// 7
// 1 2 3 4 3 2 1

// Sample Output :

// 8
// 4