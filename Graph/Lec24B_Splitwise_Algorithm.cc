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
	unordered_map<string,int> net;
	while(transaction--) {
		string a, b;
		int amt;
		cin >> a >> b >> amt;
		if(net.count(a) == 0) net[a] = 0;
		if (net.count(b) == 0) net[b] = 0;
		net[a] -= amt;
		net[b] += amt;
	}
	// now creating a multimaps.
	multiset<pair<int,string>> m;
	for(auto person : net)
		if(person.S != 0) 
			m.insert(mp(person.S,person.F));
	while(!m.empty()) {
		auto low = m.begin();
		auto hi = prev(m.end());
		pair<int,string> debiter = *low;
		pair<int,string> crediter = *hi;
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
// Ajay Vijay 50
// Vijay Deepak 30
// Deepak Ajay 10

// Sample Output :

// Ajay Paid 20 to Vijay.
// Ajay Paid 20 to Deepak.
// number of transactions are 2.