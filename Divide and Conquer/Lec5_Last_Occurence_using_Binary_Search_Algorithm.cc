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

int last_occurence(int *arr,int n,int k) {
	int s = 0;
	int e = n-1;
	int ans = -1;
	while(s <= e) {
		int m = (s+e)/2;
		if(arr[m] == k) {
			ans = m;
			s = m+1;
		} else if(arr[m] < k) s = m+1; 
		else e = m-1;
	}
	return ans;
}

int main() {
	fastio(true);
	int n;
	cin >> n;
	int*arr = new int[n]();
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int k;
	cin >> k;
	cout << last_occurence(arr,n,k) << endl;
	return 0;
}

// Sample Input :

// 10
// 1 2 2 2 3 3 3 3 4 4 
// 3

// Sample Output :

// 7