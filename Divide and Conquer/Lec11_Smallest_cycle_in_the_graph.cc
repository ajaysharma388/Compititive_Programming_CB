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
vector<int> Graph[N];

void bfs(int src,int N,int &ans) {
	vector<int> dis(N+1,INT_MAX);
	queue<int> Q;
	Q.push(src);
	dis[src] = 0;

	// Applying BFS.
	while(!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		// Traverse on all the nbr's of the cur node.
		for(int nbr : Graph[cur]) {
			// this node is not visited.
			if(dis[nbr] == INT_MAX) {
				Q.push(nbr);
				dis[nbr] = dis[cur] + 1;
			}
			// this nbr is already visited. 
			// the backedge is encountred.
			else if(dis[nbr] >= dis[cur]) {
				ans = min(ans,dis[cur]+dis[nbr]+1);
			}
		}
	}

}

void solve()
{
    int n, m, ans;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        Graph[x].pb(y);
        Graph[y].pb(x);
    }
    ans = n+1;
    for(int src = 1; src <= n; ++src) bfs(src,n,ans);
    if(ans == n+1) cout << "There is no cycle in the Graph.\n";
	else cout << "The length of shortest cycle is " << ans << '\n';
	return;  
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

// 4 4
// 1 2
// 2 3
// 3 4
// 4 1

// Sample output :

// Not Bipartite
// Bipartite