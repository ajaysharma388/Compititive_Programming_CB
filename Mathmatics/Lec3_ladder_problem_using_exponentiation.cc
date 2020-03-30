#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
#define ll long long int
#define endl "\n"
#define vi vector<ll>
#define vii vector<vector<ll>>

// Time Complexity : O(K^N)
// Space Complexity : O(N)

ll ladder_rec(ll n,ll k) {
	// Base Cases.
	if(n < 0) return 0;
	if(n == 0) return 1;
	ll ans = 0;
	for(int i = 1; i <= k; ++i) {
		ans += ladder_rec(n-i,k);
	}
	return ans;
}

// Time Complexity : O(K*N)
// Space Complexity : O(N)

ll ladder_TDDP(ll n,ll k,ll *dp) {
	// Base Cases.
	if(n < 0) return 0;
	if(n == 0) return dp[n] = 1;
	if(dp[n] != -1) return dp[n];
	dp[n] = 0;
	for(int i = 1; i <= k; ++i) {
		dp[n] += ladder_TDDP(n-i,k,dp);
	}
	return dp[n];
}

// Time Complexity : O(k*N)
// Space Complexity : O(N)

ll ladder_BUDP1(ll n,ll k) {
	ll *dp = new ll[n+1];
	dp[0] = 1;
	for(int i = 1; i <= n; ++i) {
		dp[i] = 0;
		for(int c = 1; c <= k; ++c) {
			if(i-c >= 0) {
				dp[i] += dp[i-c];
			}
 		}
	}
	return dp[n];
}

// Time Complexity : O(N)
// Space Complexity : O(N)

ll ladder_BUDP2(ll n,ll k) {
	ll *dp = new ll[n+1];
	dp[0] = 1;
	dp[1] = 1;
	ll sum = dp[0] + dp[1];
	for(int i = 2; i <= n; ++i) {
		if(i <= k) {
			dp[i] = sum;
			sum += dp[i];
		} else {
			dp[i] = 2*dp[i-1] - dp[i-k-1];
		}
	}
	return dp[n];
}

// This Solution uses matrix exponentiation technique
// Time Complexity : O(k^3 log2(N))
// Space Complexity : O(N)


vii multiply(vii A,vii B,ll k) {
	vii C(k+1,vi(k+1,0));
	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) {
			for(int c = 1; c <= k; ++c) {
				C[i][j] += (A[i][c]*B[c][j]);
			}
		}
	}
	return C;
}

vii power(vii A,ll n,ll k) {
	// Base Case.
	if(n == 1) return A;
	if(n & 1) return multiply(A,power(A,n-1,k),k);
	vii res = power(A,n/2,k);
	return multiply(res,res,k);
}

ll matrixExp(vi b,vi c,ll n,ll k) {
	// 1. form the F1
	vi F1(k+1);
	for(int i = 1; i <= k; ++i) {
		F1[i] = b[i-1];
	}
	// 2. form the transportation matrix.
	vii T(k+1,vi(k+1));
	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) {
			if(i != k) {
				if(i+1 == j) T[i][j] = 1;
				else T[i][j] = 0;
				continue;
			} 
			T[i][j] = c[k-j];
		}
	}
	// 3. Find T^n-1
	T = power(T,n-1,k);
	// 4. find the multiplication of first row with every element
	//    of F1.
	ll result = 0;
	for(int i = 1; i <= k; ++i) {
		result += (T[1][i]*F1[i]);
	} 
	return result;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);+
	cin.tie(NULL);
	ll n,k;
	cin >> n >> k;
	ll *dp = new ll[n+1];
	for(int i = 0; i <= n; ++i) {
		dp[i] = -1;
	}
	cout << "Recursive Solun  : O(K^N) -> " << ladder_rec(n,k) << endl;
	cout << "TopDown DP  : O(KN) -> " << ladder_TDDP(n,k,dp) << endl;
	cout << "Bottom UP1  : O(KN) -> " << ladder_BUDP1(n,k) << endl;
	cout << "Bottom UP2  : O(N) -> " << ladder_BUDP2(n,k) << endl;
	vi b(k);
	vi c(k);
	for(int i = 0; i < k; ++i) {
		b[i] = dp[i+1]; 
	}
	for(int i = 0; i < k; ++i) {
		c[i] = 1; 
	}
	cout << "matrix exponentiation  : O(k^3 * log2(N)) -> " << matrixExp(b,c,n,k) << endl;
	return 0;
}

// Sample Input :

// 15 8

// Sample Output :

// Recursive Solun  : O(K^N) -> 16128
// TopDown DP  : O(KN) -> 16128
// Bottom UP1  : O(KN) -> 16128
// Bottom UP2  : O(N) -> 16128
// matrix exponentiation  : O(k^3 * log2(N)) -> 16128