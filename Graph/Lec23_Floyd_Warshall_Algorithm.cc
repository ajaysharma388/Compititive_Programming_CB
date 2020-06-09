#include<iostream>
#include<vector>

using namespace std;

#define int long long int
#define endl '\n'
#define pii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define pb push_back
#define mp make_pair

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

std::vector<vi> all_pair_shortest_path(int n,std::vector<std::vector<pii>> &adjList) {
	// distance matrix.
	std::vector<vi> dist(n+1,vi(n+1,2e9));
	for(int i = 1 ;i <= n; ++i) {
		dist[i][i] = 0;
		for(pii edge : adjList[i]) {
			int nbr = edge.F;
			int wght = edge.S;
			dist[i][nbr] = wght;
		}
	}
	// running the n phases.
	for(int k = 1; k <= n; ++k) { 
		// in the kth phase.
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) 
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	}
	return dist;
}

void solve() {
	int V, E;
	cin >> V >> E;
	std::vector<std::vector<pii>> adjList(V+1);
	for(int e = 1; e <= E; ++e) {
		int src, dest, cost;
		cin >> src >> dest >> cost;
		adjList[src].pb(mp(dest, cost));
		adjList[dest].pb(mp(src, cost));
	}
	std::vector<std::vector<int>> dist = all_pair_shortest_path(V,adjList);
	cout << '*' << " | ";
	for(int i = 1; i <= V; ++i) 
		cout << i << " ";
	cout << endl;
	for(int i = 1; i <= V; ++i) {
		cout << i << " | ";
		for(int j = 1; j <= V; ++j) 
			cout << dist[i][j] << " ";
		cout << endl;
	}
	return;
}

int32_t main() {
	fastio(true);
	solve();
	return 0;
}

// Sample Input :

// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 1
// 3 4 2

// Sample Output :

// * | 1 2 3 4 
// 1 | 0 3 4 4 
// 2 | 3 0 1 1 
// 3 | 4 1 0 2 
// 4 | 4 1 2 0 