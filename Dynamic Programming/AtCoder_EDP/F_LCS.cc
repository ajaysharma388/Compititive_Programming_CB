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

int getTheLengthOfLCSRec(string inpA, int i, string inpB, int j) {
  // Base case.
  if(i < 0 or j < 0) return 0;
  // Recursive.
  int ansA = INT_MIN;
  if(inpA[i] == inpB[j])
    ansA = max(ansA, 1 + getTheLengthOfLCSRec(inpA, i-1, inpB, j-1));
  int ansB = getTheLengthOfLCSRec(inpA, i-1, inpB, j);
  int ansC = getTheLengthOfLCSRec(inpA, i, inpB, j-1);
  return max(ansA, max(ansB, ansC));
}

int getTheLengthOfLCSTD(string inpA, int i, string inpB, int j, vector<vector<int>> &dp) {
  // Base case.
  if(i < 0 or j < 0) return 0;
  // Recursive.
  if(dp[i][j] != -1) return dp[i][j];
  int ansA = INT_MIN;
  if(inpA[i] == inpB[j])
    ansA = max(ansA, 1 + getTheLengthOfLCSRec(inpA, i-1, inpB, j-1));
  int ansB = getTheLengthOfLCSRec(inpA, i-1, inpB, j);
  int ansC = getTheLengthOfLCSRec(inpA, i, inpB, j-1);
  return dp[i][j] = max(ansA, max(ansB, ansC));
}

string getTheLCSTD(string inpA, int N, string inpB, int M, vector<vector<string>> &dp, int i, int j) {
  // Base case.
  if(i >= N or j >= M) return "";
  // Recursive.
  if(dp[i][j] != "\0") return dp[i][j];
  string ansA = "";
  if(inpA[i] == inpB[j])
    ansA = inpB[j] + getTheLCSTD(inpA, N, inpB, M, dp, i+1, j+1);
  string ansB = getTheLCSTD(inpA, N, inpB, M, dp, i+1, j);
  string ansC = getTheLCSTD(inpA, N, inpB, M, dp, i, j+1);
  if(ansA.length() > ansB.length()) {
    dp[i][j] = (ansA.length() > ansC.length()) ? ansA : ansC;
  } else {
    dp[i][j] = (ansB.length() > ansC.length()) ? ansB : ansC;
  }
  return dp[i][j];
}

void solve() {
  string inpA, inpB;
  cin >> inpA >> inpB;
  int N, M;
  N = inpA.length();
  M = inpB.length();
  vector<vector<int>> dp(N, vector<int>(M, -1));
  vector<vector<string>> dp_2(N, vector<string>(M, "\0"));
  cout << getTheLengthOfLCSRec(inpA, N-1, inpB, M-1) << ", ";
  cout << getTheLengthOfLCSTD(inpA, N-1, inpB, M-1, dp) << ", ";
  cout << getTheLCSTD(inpA, N, inpB, M, dp_2, 0, 0) << endl;
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

// 1
// axyb
// abyxb

// Sample Output :

// Case #1 :3, 3, axb