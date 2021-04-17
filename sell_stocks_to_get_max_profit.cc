/**********************************************
* AUTHOR : AJAY SHARMA, ajay2201@gmail.com    *
* Github Username : ajaysharma388             *
***********************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define N 100005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second


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


void solve() {
	int n;
	cin >> n;
	vector<int> stockPrice(n, 0);
	vector<int> result(n, 1);
	for(int i = 0; i < n; ++i) 
		cin >> stockPrice[i];
	stack<int> span;
	span.push(0);
	for(int i = 1; i < n; ++i) {
		while(!span.empty() and stockPrice[span.top()] <= stockPrice[i]) {
			int t = span.top(); span.pop();
			result[i] += result[t];
		}
		span.push(i);
	}
	for(int i = 0; i < n; ++i) {
		cout << result[i] << ", ";
	}
	cout << endl;
}


int32_t main() {
	fastio(true);
	int testcases;
	cin >> testcases;
	for(int test = 1; test <= testcases; ++test) {
		cout << "Case #" << test << ": ";
		solve();
	}
	return 0;
}

// Sample Input :

// 2
// 7
// 100 80 60 70 60 75 85 
// 8
// 1 5 2 3 7 6 4 5 

// Sample Output :

// Case #1: 1, 1, 1, 2, 1, 4, 6, 
// Case #2: 1, 2, 1, 2, 5, 1, 1, 2, 