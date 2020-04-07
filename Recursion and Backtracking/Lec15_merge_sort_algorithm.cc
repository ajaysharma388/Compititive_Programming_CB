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

void merge(vector<int> &arr,int s,int e) {
	// Calculating the mid.
	int m = (s+e)/2;
	// Initialising the three pointers.
	int i = s;
	int j = m+1;
	int k = 0;
	// creating the temprary space.
	vector<int> temp(e-s+1,0);
	// merging the data.
	while(i <= m and j <= e) 
	if(arr[i] <= arr[j]) temp[k++] = arr[i++];
	else temp[k++] = arr[j++];
	// if second half is exausted.
	while(i <= m) temp[k++] = arr[i++];
	// if the first half is exausted.
	while(j <= e) temp[k++] = arr[j++];
	// finally we have the sorted data stored in temp.
	// we can simply copy the data.
	for(i = 0; i <= e-s; ++i) arr[s+i] = temp[i];
	return;
}


void mergesort(vector<int> &arr,int s,int e) {
	// Base Case.
	if(s >= e) {
		return; 
	}
	// Divide The array.
	int m = (s+e)/2;
	// sort The left Part.
	mergesort(arr,s,m);
	// sort The left Part.
	mergesort(arr,m+1,e);
	// merge the Two Sorted arrays.
	merge(arr,s,e);
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
	mergesort(arr,0,n-1);
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