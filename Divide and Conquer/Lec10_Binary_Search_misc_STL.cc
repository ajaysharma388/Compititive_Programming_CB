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

// In this problem we will try to count the frequency of
// any number using function's from standard template 
// Library.


int main() {
	fastio(true);
	int n;
	cin >> n;
	int*arr = new int[n];
	for(int i = 0; i < n; ++i) 
		cin >> arr[i];
	sort(arr,arr+n);
	for(int i = 0; i < n; ++i) 
		cout << arr[i] << " ";
	cout << endl; 
	auto it1 = lower_bound(arr,arr+n,8);
	auto it2 = upper_bound(arr,arr+n,8);
	int occurence = it2-it1;
	cout << "Frequency of 8 : " << occurence << endl; 
	return 0;
}

// Sample Input :

// 20
// 1 1 1 2 5 6 8 4 4 4 4 9 8 4 6 4 8 9 8 6

// Sample Output :

// 1 1 1 2 4 4 4 4 4 4 5 6 6 6 8 8 8 8 9 9 
// Frequency of 8 : 4