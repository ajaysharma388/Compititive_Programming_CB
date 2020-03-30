#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vii vector<vector<ll>>
#define vi vector<ll>
#define MOD 1000000000
#define endl "\n"

ll k;
vi b,c;

vii multiply(vii A,vii B) {
	vii C(k+1,vi(k+1,0));
	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) {
			for(int x = 1; x <= k; ++x) {
				C[i][j] = (C[i][j] + (A[i][x]*B[x][j]) % MOD) % MOD;
			}
		}
	}
	return C;
}

vii pow(vii A,ll n) {
	// Base Case.
	if(n == 1) return A;
	if(n & 1) return multiply(A , pow(A,n-1));
	vii B = pow(A,n/2);
	return multiply(B,B);
}


ll compute(ll n) {
	// base case.
	if(n == 0) return 0;
	if(n <= k) return b[n-1];
	// 1. form the F1 vector.
	vi F1(k+1,0);
	for(int i = 1; i <= k; ++i) {
		F1[i] = b[i-1];
	}
	// 2. form the transformation vector.
	vii T( k+1,vi (k+1,0));
	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) {
			if(i < k) {
				if(i+1 == j) T[i][j] = 1;
				else T[i][j] = 0;
				continue;
			}
			T[i][j] = c[k-j];
		}
	}
	// 3. Find T^n-1
	T = pow(T,n-1);
	// 4. Now multiply the each element in the first row of 
	//    T^n-1 with every element in the F1.
	ll result = 0;
	for(int i = 1; i <= k; ++i) {
		result = (result + (T[1][i] * F1[i]) % MOD) % MOD;
	}
	return result;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n,num;
	cin >> t;
	while(t--) {
		cin >> k;
		// taking first K terms as the input.
		for(int i = 0; i < k; ++i) {
			cin >> num;
			b.push_back(num);
		}
		// taking first K coefficients as the input.
		for(int i = 0; i < k; ++i) {
			cin >> num;
			c.push_back(num);
		}
		cin >> n;
		cout << compute(n) << endl;
		b.clear();
		c.clear();
	}	
	return 0;
}

// Sample Input :

// 3
// 3 
// 5 8 2 
// 32 54 6 
// 2 
// 3 
// 1 2 3 
// 4 5 6 
// 6 
// 3 
// 24 354 6 
// 56 57 465 
// 98765432


// Sample Output :

// 8
// 714
// 257599514