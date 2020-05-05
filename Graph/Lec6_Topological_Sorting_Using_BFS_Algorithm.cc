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
class Graph {
	map<T,list<T>> AdjList;
public:
	void addEdge(T src, T dest, bool bidir = true) {
		this->AdjList[src].pb(dest);
		if(bidir) this->AdjList[dest].pb(src);
	}

	void printAdjList() {
		for(auto node : this->AdjList) {
			cout << node.F << " -> ";
			for(auto nbr : node.S) 
				cout << nbr << " ,";
			cout << endl;
		}
	}

	void topologicalSort() {
		unordered_map<int,int> indegree;
		queue<int> Q;
		for(auto node : this->AdjList) 
			indegree[node.F] = 0;
		for(auto node : this->AdjList) 
			for(T nbr : this->AdjList[node.F]) 
				indegree[nbr] += 1;
		for(auto node : this->AdjList) 
			if (indegree[node.F] == 0) 
				Q.push(node.F);
		while(!Q.empty()) {
			T cur = Q.front();
			Q.pop();
			for(T nbr : this->AdjList[cur]) { 
				indegree[nbr] -= 1;
				if(indegree[nbr] == 0) Q.push(nbr);
			}
			cout << cur << " ,";
		}
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
// 1 ,6 ,2 ,3 ,4 ,5 ,7 ,