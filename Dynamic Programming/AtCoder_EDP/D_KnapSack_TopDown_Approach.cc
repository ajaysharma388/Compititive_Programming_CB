#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

vector<pair<int,int>> availableOpt(105);

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

int getTheMaxValue(int i, int capacity, vector<vector<int>> &dp) {
  if(i < 0 or capacity <= 0) return 0;
  if(dp[i][capacity] != -1) return dp[i][capacity];
  // 1. Will take.
  int ansA = INT_MIN;
  if(capacity - availableOpt[i].first >= 0)
    ansA = availableOpt[i].second + getTheMaxValue(i-1, capacity - availableOpt[i].first, dp);
  // 2. We Will Skip.
  int ansB = getTheMaxValue(i-1, capacity, dp);
  return dp[i][capacity] = max(ansA,ansB);
}

void solve() {
  int N, W;
  cin >> N >> W;
  for(int i = 0; i < N; ++i) {
    int w, v;
    cin >> w >> v;
    availableOpt[i] = {w, v};
  }
  vector<vector<int>> dp(N, vector<int>(W+1,-1));
  cout << getTheMaxValue(N-1, W , dp) << endl;
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