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

struct Item {
  int value;
  int weight;
};

int getTheMaxValue(int N, int W, vector<Item> &availableOpt) {
   int R = (N * 1000) + 1;
   vector<vector<int>> dp(N+1, vector<int>(R));
   for(int i = 0; i <= R; ++i)
    dp[1][i] = 1e9+7;
   // Base Cases.
   dp[1][0] = 0;
   dp[1][availableOpt[1].value] = availableOpt[1].weight;
   // Evaluating the next states.
   for(int i = 2; i <= N; ++i)
     for(int vi = 0; vi <= R; ++vi) {
        dp[i][vi] = dp[i-1][vi];
        if(availableOpt[i].value > vi) continue;
        dp[i][vi] = min(dp[i][vi], availableOpt[i].weight + dp[i-1][vi - availableOpt[i].value]);
     }
   int ans = 0;
   for(int x = 0; x <= R; ++x)
     if(dp[N][x] <= W)
       ans = max(x, ans);
   return ans;
}

void solve() {
  int N, W;
  cin >> N >> W;
  vector<Item> availableOpt(N+1);
  for(int i = 1; i <= N; ++i)
    cin >> availableOpt[i].weight >> availableOpt[i].value;
  cout << getTheMaxValue(N, W, availableOpt) << endl;
}

int32_t main() {
  fastio();
  int testcase;
  cin >> testcase;
  for(int t = 1; t <= testcase; ++t) {
    cout << "Case #" << t << " :";
    solve();
  }
  return 0;
}


// Sample Input :

// 3
// 3 8
// 3 30
// 4 50
// 5 60
// 1 1000000000
// 1000000000 10
// 6 15
// 6 5
// 5 6
// 6 4
// 6 6
// 3 5
// 7 2

// Sample Output :

// Case #1 :90
// Case #2 :10
// Case #3 :17
