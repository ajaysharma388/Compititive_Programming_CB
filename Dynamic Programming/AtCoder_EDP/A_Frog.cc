#include <bits/stdc++.h>
using namespace std;

#define ll long long int
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

int getMinCost(int n, vector<int> &stoneHei) {
  vector<int> dp(n,0);
  dp[1] = abs(stoneHei[1] - stoneHei[0]);
  for(int i = 2; i < n; ++i) {
    // rec is possible.
    int ans_1 = abs(stoneHei[i] - stoneHei[i-2]) + dp[i-2];
    int ans_2 = abs(stoneHei[i] - stoneHei[i-1]) + dp[i-1];
    dp[i] = min(ans_1, ans_2);
  }
  return dp[n-1];
}

int main() {
  int testcases;
  cin >> testcases;
  for(int t = 1; t <= testcases; ++t) {
      int N;
      cin >> N;
      vector<int> stoneHei(N,0);
      for(int i = 0; i < N; ++i) {
        cin >> stoneHei[i];
      }
      cout << "Case #" << t << " :" << getMinCost(N, stoneHei) << endl;
  }
  return 0;
}

// Sample Input :

// 3
// 6
// 30 10 60 10 60 50
// 2
// 10 10
// 4
// 10 30 40 20

// Sample Output :

// Case #1 :40
// Case #2 :0
// Case #3 :30
