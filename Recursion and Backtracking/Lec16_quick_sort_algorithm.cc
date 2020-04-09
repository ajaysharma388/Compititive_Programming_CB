#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
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
	cin.tie(0);
	cout.tie(0);
	return;
}

// Time Complexity of this function O(NLogN).

int partition(vector<int> &arr,int s,int e) {
	int i = s-1;
	for(int j = s; j < e; ++j) {
		if(arr[j] <= arr[e]) {
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[e]);
	return i+1;
}


void quicksort(vector<int> &arr,int s,int e) {
	if(s>=e) return;
	// Partition the array into two segments.
	// And Find The pivot Element. 
	int p = partition(arr,s,e);
	// now call quick sort on left segment.
	quicksort(arr,s,p-1);
	// now call quick sort on right segment.
	quicksort(arr,p+1,e);
	return;
}


int main(){
	fastio(true);
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	quicksort(arr,0,n-1);
	for(int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	return 0;
}

// Sample Input :

// 10
// 8 7 3 9 1 5 4 6 2 10

// Sample Input :

// 1 2 3 4 5 6 7 8 9 10 