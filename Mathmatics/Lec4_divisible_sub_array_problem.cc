#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

ll a[1000005],pre[1000005];

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while(t--) {
		memset(pre,0,sizeof(pre));
		ll n;
		ll sum = 0;
		cin >> n;
		pre[0] = 1;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
			sum %= n;
			sum = (sum + n) % n;
			pre[sum]++;
		}
		ll result = 0;
		for(ll i = 0; i < n; ++i) {
			ll m = pre[i];
			result += (m)*(m-1)/2;
		}
		cout << result << endl;
	}	
	return 0;
}

// Sample Input :

// 2
// 5
// 1 1 1 1 1
// 5
// 5 5 5 5 5

// Sample Output:

// 1
// 15