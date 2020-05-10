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
	bool cycle_helper(T cur,unordered_map<T,bool> &visited,T parent) {
		// mark current node as visted.
		visited[cur] = true;
		// traverse on all the nbr's of the current node.
		for(T nbr : this->adjList[cur]) {
			// if the nbr is parent of current node then skip.
			if(parent == nbr) continue;
			// if node is already visited return true.
			if(visited[nbr]) return true;
			return cycle_helper(nbr,visited,cur);
		}
		return false;
	}
	// checks whether Graph has any cycle or not.
	bool isCyclicPresent(T src,T parent) {
		unordered_map<T,bool> visited;
		for(auto node : this->adjList) 
			visited[node.first] = false;
		return cycle_helper(src,visited,parent);
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
	if(g.isCyclicPresent(1,-1)) cout << "Yes, This undirected graph has cycle." << endl;
	else cout << "This Graph has no cycle." << endl;
	return 0;
}

// Sample Input :

// 3
// 1 2
// 2 3
// 1 4

// 5
// 0 1
// 1 2
// 2 3
// 3 4 
// 4 0

// Sample Output :

// This Graph has no cycle.
// Yes, This undirected graph has cycle.