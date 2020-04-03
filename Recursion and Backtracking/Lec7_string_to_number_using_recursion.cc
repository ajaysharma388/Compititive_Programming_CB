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

// Time Complexity : O(N)
// Space Complexity : O(N)
// where N is the Length of Input String.

int convert(string input,int i) {
	if(i == input.length() - 1) {
		return (input[i] - '0');
	}
	int smallAns = convert(input,i+1);
	int res = 0;
	int p = 1;
	while(smallAns) {
		res += (smallAns%10)*p;
		smallAns/=10;
		p*=10;
	}
	return res += (input[i]-'0')*p;
}


int main(){
	fastio();
	ll t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int res = convert(s,0);
		cout << res << endl;
	}
	return 0;
}


// Sample Input :

// 2
// 1712
// 32156

// Sample Output :

// 1712
// 32156