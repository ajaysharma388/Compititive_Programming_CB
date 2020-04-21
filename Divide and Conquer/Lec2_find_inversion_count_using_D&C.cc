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
	cin.tie(NULL);
	cout.tie(NULL);
	return;
}


ll calInvAndMerge(ll *arr,ll s,ll e) {
	// calculating the mid.
	ll m = (s+e)/2;
	ll i = s;
	ll k = 0;
	ll j = m+1;
	ll ans = 0;
	// Allocating space for string temprarly.
	ll *temp = new ll[e-s+1]();
	// we will keep running this loop until we have 
	// element's in the both halfs.
	while(i <= m and j <= e)
		if(arr[i] > arr[j]){
			ans += (m-i+1); 
			temp[k++] = arr[j++];
		} else temp[k++] = arr[i++];
	// right region has exausted.
	while(i <= m) temp[k++] = arr[i++];
	// left region has exausted.
	while(j <= e) temp[k++] = arr[j++];
	// restoring the data into array.
	for(ll i = 0; i <= e-s; ++i) 
		arr[s+i] = temp[i];
	delete []temp;
	return ans;
}


ll countInversions(ll*arr,ll s,ll e) {
	// We cannot have any inversion's.
	if(s >= e) return 0;
	// calculating the mid point to divide the segment.
	ll m = (s+e)/2;
	// calculating the number of inversion's from left.
	ll x = countInversions(arr,s,m);
	// calculating the number of inversion's from right.
	ll y = countInversions(arr,m+1,e);
	// calculating the number of cross inversions.
	ll z = calInvAndMerge(arr,s,e);
	return (x+y+z);
}

int main() {
	fastio(true);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll*arr = new ll[n]();
		for(ll i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << countInversions(arr,0,n-1) << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 3
// 3 1 2
// 5
// 2 3 8 6 1

// Sample Output :

// 2
// 5