#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// recursive implementation of the factorial Problem

int factorial(int n) {
	if(n == 0) return 1;
	return n*factorial(n-1);
}

// Bottom Up Approach.

int factorialBUP(int n) {
	int ans = 1;
	for(int i = 1; i <= n; ++i) {
		ans *= i;
	}
	return ans;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << factorial(n) << endl;
	cin >> n;
	cout << factorialBUP(7) << endl;	
	return 0;
}

// Sample Input :

// 8
// 7

// Sample Output :

// 40320
// 5040