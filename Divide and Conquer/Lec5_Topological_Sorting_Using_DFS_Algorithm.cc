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

	void printList() {
		for(auto node : this->AdjList) {
			cout << node.first << " -> ";
			for(auto nbr : node.second) 
				cout << nbr << " ,";
			cout << endl;
		}
	}

	void dfs(T src,unordered_map<T,bool> &visited) {
		// setting up the source node as visited.
		cout << src << " ,";
		visited[src] = true;
		for(auto nbr : this->AdjList[src]) 
			if(!visited[nbr]) dfs(nbr,visited);
		return;
	}

	int countCCInGraph() {
		unordered_map<T,bool> visited;
		for(auto node : this->AdjList) 
			visited[node.first] = false;
		int count = 0;
		for(auto node : this->AdjList) {
			if(!visited[node.first]) {
				count += 1;
				cout << "Component Count No." << count << " : ";
				dfs(node.first,visited);
				cout << endl;
			}
		}
		return count;
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
	int count = g.countCCInGraph();
	cout << "No. Of Connected Component's : " << count << endl;
	return 0;
}