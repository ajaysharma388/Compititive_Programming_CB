#include<iostream>
using namespace std;
typedef long long int ll;

ll power(ll a,ll b) {
	if(b == 0) return 1;
	if(b == 1) return a;
	// calculating the small ans.
	ll ans = power(a,b/2);
	ans *= ans;
	return (b & 1) ? a*ans : ans;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b;
	cin >> a >> b;
	cout << power(a,b) << endl;
	return 0;
}