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

int binary_search(int *a,int n,int key) {
	int s = 0;
	int e = n-1;
	while(s <= e) {
		int m = (s+e)/2;
		if(a[m] == key) return m;
		// if left segment is sorted.
		else if(a[m] >= a[s]) {
			if(key >= a[s] and key < a[m]) e = m-1;
			else s = m+1;
		}
		// right segment sorted. 
		else {
			if(key > a[m] and key <= a[e]) s = m+1;
			else e = m-1;
		}
	}
	return -1;
} 

int main() {
	fastio(true);
	int n;
	cin >> n;
	int*arr = new int[n]();
	for(int i = 0; i < n; ++i) 
		cin >> arr[i];
	int q;
	cin >> q;
	while(q--) {
		int elementToSearch;
		cin >> elementToSearch;
		cout << elementToSearch << " : " << binary_search(arr,n,elementToSearch) << endl;
	}
	return 0;
}

// Sample Input :

// 10
// 4 5 6 7 8 9 10 1 2 3
// 10
// 0 1 3 7 8 6 5 9 -2 8

// Sample Output :

// 0 : -1
// 1 : 7
// 3 : 9
// 7 : 3
// 8 : 4
// 6 : 2
// 5 : 1
// 9 : 5
// -2 : -1
// 8 : 4