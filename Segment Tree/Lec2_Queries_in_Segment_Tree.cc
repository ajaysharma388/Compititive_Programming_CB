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

class SegmentTree {
	int lastIdx;
	int *tree;
	int size;
public:
	SegmentTree(const int n) {
		// It has been already proved that the size of the segment 
		// Tree will not exceed more than 4*n+1.
		this->size = 4*n+1;
		this->tree = new int[this->size]();
		this->lastIdx = -1;
	}
	void buildTree(int *arr,int s,int e,int index) {
		// figuringout last valid index
		this->lastIdx = max(lastIdx,index);
		// Base Case If we have reached the leaf node.
		if(s == e) {
			this->tree[index] = arr[s];
			return;
		}
		// recursive cases.
		int m = (s+e)/2;
		buildTree(arr,s,m,2*index);
		buildTree(arr,m+1,e,2*index+1);
		this->tree[index] = min(this->tree[2*index],this->tree[2*index+1]);
		return;
	}
	int QueryTree(int s,int e,int qs,int qe,int index) {
		// Here, we have to handle three cases.
		// 1. Complete Overlap.
		if(s >= qs and qe >= e) return this->tree[index];
		// 2. No overlap. return INT_MAX.
		if(qe < s or e < qs) return INT_MAX;
		// 3. Partial Overlap.
		// Call on both side.
		int m = (s+e)/2;
		// Left Result.
		int leftRes = QueryTree(s,m,qs,qe,2*index);
		// right Result.
		int rightRes = QueryTree(m+1,e,qs,qe,2*index+1);
		return min(leftRes,rightRes);
	}
	void printTree() {
		for(int i = 1; i <= this->lastIdx; ++i)  
			cout << this->tree[i] << " ";
		cout << endl;
	}
};

int main(){
	fastio(true);
	int n;
	cin >> n;
	int*arr = new int[n]();
	// Read The Input.
	for(int i = 0; i < n; ++i) 
		cin >> arr[i];
	// create The Tree.
	SegmentTree t(n);
	t.buildTree(arr,0,n-1,1);
	int q;
	cin >> q;
	while(q--) {
		int s,e;
		cin >> s >> e;
		cout << t.QueryTree(0,n-1,s,e,1) << endl;
	}
	return 0;
}

// Sample Input :

// 6
// 1 3 2 -5 6 4  
// 5
// 0 5
// 2 3
// 1 2
// 3 5
// 4 5

// Sample Output :

// -5
// -5
// 2
// -5
// 4