#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUDGE
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
	ll testCase;
	cin >> testCase;
	while(testCase--) {
		ll n,c;
		cin >> n >> c;
		ll*pos = new ll[n]();
		for(ll i = 0; i < n; ++i) 
			cin >> pos[i];
		sort(pos,pos+n);
		cout << findPossibleConf(pos,n,c) << endl;
	}
	return 0;
}

// Sample Input :

// 1
// 5 3
// 1
// 2
// 8
// 4
// 9

// Sample Output :

// 3