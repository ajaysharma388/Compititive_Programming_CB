#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define pii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define pb push_back
#define mp make_pair

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
	int transaction, friends, ans = 0;
	cin >> transaction >> friends;
	int *net = new int[friends]();
	while(transaction--) {
		int a, b, amt;
		cin >> a >> b >> amt;
		net[a] -= amt;
		net[b] += amt;
	}
	// now creating a multimaps.
	multiset<pii> m;
	for(int f = 0; f < friends; ++f)
		if(net[f] != 0) m.insert(mp(net[f],f));
	while(!m.empty()) {
		auto low = m.begin();
		auto hi = prev(m.end());
		pii debiter = *low;
		pii crediter = *hi;
		m.erase(low);
		m.erase(hi);
		int settelmentAmt = min(abs(debiter.F),abs(crediter.F));
		ans += 1;
		// settel the amount.
		debiter.F += settelmentAmt;
		crediter.F -= settelmentAmt;
		cout << debiter.S << " Paid " << settelmentAmt << " to " << crediter.S << "." << endl;
		if(debiter.F != 0) m.insert(debiter);
		if(crediter.F != 0) m.insert(crediter);
	}
	cout << "number of transactions are " << ans << "."<< endl;
	return;
}

int32_t main() {
	fastio(true);
	solve();
	return 0;
}

// Sample Input :

// 3 3
// 0 1 50
// 1 2 30
// 2 0 10

// Sample Output :

// 0 Paid 20 to 2.
// 0 Paid 20 to 1.
// number of transactions are 2.