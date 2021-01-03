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

int getWays(int n, vector<int> &dp) {
	// base case.
	if(n <= 2) return n;
	// if already calclated.
	if(dp[n] != -1) return dp[n];
	// else Calculate.
	int result = getWays(n-1, dp) + (n-1) * getWays(n-2, dp);
	return dp[n] = result;
}


int getWaysBU(int n) {
	int dp[n+1];
	memset(dp, -1, n+1);
	for(int i = 0; i <= n; ++i) {
		if(i <= 2) 
			dp[i] = i;
		else 
			dp[i] = dp[i-1] + (i-1) * dp[i-2];
	}
	return dp[n];
}


int32_t main() {
	fastio(true);
	int testCases; cin >> testCases;
	while(testCases--) {
		int n;
		cin >> n;
		vector<int> dp(n+1,-1);
		cout << "No. Of Ways TD : " << getWays(n, dp) << endl;
		cout << "No. Of Ways BU : " << getWaysBU(n) << endl;
	}
	return 0;
}

// Sample Input :

// 3
// 5
// 4
// 3

// Sample Output :

// No. Of Ways TD : 26
// No. Of Ways BU : 26
// No. Of Ways TD : 10
// No. Of Ways BU : 10
// No. Of Ways TD : 4
// No. Of Ways BU : 4