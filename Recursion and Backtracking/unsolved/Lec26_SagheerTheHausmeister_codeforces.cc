#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vc vector<char>
#define vcc vector<vector<char>>
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
	cin.tie(0);
	cout.tie(0);
	return;
}

void countTime(vector<vector<bool>>&tower,vector<int>&active,int n,int m,int i,int j) {
	

	int k = j;
	int time = 0;
	// Process Current Floor 
	if(k == 0) {
		while(active[i] and k++ < m+1) {
			if(tower[i][j]) {
				active[i]--;
			}
			time++;
		}
		countTime();
		countTime();
		// recursive call.
	} else {
		while(active[i] and k-- > 0) {
			if(tower[i][j]) {
				active[i]--;
			}
			time++;
		}
		// recursive call.
	}
	return;
}

int main() {
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		vector<int> active(n,0);
		vector<vector<bool>> tower(n,vector<bool>(m+2,0));
		for(int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			int count = 0;
			for(int j = 0; j < m+2; ++j) {
				tower[i][j] = (s[j] == '0') ? 0 : 1;
				if(s[j] == '1') count++;
			}
			active[i] = count;
		}
		countTime(tower,active,n,m);	
	}
	return 0;
}

// Sample Input :

// 3
// 2 2
// 0010
// 0100
// 3 4
// 001000
// 000010
// 000010
// 4 3
// 01110
// 01110
// 01110
// 01110