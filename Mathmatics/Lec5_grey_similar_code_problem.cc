#include<bits/stdc++.h>
#define ll unsigned long long
#define vi vector<int>
#define Fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
using namespace std;

int main(){
	Fastio
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	int n;cin>>n;
	vector<ll> arr;
	
	arr.reserve(130);
	for (int i = 0; i < n; ++i) {	
		ll a; cin>>a;
		if(n<130)
			arr.push_back(a);
	}


	if(n>=130){
		cout<< "Yes";
		return 0;
	}
	for (int i = 0; i < n-3; ++i) {
		for (int j = i+1; j < n-2; ++j) {
			for (int k = j+1; k < n-1; ++k) {
				for (int l = k+1; l < n; ++l) {
			 		if((arr[i]^arr[j]^arr[k]^arr[l]) == 0){
			 			cout<< "Yes";
						return 0;
			 		}
				}
			}
		}
	}

	
	cout<<"No";
	return 0;
}