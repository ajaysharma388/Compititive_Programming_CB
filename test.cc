/******************************************
* AUTHOR : AJAY SHARMA                    *
* NICK : ajaysharma388                    *
******************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define N 100005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second


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

int Factorial(int n) {
	if(n == 0) return 1;
	return Factorial(n-1)*n;
}

int32_t main() {
	fastio(true);
	int testCases;
	cin >> testCases;
	while(testCases--) {
		int n;
		cin >> n;
		cout << "Factorial of " << n << " is " << Factorial(n) << endl;
	}
	return 0;
}