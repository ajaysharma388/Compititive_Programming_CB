#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void fastio(bool read = true) {
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

int binary_search(int *arr,int n,int k) {
	int s = 0;
	int e = n-1;
	while(s <= e) {
		int m = (s+e)/2;
		if(arr[m] == k) return m;
		else if(arr[m] < k) s = m+1; 
		else e = m-1;
	}
	return -1;
}

int main() {
	fastio(true);
	int n;
	cin >> n;
	int*arr = new int[n]();
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int q,k;
	cin >> q;
	while(q--) {
		cin >> k;
		cout << binary_search(arr,n,k) << endl;
	}
	return 0;
}

// Sample Input : 

// 10
// 1 2 3 4 5 6 7 8 9 10
// 3
// 7 
// 9 
// 11

// Sample Output :

// 6
// 8
// -1