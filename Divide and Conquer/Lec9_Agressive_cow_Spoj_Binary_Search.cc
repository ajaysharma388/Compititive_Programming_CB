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

bool canPlace(ll *pos,ll n,ll c,ll d) {
	ll cow = 1;
	ll prePos = pos[0];
	for(ll i = 1; i < n; ++i) {
		if(pos[i] - prePos >= d) {
			prePos = pos[i];
			cow += 1;
			if(cow == c) return true;
		}
	}
	return false;
}

ll findPossibleConf(ll *pos,ll n,ll c) {
	ll s = pos[0];
	ll e = pos[n-1] - pos[0];
	ll ans = 0;
	while(s <= e) {
		ll m = (s+e)/2;
		if(canPlace(pos,n,c,m)) {
			ans = m;
			s = m+1;
		} else e = m-1; 
	}
	return ans;
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