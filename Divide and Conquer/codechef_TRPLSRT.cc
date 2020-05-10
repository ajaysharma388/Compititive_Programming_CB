/*==========================
Author : Ajay Sharma
date : 04.05.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

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

bool triplesort(int *arr,int N,int K,queue<int> &Q,vector<vector<int>> &tries) {
	while(K > 0 and !Q.empty()) {
		vector<int> res;
		int i1 = Q.front(); Q.pop();
		if(Q.empty()) return false;
		int i2 = Q.front(); Q.pop();
		if(Q.empty()) return false;
		int i3 = Q.front(); Q.pop();
		swap(arr[i1],arr[i2]);
		swap(arr[i1],arr[i3]);
		if(i1 != arr[i1]) Q.push(i1);
		else res.push_back(i1);
		if(i2 != arr[i2]) Q.push(i2);
		else res.push_back(i2);
		if(i3 != arr[i3]) Q.push(i3);
		else res.push_back(i3);
		tries.push_back(res);
		K--;
	}
	return Q.empty();
}

int main() {
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		int N, K;
		cin >> N >> K;
		int *arr = new int[N+1]{0};
		queue<int> Q;
		for(int i = 1; i <= N; ++i) {
			cin >> arr[i];
			if(arr[i]!=i) Q.push(i);
		}		
		vector<vector<int>> tries;
		if(!triplesort(arr,N,K,Q,tries)) {
			cout << "-1" << endl;
		} else {
			cout << tries.size() << endl;
			for(auto tuple : tries) {
				for(int idx : tuple) 
					cout << idx << " ";
 				cout << endl;
			}
		}
	}
	return 0;
}