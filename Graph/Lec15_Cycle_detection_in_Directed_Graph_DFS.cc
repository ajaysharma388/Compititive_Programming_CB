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
#define un_mp unordered_map

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
	un_mp<T,list<T>> adjList;
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
			T u = node.first;
			cout << u << " --> ";
			for(T vertex : this->adjList[u]) 
				cout << vertex << ", ";
			cout << endl;
		}
	}

	bool detect_cycle(T cur,un_mp<T,bool> &visited,un_mp<T,bool> &stack) {
		visited[cur] = true;
		stack[cur] = true;
		// traverse on the neighbours.
		for(auto nbr : this->adjList[cur]) {
			if(stack[nbr]) return true;
			else if(!visited[nbr] and detect_cycle(nbr,visited,stack)) return true;
		}
		// since we are leaving the node.
		stack[cur] = false;
		return false;
	}

	bool isCyclic(T src) {
		un_mp<T,bool> visited;
		un_mp<T,bool> stack;
		for(auto p : this->adjList) {
			visited[p.F] = false;
			stack[p.F] = false;
		}
		return detect_cycle(src,visited,stack);
	}
};

int main() {
	fastio(true);
	int m,n;
	// m represents number of vertices & n represents number of edges.
	cin >> m >> n;
	Graph<int> g;
	for(int i = 0; i < n; ++i) {
		int x,y;
		cin >> x >> y;
		g.addEdge(x,y,false);
	}
	if(g.isCyclic(0)) cout << "This Graph contains cycle.\n";
	else cout << "This Graph does not contains cycle.\n";
	return 0;
}

// Sample Input :

// 6 6
// 0 1
// 0 2
// 1 5
// 2 4
// 4 5
// 2 3

// 6 7
// 0 1
// 0 2
// 1 5
// 2 4
// 4 5
// 2 3
// 3 0

// Sample Output :

// This Graph does not contains cycle.

// This Graph contains cycle.