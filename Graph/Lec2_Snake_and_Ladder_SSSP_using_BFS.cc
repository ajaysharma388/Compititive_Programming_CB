#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void fastio(bool read = true) {
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
class Graph {
	map<T,list<T>> adjList;
public:
	void addEdge(T src,T dest,bool bidir = false) {
		this->adjList[src].push_back(dest);
		if(bidir) this->adjList[dest].push_back(src);
	}

	void printAdjList() {
		for(auto node : this->adjList) {
			cout << node.first << " -> ";
			for(T nbr : node.second) {
				cout << nbr << " ,";
			}
			cout << endl;
		}
	}

	void snakesandLadderBFS (T src,T dest) {
		queue<T> Q;
		unordered_map<T,T> parent;
		unordered_map<T,int> distance;
		// initialize the distance map.
		for(auto node : this->adjList) 
			distance[node.first] = INT_MAX;
		distance[src] = 0;
		parent[src] = src;
		Q.push(src);
		while(!Q.empty()) {
			T cur = Q.front();
			Q.pop();
			// Traverse over the children's of cur node.
			for(T nbr : this->adjList[cur]) {
				if(distance[nbr] == INT_MAX) {
					Q.push(nbr);
					distance[nbr] = distance[cur]+1;
					parent[nbr] = cur;
				}
			}
		}
		vector<T> route;
		T temp = dest;
		while(temp != src) {
			route.push_back(temp);
			temp = parent[temp];
		}
		route.push_back(src);
		reverse(route.begin(),route.end());
		for(auto cur : route) {
			if(cur == dest) break;
			cout << cur << " -> ";
		} 
		cout << dest << endl;
		cout << "Minimum Dice throw required : " << distance[dest] << endl;
	}
};

int main() {
	fastio(true);
	int m,n,l,s;
	cin >> m >> n;
	Graph<int> g;
	g.addEdge(m*n,m*n);
	int *board = new int[m*n + 1]();
	memset(board,0,m*n+1);
	cin >> l;
	while(l--) {
		int s, inc;
		cin >> s >> inc;
		board[s] = (inc-s);
	}
	cin >> s;
	while(s--) {
		int s, d;
		cin >> s >> d;
		board[s] = (d-s);
	}
	for(int i = 0; i < m*n; ++i) {
		for(int dice = 1; dice <= 6; ++dice) {
			int j = i + dice;
			j += board[j];
			g.addEdge(i,j);
		}
	}
	// g.printAdjList();
	g.snakesandLadderBFS(0,36);
	return 0;
}

// Sample Input :

// 6 6
// 5
// 2 15
// 5 7
// 9 27
// 18 29
// 25 35
// 5
// 17 4
// 20 6
// 24 16
// 32 30
// 34 12

// Sample Output :

// 0 -> 15 -> 29 -> 30 -> 36
// Minimum Dice throw required : 4