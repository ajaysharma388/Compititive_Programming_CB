/*==========================
Author : Ajay Sharma
date : 08.06.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

// Some useful macros that are helpful to reduce code size.

// this is slightly better implementation of the bellmann ford algorithm
// for finding whether there exist any negative weight cycle in the graph
// or not time complexity is of the order O(V.E) & if cycle exist we will 
// Simply print the vectices which are in the cycle.
// where V is the number of vertices in the graph.
// and E is the number of edges.

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

struct edge
{
    int u, v, cost;    
};

void solve() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    int dis[n];
    int path[n];
    vector<edge> edgesList;
    for(int v = 0; v < n; ++v) {
        dis[v] = INT_MAX;
        path[v] = v;
    }
    // Taking input edges List.
    for(int e = 1; e <= m; ++e) {
        edge E;
        cin >> E.u >> E.v >> E.cost;
        edgesList.pb(E);
    }
    dis[s] = 0;
    path[s] = s;
    int x;
    for(int phase = 1; phase <= n; ++phase) {
        x = -1;
        for(int e = 0; e < m; ++e) {
            edge cur = edgesList[e];
            if(dis[cur.u] != INT_MAX and dis[cur.v] > dis[cur.u]+cur.cost) {
                path[cur.v] = cur.u;
                dis[cur.v] = dis[cur.u]+cur.cost;
                x = cur.u;
            }
        }
    }
    if(x == -1) {
        cout << "There is No negative weight cycle in the Graph.\nThe route from " 
        << (char) (s+'A') << " to " << (char) (d+'A') << " is : ";
        vector<char> route;
        int cur = d;
        while(path[cur] != cur) {
            route.pb(char('A'+cur));
            cur = path[cur];
        }
        route.pb(char('A'+cur));
        reverse(route.begin(), route.end());
        for(auto v : route) cout << v << " -> ";
    } else {
        int y = x;
        for (int i=0; i<n; ++i) {
            y = path[y];
        }
        vector<int> cyclicPath;
        for (int cur=y; ; cur=path[cur]) {
            cyclicPath.push_back (cur);
            if (cur == y && cyclicPath.size() > 1)
                break;
        }
        reverse (cyclicPath.begin(), cyclicPath.end());
        cout << "Negative cycle: ";
        for (size_t i=0; i < cyclicPath.size(); ++i)
            cout << cyclicPath[i] << ' ';
    }
    return;
}

int32_t main()
{
    fastio(true);
    solve();
    return 0;
}

// Smaple Output :

// 6 7 0 5
// 0 1 4
// 0 2 2
// 1 2 5
// 1 3 10
// 4 3 4
// 3 5 11
// 2 4 3

// 4 5 0 3
// 0 1 5
// 0 2 4
// 2 1 -6
// 1 3 3
// 3 2 2



// Sample Output :

// There is No negative weight cycle in the Graph.
// The route from A to F is : A -> C -> E -> D -> F -> 


// Negative cycle: 1 3 2 1 