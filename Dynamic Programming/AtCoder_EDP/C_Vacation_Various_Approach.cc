#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

vector<vector<int>> happinessPt(100005, vector<int>(3, 0));
vector<vector<int>> dp(100005, vector<int>(3, -1));

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

int getMaxHapinessPointBU(int n) {
    for(int i = 0; i < 3; ++i) {
        dp[0][i] = happinessPt[0][i];
    }
    for(int i = 1; i < n; ++i) {
        dp[i][0] = happinessPt[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = happinessPt[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = happinessPt[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }
    return max(dp[n-1][2], max(dp[n-1][0], dp[n-1][1]));
}

int getMaxHapinessPointBUSpaceOptimised(int n) {
    // As this is the base case.
    for(int i = 0; i < 3; ++i) {
        cin >> dp[0][i];
    }
    int ai, bi, ci;
    for(int i = 1; i < n; ++i) {
        cin >> ai >> bi >> ci;
        dp[i][0] = ai + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = bi + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = ci + max(dp[i-1][0], dp[i-1][1]);
    }
    return max(dp[n-1][2], max(dp[n-1][0], dp[n-1][1]));
}

int getMaxHapinessPointBUSpaceOptimisedSuper(int n) {
    // As this is the base case.
    int ai, bi, ci, di, ei, fi;
    cin >> ai >> bi >> ci;
    int curAcctivity[3];
    for(int i = 1; i < n; ++i) {
        cin >> di >> ei >> fi;
        curAcctivity[0] = di + max(bi, ci);
        curAcctivity[1] = ei + max(ai, ci);
        curAcctivity[2] = fi + max(ai, bi);
        ai = curAcctivity[0], bi = curAcctivity[1], ci = curAcctivity[2];
    }
    return max(ai, max(bi, ci));
}

int32_t main() {
  fastio();
  int testcases;
  cin >> testcases;
  for(int t = 1; t <= testcases; ++t) {
      int N;
      cin >> N;
      for(int i = 0; i < N; ++i)
          for(int j = 0; j < 3; ++j)
              cin >> happinessPt[i][j];
      int result = getMaxHapinessPointBU(N);
      int result_1 = getMaxHapinessPointBUSpaceOptimised(N);
      int result_2 = getMaxHapinessPointBUSpaceOptimisedSuper(N);
      cout << "Case #" << t << " : " << result << " " << result_1 << " " << result_2 << endl;
  }
  return 0;
}

// Sample Input :

// 2
// 3
// 10 40 70
// 20 50 80
// 30 60 90
// 10 40 70
// 20 50 80
// 30 60 90
// 10 40 70
// 20 50 80
// 30 60 90
// 7
// 6 7 8
// 8 8 3
// 2 5 2
// 7 8 6
// 4 6 8
// 2 3 4
// 7 5 1
// 6 7 8
// 8 8 3
// 2 5 2
// 7 8 6
// 4 6 8
// 2 3 4
// 7 5 1
// 6 7 8
// 8 8 3
// 2 5 2
// 7 8 6
// 4 6 8
// 2 3 4
// 7 5 1

// Sample Output :

// Case #1 : 210 210 210
// Case #2 : 46 46 46
