/*==========================
Author : Ajay Sharma
date : 03.06.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

// Some useful macros that are helpful to reduce code size.

// this is slightly better implementation of the bellmann ford algorithm
// for finding the minimum distace from Src to every node in the graph.
// time complexity is of the order O(V.E) in the worst case.
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


bool compare(int a,int b) {
    cout << a << " < - > " << b << endl;
    return a > b; 
}

int32_t main()
{
    fastio(true);
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
    while(true) {
        bool anyChange = false;
        for(int e = 0; e < m; ++e) {
            edge cur = edgesList[e];
            if(dis[cur.u] != INT_MAX and dis[cur.v] > dis[cur.u]+cur.cost) {
                anyChange = true;
                path[cur.v] = cur.u;
                dis[cur.v] = dis[cur.u]+cur.cost;
            }
        }
        if(!anyChange) break;
    }
    vector<char> route;
    int cur = d;
    while(path[cur] != cur) {
        route.pb(char('A'+cur));
        cur = path[cur];
    }
    route.pb(char('A'+cur));
    for(int i = 0; i < route.size()/2; ++i) {
        swap(route[i],route[route.size()-i-1]);
    }
    for(auto v : route) cout << v << " -> ";
    return 0;
}

// Smaple Output :

// 6 7 0
// A B 4
// A C 2
// B C 5
// B D 10
// E D 4
// D F 11
// C E 3

// Sample Output :

// A -> C -> E -> D -> F -> 