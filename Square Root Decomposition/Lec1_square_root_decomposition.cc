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

int* build1(int *arr,int n,int sq) {
	// we have constructed the blocks array.
	int *blocks = new int[sq+1]();
	for(int i = 0; i <= sq; ++i)
		for(int j = i*sq; j < ((i*sq) + sq) and j < n; ++j) 
			blocks[i] += arr[j];
	return blocks;	
}

int* build2(int *arr,int n,int sq) {
	// we have constructed the blocks array.
	int *blocks = new int[sq+1]();
	int block_Id = -1;
	for(int i = 0; i < n; ++i) {
		if(i % sq == 0) block_Id++;
		blocks[block_Id] += arr[i];
	}
	return blocks;	
}


// time complexity of this method is of the order O(N^(1/2))

int query(int *blocks,int *arr,int sq,int l,int r) {
	int sum = 0;
	// partial initial block.
	while(l < r and l != 0 and l % sq != 0) {
		sum += arr[l];
		l++;
	} 
	// complete blocks.
	while(l+sq <= r) {
		int id = l/sq;
		sum += blocks[id];
		l += sq;
	}
	// partial ending blocks.
	while(l <= r) {
		sum += arr[l];
		l++;
	}
	return sum;
}

void update(int *blocks,int *arr,int sq,int index,int value) {
	int blockId = index/sq;
	blocks[blockId] += (value - arr[index]);
	arr[index] = value;
}
 
int main() {
	fastio(true);
	int n,k;
	cin >> n;
	int sq = sqrt(n);
	int *arr = new int[n]();
	for(int i = 0; i < n; ++i) 
		cin >> arr[i];
	int *blocks = build2(arr,n,sq);
	update(blocks,arr,sq,2,15);
	for(int i = 0; i < n; ++i) 
		cout << arr[i] << " ";
	cout << endl;
	cout << query(blocks,arr,sq,2,9) << endl;
	return 0;
}

// Sample Input :

// 10
// 1 3 5 2 7 6 3 1 4 8

// Sample Output :

// 1 3 15 2 7 6 3 1 4 8 
// 46