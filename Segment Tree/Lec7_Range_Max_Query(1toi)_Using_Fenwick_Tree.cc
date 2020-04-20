#include <bits/stdc++.h>
using namespace std;

#define ll long long int
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
	cin.tie(NULL);
	cout.tie(NULL);
	return;
}

int query(int *bit,int i) {
	int ans = 0;
	while(i > 0) {
		ans = max(ans,bit[i]);
		i -= (i&(-i));
	}
	return ans;
}

void update (int*bit,int value,int i,int n) {
	while(i <= n) {
		bit[i] = max(value,bit[i]);
		i += ( i & (-i));
	}
	return;
}

int main(){
	fastio(true);
	int n;
	cin >> n;
	int *arr = new int[n+1]();
	int *bit = new int[n+1]();
	for(int i = 1; i <= n; ++i) {
		cin >> arr[i];
		update(bit,arr[i],i,n);
	}
	int q;
	cin >> q;
	while(q--) {
		int r;
		cin >> r;
		cout << query(bit,r) << endl;
	}
	return 0;
}

// Sample Input :

// 5
// 1 4 5 6 7
// 3
// 2  
// 4 
// 1 

// Sample Output :

// 4
// 6
// 1