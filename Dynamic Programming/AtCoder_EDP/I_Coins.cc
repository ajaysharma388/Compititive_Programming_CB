#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define pb push_back
#define MOD 1000000007

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

int N;
double ar[3001];
double dp[3001][3001];

double getProbabiltyOfGettingHeads(int N, int i, int x) {
  // Base Case.
  if(x == 0) return 1;
  // if I have no coin to toss.
  if(i == 0) return 0;
  // if subproblem is already calculated.
  if(dp[i][x] > -0.9) return dp[i][x];
  dp[i][x] = ar[i]*getProbabiltyOfGettingHeads(N, i-1, x-1) + (1-ar[i])*getProbabiltyOfGettingHeads(N, i-1, x);
  return dp[i][x];
}

int32_t main() {
  fastio();
  cin >> N;
  for(int i = 1; i <= N; ++i) {
    cin >> ar[i];
  }
  memset(dp, -1, sizeof dp);
  cout << fixed << setprecision(10) << getProbabiltyOfGettingHeads(N, N, (N+1)/2) << endl;
  return 0;
}


// Sample Input :

// 5
// 0.42 0.01 0.42 0.99 0.42
// 3
// 0.30 0.60 0.80


// Sample Output :

// 0.3821815872
// 0.612


