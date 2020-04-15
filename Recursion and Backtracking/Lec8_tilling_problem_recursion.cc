#include <bits/stdc++.h>
using namespace std;

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
	cin.tie(0);
	cout.tie(0);
	return;
}

ll ways(ll n, ll m) {
	if(n <= 0) return 0;
	if(n < m) return 1;
	ll resV = ways(n-1,m);
	ll resH = ways(n-m,m);
	return resH+resV+1;
}


int main(){
	fastio(true);
	ll t;
	cin >> t;
	while(t--) {
		ll n,m;
		cin >> n >> m;
		cout << ways(n,m) << endl;
	}
	return 0;
}