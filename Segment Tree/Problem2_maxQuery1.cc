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

class TreeNode {
	vector<int> vec;
public:
	TreeNode(){}
	void push(const int data) {
		vec.push_back(data);
	}
	int getSize() {
		return this->vec.size();
	}
	void merge(TreeNode*a,TreeNode*b) {
		int x = 0;
		int y = 0;
		int aSize = a->vec.size();
		int bSize = b->vec.size();
		while(x < aSize and y < bSize) {
			if(a->vec[x] <= b->vec[y]) this->vec.push_back(a->vec[x++]);
			else this->vec.push_back(b->vec[y++]);  
		}
		while(x < aSize) {
			this->vec.push_back(a->vec[x++]);  
		}
		while(y < bSize) {
			this->vec.push_back(b->vec[y++]);  
		}
		return;
	}

	int count(int l,int r,int k) {
		auto low = lower_bound(vec.begin(), vec.end(), k) - vec.begin();
		int n = vec.end() - vec.begin();
		return n-low;
	}
};


class SegmentTree {
	TreeNode **tree;
	int size;
	int index;
public:
	SegmentTree(const int size) {
		this->size = 4*size+1;
		this->tree = new TreeNode*[this->size]();
		for(int i = 0; i < this->size; ++i) {
			this->tree[i] = NULL;
		}
		this->index = 0;
	}

	void buildTree(int s,int e,int *a,int index = 1) {
		if(s == e) {
			this->tree[index] = new TreeNode();
			this->tree[index]->push(a[s]);
			this->index = max(index,this->index);
			return;
		}
		int m = (s+e)/2;
		buildTree(s,m,a,2*index);
		buildTree(m+1,e,a,2*index+1);
		this->tree[index] = new TreeNode();
		this->tree[index]->merge(this->tree[2*index],this->tree[2*index+1]);
		return;
	}

	void find(int s,int e,int qs,int qe,int k,int &ans,int index = 1) {
		// If no overlap then simple return.
		if(qs > e or qe < s) return;
		// complete overlap.
		if(qs<=s and qe>=e) {
			ans += this->tree[index]->count(qs,qe,k);
			return;
		}
		// Partial Overlap.
		int m = (s+e)/2;
		find(s,m,qs,qe,k,ans,2*index);
		find(m+1,e,qs,qe,k,ans,2*index+1);
		return;
	}
};


int main() {
	fastio(true);
	int n,k;
	cin >> n;
	int*a = new int[n]();
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	SegmentTree t(n);
	t.buildTree(0,n-1,a);
	cin >> k;
	while(k--) {
		int l,r,k,ans = 0;
		cin >> l >> r >> k;
		t.find(0,n-1,l-1,r-1,k,ans);
		cout << ans << endl;
	}
	return 0;
}