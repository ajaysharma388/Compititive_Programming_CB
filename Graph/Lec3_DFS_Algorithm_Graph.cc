#include <bits/stdc++.h>
using namespace std;

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
	void addEdge(T u, T v, bool bidir = true) {
		this->adjList[u].push_back(v);
		if(bidir) this->adjList[v].push_back(u);
	}

	void printAdjList() {
		for(auto node : this->adjList) {
			cout << node.first << " -> ";
			for(T nbr : node.second) 
				cout << nbr << " ,";
			cout << endl;
		}
	}

	void dfs_helper(T src,unordered_map<T,bool> &visited) {
		// mark the src node as visited.
		cout << src << " ";
		visited[src] = true;
		// iterate over all the unvisited children's on by one.
		for(T nbr : this->adjList[src]) {
			if(!visited[nbr]) {
				dfs_helper(nbr,visited);
			}
		} 
		return;
	}

	void dfs(T src) {
		unordered_map<T,bool> visited;
		for(auto node : this->adjList) 
			visited[node.first] = false;
		dfs_helper(src,visited);
		return;
	}
};

int main(){
	fastio(true);
	Graph<int> g;
	int e;
	cin >> e;
	while(e--) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u,v);
	}
	g.dfs(0);
	return 0;
}

// Sample Input :

// 6
// 0 1
// 0 3
// 1 2
// 2 3
// 3 4
// 4 5

// Sample Output :

// 0 1 2 3 4 5 