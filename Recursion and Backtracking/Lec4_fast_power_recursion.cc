#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
#define endl "\n"

void fastio() {
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

// Time Complexity : O(B)
// Space Complexity : O(B)

ll power(ll a,ll b) {
	return (b == 0) ? 1 : a * power(a,b-1);
}

// Time Complexity : O(Log2B)
// Space Complexity : O(Log2B)

ll fastPower(ll a,ll b) {
	if(b == 0) return 1;
	if(b == 1) return a;
	int ans = fastPower(a,b/2);
	ans *= ans;
	return (b & 1) ? a*ans : ans;
} 


int main(){
	fastio();
	ll a, b;
	cin >> a >> b;
	cout << a << "^" << b << " = " << power(a,b) << endl;
	cout << a << "^" << b << " = " << fastPower(a,b) << endl;
	return 0;
}


// Sample Input :

// 8 3

// Sample Output :

// 8^3 = 512