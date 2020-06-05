/*==========================
Author : Ajay Sharma
date : 03.06.2020
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


int32_t main()
{
    fastio(true);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> gr[n+1];
    // vis means included in the mst.
    int vis[n+1] = {0};
    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        gr[x].pb({y, w});
        gr[y].pb({x, w});
    }
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    int mstWght = 0;
    Q.push({0,1});
    while(!Q.empty()) {
        pair<int, int> curBest = Q.top();
        Q.pop();
        int wght = curBest.F;
        int to = curBest.S;
        // if the edge is not active that means we have already travelled to.
        if(vis[to]) continue;
        mstWght += wght;
        vis[to] = 1;
        // we will mark the edges of to as active now.
        for(auto nbr : gr[to]) 
            if(!vis[nbr.F]) 
                Q.push({nbr.S,nbr.F});
    }
    cout << "Weight of Minimum Spanning Tree is " << mstWght << endl;
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

// Weight of Minimum Spanning Tree is 43