#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

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

int getMinCost(int n, int k, vector<int> &stoneHei) {
  vector<int> dp(n,INT_MAX);
  // for moving first k steps.
  dp[0] = 0;
  // for moving from k to N.
  for(int i = 1; i < n; ++i) {
    for(int x = 1; x <= k; ++x) {
      if(i-x >= 0) {
        int cur_Ans = abs(stoneHei[i] - stoneHei[i-x]) + dp[i-x];
        dp[i] = min(dp[i], cur_Ans);
      }
    }
  }
  return dp[n-1];
}

int32_t main() {
  int testcases;
  cin >> testcases;
  for(int t = 1; t <= testcases; ++t) {
      int N, K;
      cin >> N >> K;
      vector<int> stoneHei(N,0);
      for(int i = 0; i < N; ++i) {
        cin >> stoneHei[i];
      }
      cout << "Case #" << t << " :" << getMinCost(N, K, stoneHei) << endl;
    // cout << getMinCost(N, stoneHei);
  }
  return 0;
}

// Sample Input :

// 4
// 5 3
// 10 30 40 50 20
// 3 1
// 10 20 10
// 2 100
// 10 10
// 10 4
// 40 10 20 70 80 10 20 70 80 60


// Sample Output :

// Case #1 :30
// Case #2 :20
// Case #3 :0
// Case #4 :40