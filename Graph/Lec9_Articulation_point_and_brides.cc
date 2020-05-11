/*==========================
Author : Ajay Sharma
date : 04.05.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"

void fastio(bool read = false)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if(read)
    {
#ifndef ONLINE_JUGDE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
#endif
    }
    return;
}

const int N = 100005, M = 22;
vector<int> gr[N];
set<int> art_p;
vector<pair<int,int>> bridge;


int disc[N], low[N], tme;

void dfs(int cur,int par) {
	disc[cur] = low[cur] = tme++;
	int no_child = 0;
	for(auto child : gr[cur]) {
		// if the child is not visited.
		if(disc[child] == 0) {
			dfs(child,cur);
			no_child += 1;
			low[cur] = min(low[cur],low[child]);
			// calculating articulation point.
			if(par != 0 and low[child] >= disc[cur]) art_p.insert(cur);
			// condition for being the bridge.
			if(low[child] > disc[cur]) bridge.pb({cur,child});
		} else if(child != par) {
			// back edge and cycle found.
			low[cur] = min(low[cur],disc[child]);
		}
	}
	// seperate case for root to be an articulation point.
	if(par == 0 and no_child >= 2) {
		art_p.insert(cur);
	}
	return;
}

void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    for(i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    tme = 1;
    dfs(1, 0);
    for(auto x : art_p) cout << x << " ";
    cout << endl;
}

int32_t main()
{
    fastio(true);
    // int t;cin >> t;while(t--) 
    {
    	solve();
    }

    return 0;
}

// Sample Input :

// 5 5
// 1 2
// 2 3
// 3 1
// 3 4
// 4 5

// Sample output : 

// 3 4