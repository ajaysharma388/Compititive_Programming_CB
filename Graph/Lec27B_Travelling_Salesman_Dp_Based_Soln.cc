#include<bits/stdc++.h>
using namespace std;

#define int long long int

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

int tsp(int cur,int n,int **distaces,int all_visited,int mask,int **dp) {
	if(mask == all_visited) return distaces[cur][0];
	// Traverse on the nbr which are not visited.
	if(dp[mask][cur] != -1) return dp[mask][cur];
	int ans = INT_MAX;
	for(int city = 0; city < n; ++city) {
		// checking if current city is not visited.
		if(!(mask & (1 << city))) {
			int newAns = distaces[cur][city] + tsp(city,n,distaces,all_visited,mask|(1<<city),dp);
			ans = min(ans,newAns);
		}
	}
	return dp[mask][cur] = ans;
}

void solve() {
	int n;
	cin >> n;
	int **distaces = new int*[n];
	for(int i = 0; i < n; ++i) 
		distaces[i] = new int[n];
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < n; ++j) 
			cin >> distaces[i][j];
	int **dp = new int*[1<<n];
	for(int i = 0; i < (1 << n); ++i) 
		dp[i] = new int[n];
	for(int i = 0; i < (1<<n); ++i) 
		for(int j = 0; j < n; ++j) 
			dp[i][j] = -1;
	int all_visited = (1 << n) - 1;
	cout <<"Minimum Weight Hamiltonian Cycle is " << tsp(0,n,distaces,all_visited,1,dp) << "."<< endl;
	for(int i = 0; i < n; ++i) 
		delete[] distaces[i];
	delete[] distaces;
	return;
}

int32_t main() {
	fastio(true);
	int testcases;
	cin >> testcases;
	while(testcases--) {
		solve();
	}
	return 0;
}

// Sample Input :

// 1
// 4
// 0 20 42 25
// 20 0 30 34
// 42 30 0 10
// 25 34 10 0

// Sample Output :

// Minimum Weight Hamiltonian Cycle is 85.