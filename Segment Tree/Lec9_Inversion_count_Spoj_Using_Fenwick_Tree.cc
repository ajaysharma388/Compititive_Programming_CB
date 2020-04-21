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

// 1. This Technique will simply fail when the number range is not
//     uniformly spread over.
// 2. And inversion'a also possible for the negative number's but 
// 	   using this solution we will get the runtime error as we don't 
// 	   have any negative index's.
// 3. to avoid that scenario we will use the coordinate compression 
// 	   Technique. 


int main(){
	fastio(true);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int *arr = new int[n+1]();
		int *bit = new int[n+1]();
		for(int i = 1; i <= n; ++i) {
			cin >> arr[i];
			bit[i] = 0;
		}
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

// 1
// 5
// 5 2 1 4 3

// Sample Output :

// 6