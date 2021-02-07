#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree< pair<int,int>, null_type, std::less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update > PDBS;

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

void solve() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    PDBS st;
    int inv_cnt = 0;
    for(int i = 0; i < n; ++i) {
        inv_cnt += (i-st.order_of_key({arr[i],i}));
        st.insert({arr[i],i});
    }
    cout << inv_cnt << endl;
}

int main() {
    fastio(false);
    int testCases; 
    cin >> testCases;
    while(testCases--) {
        solve();
    }
    return 0;
}

// Sample Input :

// 2
// 10
// 12 2 33 45 89 21 33 2 21 13
// 7
// 1 5 2 3 6 4 10

// Sample Output :

// 22
// 4