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

void update(int *bit,int i,int val,int n) {
	while(i <= n) {
		bit[i] += val;
		i += (i&(-i));
	}
}

int query(int *bit,int i) {
	int ans = 0;
	while(i) {
		ans += bit[i];
		i -= (i&(-i));
	}
	return ans;
}

int main(){
	fastio(true);
	int testCase;
	cin >> testCase;
	while(testCase--) {
		int n,u;
		cin >> n >> u;
		int *bit = new int[n+1]();
		for(int i = 1; i <= u; ++i) {
			int l, r, val;
			cin >> l >> r >> val;
			update(bit,l+1,val,n);
			update(bit,r+2,(-1)*val,n);
		}
		int q;
		cin >> q;
		while(q--) {
			int p;
			cin >> p;
			cout << query(bit,p+1) << endl;
		}
	}
	return 0;
}

// Sample Input :

// 1
// 5 3
// 0 1 7
// 2 4 6
// 1 3 2
// 3
// 0
// 3
// 4

// Sample Output :

// 7
// 8
// 6