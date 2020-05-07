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
			T u = node.first;
			cout << u << " --> ";
			for(T vertex : this->adjList[u]) 
				cout << vertex << ", ";
			cout << endl;
		}
	}

	bool detect_cycle(un_mp<T,bool> &visited,un_mp<T,bool> &stack) {}
	
};

int main() {
	fastio(true);

	return 0;
}

// Sample Input :

// Sample Output :
