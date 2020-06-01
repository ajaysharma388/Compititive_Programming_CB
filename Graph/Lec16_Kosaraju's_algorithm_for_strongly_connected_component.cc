/*==========================
Author : Ajay Sharma
date : 02.06.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

// Some useful macros that are helpful to reduce code size.
#define vi vector<int>
#define int long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ld long double
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
const int N = 100005, M = 22;
std::vector<int> gr[N],grr[N];
std::vector<int> order,in_comp[N];
int vis[N],comp[N];

void dfs(int cur) {
    vis[cur] = 1;
    for(auto nbr : gr[cur]) 
        if(!vis[nbr]) dfs(nbr);
    order.pb(cur);
}

void dfs_reverse(int cur,int col) {
    comp[cur] = col;
    in_comp[col].pb(cur);
    vis[cur] = 1;
    for(auto nbr : grr[cur]) 
        if(!vis[nbr]) 
            dfs_reverse(nbr,col);
}

void solve() {
    int m, n;
    cin >> n >> m;
    for(int i =0 ; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        grr[y].pb(x);
    }
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i);
    }
    // for(auto e : order) cout << e << " ";
    memset(vis,0,sizeof(vis));
    int col = 0;
    for(int i = n; i >= 1; --i) {
        if(!vis[order[i]]) {
            dfs_reverse(order[i],col);
            col += 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << i << " -> " << comp[i] << endl;
    }
    // for(auto v : in_comp) {
    //     for(int e : v) {
    //         cout << e << ", ";
    //     }
    //     cout << endl;
    // }
}

int32_t main() {
    fastio(true);
    solve();
    return 0;
}

// Sample Input :

// 6 7
// 1 2
// 2 3
// 3 1
// 3 4
// 4 5
// 5 6
// 6 4

// Sample Output :

// 1 -> 1
// 2 -> 1
// 3 -> 1
// 4 -> 2
// 5 -> 2
// 6 -> 2
// 0, 
// 1, 3, 2, 
// 4, 6, 5,