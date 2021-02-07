#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree< pair<int, int>, null_type, std::less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > PBDS;

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
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i = 0; i < n; i+=1) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i+=1) {
        cin >> b[i];
    }
    vector<int> c(n,0);
    for(int i = 0; i < n; i+=1) {
        c[i] = (a[i] - b[i]);
    }
    PBDS st;
    int ans = 0;
    for(int i = 0; i < n; i+=1) {
        ans += i - st.order_of_key({-c[i],1e5});
        st.insert({c[i],i});
    }
    cout << ans << endl;
    return;
}

int main() {
    fastio();
    int testCases;
    cin >> testCases;
    while(testCases--) {
        solve();
    }
    return 0;
}

// Sample Input : 

// 2
// 5
// 4 8 2 6 2
// 4 5 4 1 3
// 4
// 1 3 2 4
// 1 3 2 4

// Sample Output :

// 7
// 0