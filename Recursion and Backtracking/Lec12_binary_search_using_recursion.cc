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

int binarySearch(int*a,int s,int e,int key) {
  if(s>e) return -1;
  int m = (s+e)/2;
  if(a[m] == key) return m;
  // serching in the left part.
  if(a[m] > key) return binarySearch(a,s,m-1,key);
  // searching in the right part.
  return binarySearch(a,m+1,e,key);
}

int main(){
	fastio(false);
	int n;
	cin >> n;
	int a[n]={};
	for(int i=0;i<n;++i) cin>>a[i];
  int testCases;
  cin >> testCases;
  while(testCases--){
    int item;
    cin >> item;
    cout << binarySearch(a,0,n-1,item) << endl;
  }
	return 0;
}

// Sample Input :

// 10
// 1 2 3 11 14 25 83 101 122 136
// 2
// 36
// 14

// Sample Output :

// -1
// 4
