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
int visited[N];
bool odd_cycle = false;

void dfs(int cur, int par, int color)
{
    visited[cur] = color;
    for(auto child : gr[cur])
    {
        // Child is not visited.
        if(visited[child] == 0) dfs(child, cur, 3 - color);
        // If the child is visited but not the parent of cur.
        // then we can say that there is a backedge.
        else if(child != par and color == visited[child]) odd_cycle = true;
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
    dfs(1, 0, 1);
    if(odd_cycle) cout << "Not Bipartite\n";
    else cout << "Bipartit\n";
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