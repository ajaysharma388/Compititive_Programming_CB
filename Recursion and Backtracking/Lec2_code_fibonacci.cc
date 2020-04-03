#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// This is recursive code.

int fib(int n) {
	if(n == 0 or n == 1) return n;
	return fib(n-1) + fib(n-2);
}

// top down DP.

int fibTopDown(int n,int *dp) {
	if(n == 0 or n == 1) return dp[n] = n;
	if(dp[n] != -1) return dp[n];
	dp[n] = fib(n-1) + fib(n-2);
	return dp[n];
}

// bottom up dp.

int fibBottomUp(int n) {
	int dp[n+1];
	memset(dp,0,sizeof dp);
	dp[1] = 1;
	for(int i = 2; i <= n; ++i) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

vector<vector<int>> multiply(vector<vector<int>> A,vector<vector<int>> B) {
	vector<vector<int>> C(3,vector<int>(3,0));
	for(int i = 1; i <= 2; ++i) {
		for(int j = 1; j <= 2; ++j) {
			for(int k = 1; k <= 2; ++k) {
				C[i][j] += (A[i][k]*B[k][j]);
			}
		}
	}
	return C;
}

vector<vector<int>> power(vector<vector<int>> A,int n) {
	if(n == 1) return A;
	if(n & 1) return multiply(A,power(A,n-1));
	vector<vector<int>> res = power(A,n/2);
	return multiply(res,res);
}

// using matrix exponentiation.

int matExponentiation(vector<int>&b,vector<int>&c,int k) {
	// 1. form the vector F1.
	int n = b.size();
	vector<int> F1(n+1,0);
	for(int i = 1; i <= n; ++i) {
		F1[i] = b[i-1];
	}
	// 2. Find T matrix.
	vector<vector<int>> T(n+1,vector<int>(n+1,0));
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i < n) {
				if(i+1 == j) T[i][j] = 1;
				else T[i][j] = 0;
				continue;				
			}
			T[i][j] = c[n-j];
		}	
	}
	// 3. Find The value of T^n-1.
	T = power(T,k);
	// 4. multiply F1 with T.
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += T[1][i] * F1[i];
	}
	return ans;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int *dp = new int[n+1];
	for(int i = 0; i <= n; ++i) {
		dp[i] = -1;
	}
	cout << fib(n) << endl;
	cout << fibTopDown(n,dp) << endl;
	cout << fibBottomUp(n) << endl;
	vector<int> b = {0,1};
	vector<int> c = {1,1};
	cout << matExponentiation(b,c,n) << endl;
	return 0;
}

// Sample Input :

// 13

// Sample Output :

// 233
// 233
// 233
// 233