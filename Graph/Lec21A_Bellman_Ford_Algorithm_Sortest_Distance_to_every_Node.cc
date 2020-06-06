/*==========================
Author : Ajay Sharma
date : 03.06.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

// Some useful macros that are helpful to reduce code size.
// this is simple implementation of the bellman ford algorithm
// for finding the minimum distace from Src to every node in the graph.
// time complexity is of the order O(V.E);
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
    int n, m, src;
    cin >> n >> m >> src;
    int dis[n];
    vector<edge> edgesList;
    for(int v = 0; v < n; ++v) dis[v] = INT_MAX;
    // Taking input edges List.
    for(int e = 1; e <= m; ++e) {
        edge E;
        cin >> E.u >> E.v >> E.cost;
        edgesList.pb(E);
    }
    dis[src] = 0;
    for(int phase = 0; phase < n-1; ++phase) {
        for(int e = 0; e < m; ++e) {
            edge cur = edgesList[e];
            if(dis[cur.u] != INT_MAX) {// dis[cur.u]+cur.cost) {
                dis[cur.v] = min(dis[cur.v], dis[cur.u]+cur.cost);
            }
        }
    }
    for(int v = 0; v < n; ++v) {
        cout << char('A'+v) << " --> " << dis[v] << endl;
    }
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

// A --> 0
// B --> 4
// C --> 2
// D --> 9
// E --> 5
// F --> 20