#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
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
	cin.tie(0);
	cout.tie(0);
	return;
}

int = 4;

// 4*4

int waysSpoj(int k) {
	if(k <= 0) return 0;
	if(k == 2) return 5;
	if(k == n) return 20; 
	int res = 3 + waysSpoj(k-2);
	res += 2 + waysSpoj(k-2);
	return res;
}

int ways(int k) {
	if(k < n) return 1;
	if(k == n) return 2;
	int res = ways(k-n);
	res += ways(k-1);
	return res;
}

int main(){
	fastio(true);
	int t,k;
	cin >> t;
	while(t--) {
		cin >> k;
		cout << waysSpoj(k) << endl;
	}
	return 0;
}