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

// Time Complexity : O(N)
// Space Complexity : O(N)
// Same For both the recurrences.

void printNumbersDec(int n) {
	if(n == 0) return;
	cout << n << " ";
	printNumbersDec(n-1);
}

void printNumbersInc(int n) {
	if(n == 0) return;
	printNumbersInc(n-1);
	cout << n << " ";
}

int main(){
	fastio();
	ll n;
	cin >> n;
	printNumbersInc(n);
	cout << endl;
	printNumbersDec(n);
	return 0;
}


// Sample Input :

// 12

// Sample Output :

// 1 2 3 4 5 6 7 8 9 10 11 12 
// 12 11 10 9 8 7 6 5 4 3 2 1 