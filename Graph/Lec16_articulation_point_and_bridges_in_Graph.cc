/*==========================
Author : Ajay Sharma
date : 04.05.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define vi(n) vector<long long int>
#define vii(m,n) vector<m, vector<long long int>(n,0)>
#define ll long long int
#define endl "\n"
#define un_mp unordered_map

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

const int N = 100005,M = 22;
std::vector<int> gr[N];
std::set<int> art_p;
std::vector<pair<int,int>> bridges;
int dis[N],low[N],tme;

void dfs(int cur,int par) {
	dis[cur] = low[cur] = tme++;
	int no_childs = 0;
	// Traverse on every child of the current element.
	for(auto child : gr[cur]) {
		// we are using a single array to keep track of distance and visited.
		// if the distance is equal to 0 then we can say that the current nbr 
		// is not visited yet.
		if(dis[child] == 0) {
			dfs(child,cur);
			no_childs += 1;
			low[cur] = min(low[child], low[cur]);
		}
		if(par != 0 and low[child] >= dis[cur]) art_p.insert(cur);
		if(low[child] > dis[cur]) bridges.pb(mp(cur, child));
		else if(child != par) low[cur] = min(dis[child],low[cur]);
	}
	if(par == 0 and no_childs >= 2) art_p.insert(cur);
	return; 
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		gr[x+1].pb(y+1);
		gr[y+1].pb(x+1);
	}
	tme = 1;
	dfs(1,0);
	for(int e : art_p) cout << (e-1) << ", ";
	cout << endl;
}

int32_t main() {
	fastio(true);
	solve();
	return 0;
}

// Sample Input :

// 6 8
// 0 1
// 0 2
// 1 2
// 1 6
// 1 4
// 1 3
// 4 5
// 3 5

// 5 5
// 1 0
// 2 0
// 1 2
// 0 3
// 3 4

// Sample Output :

// 1,

// 0, 3, 