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

char grid[1002][1002];
int dp[1002][1002];
int H, W;

int getTtlPathsTD(int i, int j) {
  // Base Case If we move out of grid.
  if(i <= 0 or j <= 0) return 0;
  // If grid is blocked then No Path from here.
  if(grid[i][j] == '#') return dp[i][j] = 0;
  // If we have encountred the Path.
  if(i == 1 and j == 1) return dp[i][j] = 1;
  // If we already Know the Paths till this pt.
  if(dp[i][j] != -1) return dp[i][j];
  // If we don't Know the Paths till this pt.
  int ansA = getTtlPathsTD(i-1, j) % MOD;
  int ansB = getTtlPathsTD(i, j-1) % MOD;
  dp[i][j] = (ansA + ansB) % MOD;
  return dp[i][j];
}

int getTtlPathsBU() {
  int i = 1, j = 1;
  dp[i][j] = 1;
  for(int i = 2; i <= H; ++i) {
    if(grid[i][1] == '#') break;
    else dp[i][1] = 1;
  }
  for(int i = 2; i <= W; ++i) {
    if(grid[1][i] == '#') break;
    else dp[1][i] = 1;
  }
  for(int i = 2; i <= H; ++i) {
    for(int j = 2; j <= W; ++j) {
      if(grid[i][j] == '#') continue;
      dp[i][j] = ((dp[i-1][j] % MOD) + (dp[i][j-1] % MOD)) % MOD;
    }
  }
  return dp[H][W];
}

int32_t main() {
  fastio();
  cin >> H >> W;
  for(int h = 1; h <= H; ++h) {
    for(int w = 1; w <= W; ++w) {
      cin >> grid[h][w];
      dp[h][w] = 0;
    }
  }
  cout << getTtlPathsBU() << endl;
  return 0;
}


// Sample Input :

// 5 5
// ..#..
// .....
// #...#
// .....
// ..#..

// 20 20
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................
// ....................



// Sample Output :

// 24
// 345263555

// https://ide.codingblocks.com/s/449865
