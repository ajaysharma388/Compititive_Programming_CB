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

int getMaxprofit(vector<int> &stockPrice, int s, int e) {
	// if we do not have the valid search space.
	if(s >= e) return 0;
	int maxProfit = 0;
	// try for every possible case.
	for(int i = s; i < e; ++i) {
		for(int j = i+1; j <= e; ++j) {
			if(stockPrice[j] > stockPrice[i]) {
				int curProfit = stockPrice[j] - stockPrice[i];
				curProfit += getMaxprofit(stockPrice,s, i-1);
				curProfit += getMaxprofit(stockPrice,j+1, e);
				maxProfit = max(maxProfit, curProfit);
			}
		}
	}
	return maxProfit;
}


int32_t main() {
	fastio(true);
	int testcases;
	cin >> testcases;
	for(int test = 1; test <= testcases; ++test) {
		int n;
		cin >> n;
		vector<int> stockPrice(n, 0);
		for(int i = 0; i < n; ++i) 
			cin >> stockPrice[i];
		cout << "Case #" << test << ": " << getMaxprofit(stockPrice, 0, n-1) << endl;
	}
	return 0;
}

// Sample Input :

// 4
// 8
// 12 14 17 10 14 13 12 15
// 7
// 10 18 26 31 4 53 79
// 7
// 100 180 260 310 40 535 695
// 6
// 10 9 8 7 6 5

// Sample Output :

// Case #1: 12
// Case #2: 96
// Case #3: 865
// Case #4: 0