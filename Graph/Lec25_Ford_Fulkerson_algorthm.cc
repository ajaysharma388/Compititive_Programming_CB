#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define F first 
#define S second


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

// ford_fulkerson algorithm implementation.
bool bfs(int **Gr,int V,int &src,int &dest,vector<int> &parent) {
	int visited[V];
	memset(visited,false,sizeof(visited));
	queue<int> Q;
	Q.push(src);
	parent[src] = -1;
	visited[src] = true;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(int v = 0; v < V; ++v) {
			if(Gr[u][v] > 0 and !visited[v]) {
				Q.push(v);
				visited[v] = true;
				parent[v] = u;
			}
		}
	}
	return (visited[dest] == true);
}

int ford_fulkerson(int **Gr,int V,int src,int dest) {
	int u, v;
	int **rGr = new int*[V];
	for(int i = 0; i < V; ++i) 
		rGr[i] = new int[V];
	for(int i = 0; i < V; ++i) 
		for(int j = 0; j < V; ++j) 
			rGr[i][j] = Gr[i][j];
	vector<int> parent(V,0);
	int max_flow = 0;
	while(bfs(rGr,V,src,dest,parent)) {
		int path_flow = INT_MAX;
		for(v = dest; v != src; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow,rGr[u][v]);
		}
		vector<int> path;
		path.push_back(dest);
		for(v = dest; v != src; v = parent[v]) {
			u = parent[v];
			path.push_back(u);
			rGr[u][v] -= path_flow;
			rGr[v][u] += path_flow;
		}
		reverse(path.begin(),path.end());
		for(auto p : path) cout << p << " -> ";
		cout << endl; 
		max_flow += path_flow;
	}
	return max_flow;
}

void solve() {
	int v, e, src, dest;
	cin >> v >> e >> src >> dest;
	int **Gr = new int*[v];
	for(int i = 0; i < v; ++i) 
		Gr[i] = new int[v];
	for(int i = 0; i < v; ++i) 
		for(int j = 0; j < v; ++j) 
			Gr[i][j] = 0;
	for(int edge = 1; edge <= e; ++edge) {
		int x , y, w;
		cin >> x >> y >> w;
		Gr[x][y] = w;
	}
	int max_flow = ford_fulkerson(Gr,v,src,dest);
	cout << "Max flow throught the above network is " << max_flow << endl;
	return;
}

int32_t main() {
	fastio(true);
	// int t; cin >> t;
	// while(t--) 
	solve();
	return 0;
}


// Sample Input :

// 5 7 0 1
// 0 2 100
// 2 1 50
// 2 3 50
// 2 4 50
// 0 3 50
// 3 4 100
// 4 1 125

// Sample Output :

// 0 -> 2 -> 1 -> 
// 0 -> 2 -> 4 -> 1 -> 
// 0 -> 3 -> 4 -> 1 -> 
// Max flow throught the above network is 150