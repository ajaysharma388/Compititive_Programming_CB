// Write a program to multiply two number without using *.
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

ll multiply(ll a,ll b) {
	if(b == 0 or a == 0) return 0;
	// possitive
	if(b == -1 and a < 0) return -a;
	// negative
	else if(b == -1 and a > 0) return -a; 
	else if(b == 1 and a > 0) return a;
	else if(b == 1 and a < 0) return a;
	if(a < 0){
		if(b < 0) return multiply(a,b+1) - a;
		else return a + multiply(a , b-1);	
	} else {
		if(b < 0) return -a + multiply(a,b+1);
		else return a + multiply(a , b-1);
	} 
}

int main(){
	fastio();
	ll t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
		cout << a << "*" << b << " = " << multiply(a,b) << endl;
	}
	return 0;
}


// Sample Input :

// 5
// 8 7
// 11 9
// 178 5
// 89 9
// 12 4

// Sample Output :

// 8*7 = 56 | 56
// 11*9 = 99 | 99
// 178*5 = 890 | 890
// 89*9 = 801 | 801
// 12*4 = 48 | 48