/**********************************************
* AUTHOR : AJAY SHARMA, ajay2201@gmail.com    *
* Github Username : ajaysharma388             *
**********************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000000
#define N 100005
#define pb push_back
#define mp make_pair
#define F first
#define S second


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

vector<int> b, c;
int k, n;

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> C(k+1, vector<int>(k+1,0));
	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) {
			for(int x = 1; x <= k; ++x) {
				C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
			}
		}
	}
 	return C;
}

vector<vector<int>> pow(vector<vector<int>> A, int n) {
	if(n == 1) return A;
	if(n&1) {
		return multiply(A, pow(A,n-1));
	} 
	vector<vector<int>> Res = pow(A, n/2);
	return multiply(Res, Res);
}


int matExponentiation() {
	if(n == 0) return 0;
	if(n <= k) return b[n-1];
	// Step 1. Calculate F1 vector.
	vector<int> F1(k+1, 0);
	for(int i = 1; i <= k; ++i) {
		F1[i] = b[i-1];
	}
	// Step 2. Create Transformation Matrix.
	vector<vector<int>> Tn(k+1, vector<int>(k+1, 0));
	vector<vector<int>> Tm(k+1, vector<int>(k+1, 0));

	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) {
			if(i < k) {
				if(j == i+1) {
					Tn[i][j] = 1;
				} else {
					Tn[i][j] = 0;
				}
			} else {
				Tn[i][j] = c[k-j];
			} 
		}
	}
	// Step 3. Calculating the nth and kth pow mat.
	Tn = pow(Tn, n-1);

	// Step 4. Calculate Sm, Sn.
	int Fn = 0;
	for(int i = 1; i <= k; ++i) {
		Fn  = (Fn + (Tn[1][i] * F1[i])%MOD)%MOD;
	}
	return Fn;
}

int32_t main() {
	fastio(true);
	int testCases; cin >> testCases;
	while(testCases--) {
		cin >> k;
		for(int i = 0; i < k; ++i) {
			int num; cin >> num;
			b.pb(num);
		}
		for(int i = 0; i < k; ++i) {
			int num; cin >> num;
			c.pb(num);
		}
		cin >> n;
		cout << matExponentiation() << endl;
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