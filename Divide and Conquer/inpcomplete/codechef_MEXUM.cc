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
class Node {
public:
	T minInRange;
	set<T> s;
	Node() {}
};


ll findMinElement(set<ll>&s1) {
	auto it = s1.end();
	it--; 
	ll n = *it + 1;
	for(ll i = 1; i <= n; ++i) {
		if(s1.find(i) == s1.end())
			return i;
	}
	return n;
}

ll maxIndex = 0;

void buildTree(ll*arr,Node<ll>**tree,ll s,ll e,ll index = 1) {
	if(s > e) {
		tree[index] = NULL;
		return;
	}
	maxIndex = max(maxIndex,index);
	if(s == e){
		tree[index] = new Node<ll>();
		tree[index]->s.insert(arr[s]);
		tree[index]->minInRange = (arr[s] == 1) ? 2 : 1;
		return;
	} 
	// recursive case.
	ll m = (s+e)/2;
	buildTree(arr, tree, s, m, 2*index);
	buildTree(arr, tree, m+1, e, 2*index+1);
	Node<ll> *leftNode = tree[2*index];
	Node<ll> *rightNode = tree[2*index+1];
	tree[index] = new Node<ll>();
	for(auto element : tree[index]->s) tree[index]->s.insert(element);
	for(auto element : tree[index]->s) tree[index]->s.insert(element);
	tree[index]->minInRange = findMinElement(tree[index]->s);
	return;
}

int main() {
	fastio(true);
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll *arr = new ll[n+1]();
		Node<ll> **tree = new Node<ll>*[4*n+1]();
		for(int i = 1; i <= n; ++i) 
			cin >> arr[i];
		for(int i = 1; i <= 4*n; ++i) 
			tree[i] = NULL;
		buildTree(arr,tree,1,n);
		for(int i = 1; i <= n; ++i) 
			cout << arr[i] << " ";
		cout << endl;
		cout << "Hello" << endl;
		cout << maxIndex << endl;
		// for(int i = 1; i < 4*n; ++i)
		// 	if(tree[i] != NULL)
			// cout << i << " : " << tree[i].s.size() << endl; 
	}
	return 0;
}