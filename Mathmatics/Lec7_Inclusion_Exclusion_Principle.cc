#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl '\n';

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

ll solve() {
    ll n, N; cin >> n >> N;
    vector<ll> arr(n,0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll ans = 0;
    ll _n = (1<<n)-1;
    for(ll i = 1; i <= _n ; ++i) {
        ll prd = 1;
        ll count = 0;
        ll cur = i;
        for(ll j = 0; cur > 0; ++j) {
            if(cur&1) {
                count++;
                prd *= arr[j];
            } 
            cur>>=1;
        }
        ll curAns = floor((N-1)/prd);
        ans += (count&1) ? curAns : curAns*(-1);
    }
    return ans;
}

int main() {
    fastio();
    int testcases;
    cin >> testcases;
    for(int task = 1; task <= testcases; task++) {
        cout << "Case #"<<task << " : " << solve() << endl;
    }
    return 0;
}
