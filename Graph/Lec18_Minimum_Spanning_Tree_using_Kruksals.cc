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

struct dsu
{
    std::vector<int> par;
    int ttl_comp;
    // initializing the vector.
    void init(int n) {
        par.resize(n);
        ttl_comp = n;
        for(int i = 1; i < n; ++i) {
            par[i] = i;
        }
    }
    // this is function is used to get the superparent.
    int getSuperParent(int x) {
        if(par[x] == x) return x;
        // here we are ensuring that the tree won't sckwed.
        // that means we are applying the path compression.
        return par[x] = getSuperParent(par[x]);
    }

    // applying union on two nodes.
    void unite(int x,int y) {
        int supParentX = getSuperParent(x);
        int supParentY = getSuperParent(y);
        if(supParentX != supParentY) par[supParentX] = supParentY;
        ttl_comp -= 1;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> gr[m];
    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        gr[i] = {w,x,y};
    }
    sort(gr,gr+m);
    dsu G;
    G.init(n+1);
    int ans = 0;
    for(int i = 0; i < m; ++i) {
        if(G.getSuperParent(gr[i][1]) != G.getSuperParent(gr[i][2])) {
            G.unite(gr[i][1],gr[i][2]);
            ans += gr[i][0];
        }
    }
    cout << "Cost Of Minimum Spanning Tree is : " << ans << endl;
}

int32_t main() {
    fastio(true);
    // int t; cin >> t;
    // while(t--) {
        solve();
    // }
    return 0;
}

// Smaple Output :

// 9 15
// 1 2 10
// 1 3 12
// 2 3 9
// 2 4 8
// 3 5 3
// 3 6 1
// 4 5 7
// 4 6 10
// 4 7 8
// 4 8 5
// 5 6 3
// 6 8 6
// 7 8 9
// 7 9 2
// 8 9 11

// Sample Output :

// Cost Of Minimum Spanning Tree is : 43