#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void fastio(bool read = true) {
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


int partition(int *arr,int s,int e) {
	int i = s-1;
	for(int j = s; j < e; ++j) 
		if(arr[j] < arr[e]) 
			swap(arr[++i],arr[j]);
	swap(arr[i+1],arr[e]);
	return i+1;
}

void quickSort(int *arr,int s,int e) {
	// Base case i.e, array has only one element or zero.
	if(s >= e) return;
	// calculate pivot element.
	int p = partition(arr,s,e);
	// calling on left part.
	quickSort(arr,s,p-1);
	// calling on right part.
	quickSort(arr,p+1,e);
	return;
}

int main(){
	fastio(true);
	int n;
	cin >> n;
	int*arr = new int[n]();
	for(int i = 0; i < n; ++i) 
		cin >> arr[i];
	quickSort(arr,0,n-1);
	for(int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

// Sample Input :

// 10
// 8 9 1 10 7 5 4 3 2 6

// Sample Output :

// 1 2 3 4 5 6 7 8 9 10 