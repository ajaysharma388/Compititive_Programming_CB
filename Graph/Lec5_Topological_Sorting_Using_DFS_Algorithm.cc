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
class Graph {
	map<T,list<T>> AdjList;
public:
	void addEdge(T src, T dest, bool bidir = true) {
		this->AdjList[src].push_back(dest);
		if(bidir) this->AdjList[dest].push_back(src);
	}

	void printAdjList() {
		for(auto node : this->AdjList) {
			cout << node.first << " -> ";
			for(auto nbr : node.second) 
				cout << nbr << " ,";
			cout << endl;
		}
	}

	void dfs(T src,unordered_map<T,bool> &visited,list<T> &order) {
		// setting up the source node as visited.
		visited[src] = true;
		for(auto nbr : this->AdjList[src]) 
			if(!visited[nbr]) dfs(nbr,visited,order);
		order.push_front(src);
		return;
	}

	void topologicalSort() {
		unordered_map<T,bool> visited;
		list<T> order;
		for(auto node : this->AdjList) 
			visited[node.first] = false;
		for(auto node : this->AdjList) 
			if(!visited[node.first]) dfs(node.first,visited,order);
		for(T e : order) 
			cout << e << " ,";
		cout << endl;
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
		g.addEdge(u,v,false);
	}
	g.topologicalSort();
	return 0;
}

// Sample Input :

// 7
// 1 2
// 1 3
// 2 4
// 4 5
// 3 5
// 6 7
// 5 7

// Sample Output :

// 6 ,1 ,3 ,2 ,4 ,5 ,7 ,