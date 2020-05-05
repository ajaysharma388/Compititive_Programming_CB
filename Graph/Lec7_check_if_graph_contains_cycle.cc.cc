/*==========================
Author : Ajay Sharma
date : 05.05.2020
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
	map<T,list<T>> adjList;
	public:
	// Default Constructor.
	Graph() {}
	// Adding the Edge into the graph.
	void addEdge(T u,T v,bool bidir = true) {
		this->adjList[u].pb(v);
		if(bidir) this->adjList[v].pb(u);
	}
	// Printing The Adjacency List.
	void printAdjList() {
		for(auto node : this->adjList) {
			T u = node.F;
			cout << u << " --> ";
			for(T vertex : this->adjList[u]) 
				cout << vertex << ", ";
			cout << endl;
		}
	}
	// isTree function that checks whether Graph has any cycle or not.
	bool isTree(T src) {
		unordered_map<T,T> parents;
		unordered_map<T,bool> visited;
		queue<T> Q;
		for(auto node : this->adjList) 
			visited[node.F] = false;
		Q.push(src);
		parents[src] = src;
		visited[src] = true;
		while(!Q.empty()) {
			T cur = Q.front();
			Q.pop();
			for(auto nbr : this->adjList[cur]) {
				if(nbr == parents[cur]) continue;
				if(visited[nbr]) return false;
				visited[nbr] = true;
				parents[nbr] = cur;
				Q.push(nbr);
			}
		}
		// There is no cycle present in the graph.
		return true;
	}
};

int main() {
	fastio(true);
	Graph<int> g;
	int E;
	cin >> E;
	while(E--) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u,v);
	}
	if(g.isTree(1)) cout << "This Graph has no cycle." << endl;
	else cout << "This Graph has cycle." << endl;
	return 0;
}

// Sample Input :

// 3
// 1 2
// 2 3
// 1 4

// 7
// 1 2
// 1 3
// 2 4
// 4 5
// 3 5
// 6 7
// 5 7

// Sample Output :

// This Graph has no cycle.
// This Graph has cycle.