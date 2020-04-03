#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
#define endl "\n"

void fastio() {
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

bool isSorted(int*arr,int n) {
	if(n == 1) return true;
	if(arr[0] <= arr[1]) return isSorted(arr+1,n-1);
	return false;
} 

int main(){
	fastio();
	int n;
	cin >> n;
	int* arr = new int[n]();
	for(int i = 0 ; i < n; ++i) {
		cin >> arr[i];
	} 	
	if(isSorted(arr,n)) cout << "The Input Array is Sorted." << endl;
	else cout << "The Input Array is not Sorted." << endl;
	return 0;
}