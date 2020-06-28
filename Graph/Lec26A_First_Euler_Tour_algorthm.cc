#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
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

void eulerTourOne(vector<int> *gr, int tm[][2],int cur,int par,int &ts) {
	cout << cur << " ";
	tm[cur][0] = ts;
	for(auto x : gr[cur]) {
		if(x != par) {
			ts++;
			eulerTourOne(gr, tm, x, cur,ts);
			cout << cur << " ";
		}
	}
	tm[cur][1] = ts++;
	return;
}

void solve() {
	int n;
	cin >> n;
	vector<int> gr[n+1];
	int tm[n+1][2];
	for(int i = 0; i <= n; ++i) {
		tm[i][0] = tm[i][1] = 0;
	}
	for(int e = 1; e < n; ++e) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	int ts = 1;
	eulerTourOne(gr,tm,1,0,ts);
	cout << endl;
	for(int i = 1; i <= n; ++i) {
		cout << i << ": " << tm[i][0] << ", " << tm[i][1] << endl;
	}
	return;
}

int32_t main() {
	fastio(true);
	// int t; cin >> t;
	// while(t--) 
	solve();
	return 0;
}


// Sample Input :

// 9
// 1 2
// 2 4
// 2 5
// 2 6
// 1 3
// 3 7
// 7 8
// 7 9

// Sample Output :

// 1 2 4 2 5 2 6 2 1 3 7 8 7 9 7 3 1 
// 1: 1, 17
// 2: 2, 8
// 3: 10, 16
// 4: 3, 3
// 5: 5, 5
// 6: 7, 7
// 7: 11, 15
// 8: 12, 12
// 9: 14, 14