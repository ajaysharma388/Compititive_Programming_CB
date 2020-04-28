#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUDGE
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
	map<T,list<T>> AdjList;
public:
	void addEdge(T src,T dest,bool bidir = true) {
		this->AdjList[src].push_back(dest);
		if(bidir) this->AdjList[dest].push_back(src);
	}

	void printList() {
		for(auto node : this->AdjList) {
			cout << node.first << " -> ";
			for(T nbr : node.second) {
				cout << nbr << " ,";
			}
			cout << endl;
		}
	}

	void sortestPathBFS(T src,T dest) {
		queue<T> Q;
		unordered_map<T,bool> visited;
		unordered_map<T,T> parents;
		// unordered_map<T,int> distance;
		Q.push(src);
		visited[src] = true;
		parents[src] = src;
		while(!Q.empty()) {
			int cur = Q.front();
			Q.pop();
			// iterate over it's all nbrs.
			for(auto nbr : this->AdjList[cur]) {
				if(!visited[nbr]) {
					Q.push(nbr);
					visited[nbr] = true;
					parents[nbr] = cur;
				}
			}
		}
		// now we have the route from src to dest stored in 
		// parent map let's fetch it.
		vector<T> route;
		T cur = dest;
		while(cur != src) {
			route.push_back(cur);
			cur = parents[cur];
		}
		route.push_back(cur);
		// since our route is stored from back to front reverse it.
		reverse(route.begin(),route.end());
		// printing the route.
		for(T node : route) {
			cout << node << " -> ";
		}
		return;
	}
};

int main() {
	fastio(true);
	Graph<int> g;
	int e;
	cin >> e;
	while(e--) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u,v);
	}
	// g.printList();
	g.sortestPathBFS(0,5);
	return 0;
}

// Sample Input :

// 6
// 0 1
// 0 3
// 2 1
// 2 3
// 3 4
// 4 5

// Sample Output :

// 0 -> 3 -> 4 -> 5 -> 