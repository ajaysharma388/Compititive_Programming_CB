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
        for(int i = 0; i < n; ++i) {
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
    bool isCyclic = false;
    cin >> n >> m;
    dsu G;
    G.init(n);
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(G.getSuperParent(x) != G.getSuperParent(y)) {
            // that means they are from different component.
            G.unite(x,y);
        } else {
            isCyclic = true;
            break;
        }
    }
    if(isCyclic) cout << "This graph is cyclic.\n";
    else cout << "This graph has no cycle.\n"; 
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

// 6 7
// 1 2
// 2 3
// 3 1
// 3 4
// 4 5
// 5 6
// 6 4

// Sample Output :

// This graph is cyclic.