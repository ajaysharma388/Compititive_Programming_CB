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
  int weight;
  int value;
};

int calculateMaxprofit(std::vector<Item> &knapSack, int N, int W) {
  vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
  dp[1][knapSack[1].weight] = knapSack[1].value;
  for(int i = 2; i <= N; ++i) {
    for(int wt = 0; wt <= W; ++wt) {
      // This Case is for Not considering our current in knapSack.
      dp[i][wt] = dp[i-1][wt];
      // This Case is for considering our current in knapSack.
      if(wt < knapSack[i].weight) continue;
      dp[i][wt] = max(dp[i][wt], knapSack[i].value + dp[i-1][wt - knapSack[i].weight]);
    }
  }
  return *max_element(dp[N].begin() , dp[N].end());
}

void solve() {
  int N, W;
  cin >> N >> W;
  vector<Item> knapSack(N+1);
  for(int i = 1; i <= N; ++i) {
    cin >> knapSack[i].weight >> knapSack[i].value;
  }
  cout << calculateMaxprofit(knapSack, N, W) << endl;
  return;
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
// 5 5
// 1 1000000000
// 1 1000000000
// 1 1000000000
// 1 1000000000
// 1 1000000000
// 6 15
// 6 5
// 5 6
// 6 4
// 6 6
// 3 5
// 7 2
// 3 8
// 3 30
// 4 50
// 5 60

// Sample Output :

// Case #1 :5000000000
// Case #2 :17
// Case #3 :90