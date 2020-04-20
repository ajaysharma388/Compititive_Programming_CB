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
	while(i) {
		ans = max(ans,bit[i]);
		i -= (i&(-i));
	}
	return ans;
}

void update (int*bit,int value,int i,int n) {
	while(i <= n) {
		bit[i] += value;
		i += ( i & (-i));
	}
	return;
}

int* getArray(int n) {
	int *arr = new int[n+1];
	unordered_map<int,int> mp;
	set<int> s;
	for(int i =1; i <= n; ++i) {
		cin >> arr[i];
		s.insert(arr[i]);
	}
	int i = 1;
	for(auto e : s) {
		mp[e] = i++;
	}
	for(int i = 1; i <= n; ++i) {
		arr[i] = mp[arr[i]];
	}
	return arr;
}

int main(){
	fastio(true);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int *arr = getArray(n);
		int *bit = new int[n+1]();
		int ans = 0;
		for(int i = n; i > 0; --i) {
			ans += query(bit,arr[i]-1);
			update(bit,1,arr[i],n);
		}
		cout << ans << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 5
// 100 82 11 99 97
// 5
// 0 -5 -10 -1 -2

// Sample Output :

// 6
// 6