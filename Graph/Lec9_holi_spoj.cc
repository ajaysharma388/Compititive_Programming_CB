/*==========================
Author : Ajay Sharma
date : 04.05.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define vi(n) vector<long long int>
#define vii(m,n) vector<m, vector<long long int>(n,0)>
#define ll long long int
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

template<typename T>
class Graph{
	list< pair<T,int> > *adjList;
	int V;
	public:
	// Default Constructor.
	Graph(const int V) {
		this->V = V;
		this->adjList = new list< pair<T,int> >[V];
	}
	// Adding the Edge into the graph.
	void addEdge(T u,T v,int cost,bool bidir = true) {
		this->adjList[u].pb(mp(v,cost));
		if(bidir) this->adjList[v].pb(mp(u,cost));
	}
	// Printing The Adjacency List.
	void printAdjList() {
		for(int v = 0; v < this->V; ++v) {
			cout << v << " --> ";
			for(auto nbr_pair : this->adjList[v]) 
				cout << "("<< nbr_pair.F << " ," << nbr_pair.S << "), ";
			cout << endl;
		}
	}

	int dfsHealper(int node,bool *visited,int *count,int &ans) {
		// Mark the current node as visited.
		visited[node] = true; 
		count[node] = 1;
		// traverse through it's children.
		for(auto nbr_pair : this->adjList[node]) {
			T nbr = nbr_pair.F;
			int wt = nbr_pair.S;
			if(!visited[nbr]) {
				count[node] += dfsHealper(nbr,visited,count,ans);
				int dx = count[nbr];
				int dy = this->V - dx;
				ans += 2*min(dx,dy)*wt;
			}
		}
		return count[node];
	}

	int dfs() {
		bool *visited = new bool[this->V]{false};
		int *count = new int[this->V]{0};
		int ans = 0;
		dfsHealper(0,visited,count,ans);
		return ans;
	}
};

int main() {
	fastio(true);
	int testCases,V;
	cin >> testCases;
	for(int test = 1; test <= testCases; ++test) {
		cin >> V;
		Graph<int> g(V);
		for(int i = 1; i < V; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			g.addEdge(u-1,v-1,w);
		}
		cout << "Case #" << test << ": " << g.dfs() << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 4
// 1 2 3
// 2 3 2
// 4 3 2
// 6
// 1 2 3
// 2 3 4
// 2 4 1
// 4 5 8
// 5 6 5

// Sample Output :

// Case #1: 18
// Case #2: 62