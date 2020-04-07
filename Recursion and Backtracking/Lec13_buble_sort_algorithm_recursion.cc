#include <iostream>
#include <stdio.h>
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

// this is purely iterative implementation of bubble sort
// algorithm time complexity is of the order O(N^2).
// Space Complexity of this implementation is of the order O(1).

void bubbleSort1(int*a,int n) {
  for(int i = 0; i < n-1; ++i) {
    for(int j = 0; j < n - i - 1; ++j) {
      if(a[j] > a[j+1]) swap(a[j] , a[j+1]);
    }
  }
}

// this is partially recursive implementation of bubble sort
// algorithm time complexity is of the order O(N^2).
// Space Complexity of this implementation is of the order O(N).

void bubbleSort2(int*a,int n) {
  if(n == 1) return;
  for(int i = 0; i < n-1; ++i) {
    if(a[i] > a[i+1]) swap(a[i] , a[i+1]);
  }
  bubbleSort2(a,n-1);
  return;
}

// This is fully recursive implementation of bubble sort algorithm.
// algorithm time complexity is of the order O(N^2).
// Space Complexity of this implementation is of the order O(N).
// eleminating the inner loop as well.

void bubbleSort3(int*a,int i,int n) {
  if(n == 1) return;
  if(i == n-1) {
    bubbleSort3(a,0,n-1);
    return;
  }
  if(a[i] < a[i+1]) swap(a[i] , a[i+1]);
  bubbleSort3(a,i+1,n);
  return;
}

int main(){
	fastio(false);
	int n;
	cin >> n;
	int a[n]={};
	for(int i=0;i<n;++i) cin>>a[i];
  bubbleSort1(a,n);
  for(int i=0;i<n;++i) cout << a[i] << " ";
  cout << endl;
  bubbleSort2(a,0,n);
  for(int i=0;i<n;++i) cout << a[i] << " ";
	return 0;
}

// Sample Input :

// 10
// 136 1 122 3 45 65 11 89 95 15

// Sample Output :

// 1 3 11 15 45 65 89 95 122 136
// 136 122 95 89 65 45 15 11 3 1
