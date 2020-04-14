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
	int *lazy;
	int size;
public:
	SegmentTree(const int n) {
		// It has been already proved that the size of the segment 
		// Tree will not exceed more than 4*n+1.
		this->size = 4*n+1;
		this->tree = new int[this->size]();
		this->lazy = new int[this->size]();
		this->lastIdx = -1;
	}
	void buildTree(int *arr,int s,int e,int index = 1) {
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
	int QueryTree(int s,int e,int qs,int qe,int index = 1) {
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
	int QueryLazy(int s,int e,int qs,int qe,int index = 1) {
		// Resolve the Lazy value first.
		if(this->lazy[index] != 0) {
			this->tree[index] += this->lazy[index];
			// If this node is not leaf node then forward lazy value.
			if(s != e) {
				this->lazy[2*index] = this->lazy[index];
				this->lazy[2*index+1] = this->lazy[index];
			}
			this->lazy[index] = 0;
		}
		// Here, we have to handle three cases.
		// 1. No overlap. return INT_MAX.
		if(qe < s or e < qs) return INT_MAX;
		// 1. Complete Overlap.
		if(s >= qs and qe >= e) return this->tree[index];
		// 3. Partial Overlap.
		// Call on both side.
		int m = (s+e)/2;
		// Left Result.
		int leftRes = QueryLazy(s,m,qs,qe,2*index);
		// right Result.
		int rightRes = QueryLazy(m+1,e,qs,qe,2*index+1);
		return min(leftRes,rightRes);
	}
	void updateRange(int s,int e,int l,int r,int inc,int index = 1) {
		// If we run out of bound.
		if(r < s or l > e) return;
		// If we have reached the leafnode then just update
		// it as it will be part of the range.
		if(s == e) {
			this->tree[index]+=inc;
			return;
		}
		// we will try to update left tree and the right tree.
		int m = (s+e)/2;
		// update in left subtree.
		updateRange(s,m,l,r,inc,2*index);
		updateRange(m+1,e,l,r,inc,2*index+1);
		// Update Parent nodes.
		this->tree[index] = min(this->tree[2*index],this->tree[2*index+1]);
		return;
	}
	void updateRangeLazy(int s,int e,int l,int r,int inc,int index = 1) {
		// If we went to a node whose lazy value is not 0.
		if(this->lazy[index] != 0) {
			this->tree[index] += this->lazy[index];
			// If this node is not leaf node then Pass lazy value to children.
			if(s!=e) {
				this->lazy[2*index] += this->lazy[index];
				this->lazy[2*index+1] += this->lazy[index];
			}
			this->lazy[index] = 0;
		}
		// If we are out of bound then just return.
		if(r < s or l > e) return;
		// If we have reached the node where in there is complete overlap.
		if(s >= l and r >= e) {
			this->tree[index] += inc;
			if(s != e) {
				this->lazy[2*index] += inc;
				this->lazy[2*index+1] += inc;
			}
			return;
		}
		// If not a complete overlap then just call on left and right segment.
		int m = (s+e)/2;
		// Recursive Call on left subtree.
		updateRangeLazy(s,m,l,r,inc,2*index);
		// Recursive Call on Right Subtree.
		updateRangeLazy(m+1,e,l,r,inc,2*index+1);
		this->tree[index] = min(this->tree[2*index],this->tree[2*index+1]);
		return;
	}
	void printTree() {
		for(int i = 1; i <= this->lastIdx; ++i)  
			cout << this->tree[i] << " ";
		cout << endl;
	}
	void printTreeData(int s,int e,int index = 1) {
		if(s == e) {
			cout << this->tree[index] << " ";
			return;
		}
		int m = (s+e)/2;
		printTreeData(s,m,2*index);
		printTreeData(m+1,e,2*index+1);
		return;
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
	t.buildTree(arr,0,n-1);
	t.printTreeData(0,n-1);
	cout << endl;
	t.updateRangeLazy(0,n-1,1,4,10);
	t.printTreeData(0,n-1);
	cout << endl;
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << t.QueryLazy(0,n-1,l,r) << endl;
	}
	return 0;
}

// Sample Input :

// 6
// 1 3 2 -5 6 4  

// Sample Output :

// 1 3 2 -5 6 4 
// 1 13 12 5 16 4 
// 1
// 5
// 12
// 4
// 4

// Lazy Result.

// 1 3 2 -5 6 4 
// 1 13 12 -5 6 4 
// 1
// 5
// 12
// 4
// 4