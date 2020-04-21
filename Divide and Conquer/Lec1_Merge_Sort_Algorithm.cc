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


void merge(int *arr,int s,int e) {
	// Calculating mid.
	int m = (s+e)/2;
	// initialising index's pointer's to iterate in to sorted
	// halfs.
	int i = s;
	int k = 0;
	int j = m+1;
	// since mersort is not inplace sorting technique
	// allocating space.
	int *temp = new int[e-s+1]();
	// comparing both the half and storing the min element in the 
	// temp array.
	while(i <= m and j <= e) 
	if(arr[i] <= arr[j]) temp[k++] = arr[i++];
	else temp[k++] = arr[j++];
	// if right part is exausted.
	while(i <= m) temp[k++] = arr[i++];
	// if left part exausted.
	while(j <= e) temp[k++] = arr[j++];
	// copying the sorted result.
	for(int i = 0; i <= (e-s); ++i) 
		arr[i+s] = temp[i];
	delete[] temp;
	return;
}

void mergesort(int *arr,int s,int e) {
	// Base case.
	if(s >= e) return;
	// calculating mid.
	int m = (s+e)/2;
	// sorting left segment.
	mergesort(arr,s,m);
	// sorting right segment.
	mergesort(arr,m+1,e);
	// merging the two sorted segments.
	merge(arr,s,e);
	return;
}

int main(){
	fastio(true);
	int n;
	cin >> n;
	int*arr = new int[n]();
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

// 20
// 8 9 1 10 7 5 4 6 2 3 11 19 20 18 17 15 13 14 12 16

// Sample Output :

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20