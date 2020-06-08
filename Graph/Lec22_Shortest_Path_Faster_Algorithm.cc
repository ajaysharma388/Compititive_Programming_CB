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

const int inf = 10000000000;

bool spfa(int s,int n,vector<vector<pair<int,int>>> &adj,vector<int> &dis) {
    dis.assign(n,inf);
    vector<int> cnt(n, 0);
    vector<bool> inQueue(n, false);
    queue<int> Q;
    dis[s] = 0;
    Q.push(s);
    inQueue[s] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        inQueue[cur] = false;
        // Traverse on all the nbring edges in adjList.
        for(auto edge : adj[cur]) {
            int to = edge.F;
            int cost = edge.S;
            if(dis[cur] + cost < dis[to]) {
                dis[to] = dis[cur] + cost;
                if(!inQueue[to]) {
                    Q.push(to);
                    inQueue[to] = true;
                    cnt[to] += 1;
                    if(cnt[to] > n) return true;
                }
            }
        }
    }
    return false;
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int,int>>> adj(n);
    vector<int> dis(n);
    adj.clear();
    // Taking input edges List.
    for(int e = 1; e <= m; ++e) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].pb({y,w});
    }
    if(spfa(s,n,adj,dis)) 
        cout << "Negative Cycle Exist." << endl;
    else 
        for(auto i = 0; i < n; ++i) 
            cout << "Dist. of " << i << " From " << s << " is " << dis[i] << endl;
    return;
}

int32_t main()
{
    fastio(true);
    solve();
    return 0;
}

// Smaple Output :

// 6 7 0 
// 0 1 4
// 0 2 2
// 1 2 5
// 1 3 10
// 4 3 4
// 3 5 11
// 2 4 3

// 4 5 0 
// 0 1 5
// 0 2 4
// 2 1 -6
// 1 3 3
// 3 2 2



// Sample Output :

// Dist. of 0 From 0 is 0
// Dist. of 1 From 0 is 4
// Dist. of 2 From 0 is 2
// Dist. of 3 From 0 is 9
// Dist. of 4 From 0 is 5
// Dist. of 5 From 0 is 20


// Negative Cycle Exist.