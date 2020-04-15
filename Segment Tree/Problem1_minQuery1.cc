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
	int *tree;
	int size;
	int index;
public:
	SegmentTree(const int size) {
		this->size = 4*size+1;
		this->tree = new int[this->size]();
		this->index = 0;
	}

	void buildTree(int s,int e,int *a,int index = 1) {
		if(s == e) {
			this->tree[index] = a[s];
			this->index = max(index,this->index);
			return;
		}
		int m = (s+e)/2;
		buildTree(s,m,a,2*index);
		buildTree(m+1,e,a,2*index+1);
		this->tree[index] = min(this->tree[2*index],this->tree[2*index+1]);
		return;
	}

	void update(int s,int e,int pos,int val,int index = 1) {
		if(pos < s or e < pos) return;
		if(s==e and s==pos) {
			this->tree[index] = val;
			return;
		}
		int m = (s+e)/2;
		update(s,m,pos,val,2*index);
		update(m+1,e,pos,val,2*index+1);
		this->tree[index] = min(this->tree[2*index],this->tree[2*index+1]);
		return;	 
	}

	int getMin(int s,int e,int qs,int qe,int index = 1) {
		if(qs<=s and qe>=e) return this->tree[index]; 
		if(qs>e or qe<s) return INT_MAX;
		int m = (s+e)/2;
		int l = getMin(s,m,qs,qe,2*index);
		int r = getMin(m+1,e,qs,qe,2*index+1);
		return min(l,r);
	}	

	void printTree() {
		for(int i = 1; i <= this->index; ++i) {
			cout << this->tree[i] << " "; 
		}
		cout << endl;
		return;
	}
};

int main() {
	fastio(true);
	int n,k;
	cin >> n >> k;
	int*a = new int[n]();
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	SegmentTree t(n);
	t.buildTree(0,n-1,a);
	while(k--) {
		int q,a,b;
		cin >> q >> a >> b;
		if(q == 1) {
			cout << t.getMin(0,n-1,a-1,b-1) << endl;
		} else {
			t.update(0,n-1,a-1,b);
		}
	}
	return 0;
}

// Sample Input :

// 5 5
// 1 4 3 5 2
// 1 1 5
// 2 3 9
// 1 2 4
// 1 2 5
// 1 3 4

// Sample Output :

// 1
// 4
// 2
// 5