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

ll getUpperbound(ll time,ll parata) {
	ll up_Bound = 0;
	for(ll i = 1; i <= parata; ++i) 
		up_Bound += (time*i);
	return up_Bound;
}

ll getCountllime(ll*cook,ll n,ll time) {
	ll ttl_parata = 0;
	for(ll i = 0; i < n; ++i) {
		ll timeElapsed = 0;
		ll curr_Chef_count = 1;
		while(timeElapsed + (cook[i] * curr_Chef_count) <= time) {
			timeElapsed += (cook[i] * curr_Chef_count);
			curr_Chef_count++;
		}
		ttl_parata += curr_Chef_count-1;
	}
	return ttl_parata;
}

ll getOrderTime(ll*cooks,ll n,ll parata) {
	sort(cooks,cooks+n);
	ll s = 1;
	ll e = getUpperbound(cooks[0],parata);
	ll min_time = INT_MAX;
	while(s <= e) {
		ll time = (s+e)/2;
		ll count = getCountllime(cooks,n,time);
		if(parata <= count){
			min_time = time;
			e = time - 1;	
		} 
		else s = time + 1;
	}
	return min_time;
}
 
int main() {
	fastio(true);
	ll testCases;
	cin >> testCases;
	while(testCases--) {
		ll p,n;
		cin >> p >> n;
		ll*cooks = new ll[n]();
		for(ll i = 0; i < n; ++i) 
			cin >> cooks[i]; 
		cout << getOrderTime(cooks,n,p) << endl;
	}
	return 0;
}

// Sample Input :

// 3
// 10
// 4 1 2 3 4
// 8
// 1 1
// 8
// 8 1 1 1 1 1 1 1 1

// Sample Output :

// 12
// 36
// 1