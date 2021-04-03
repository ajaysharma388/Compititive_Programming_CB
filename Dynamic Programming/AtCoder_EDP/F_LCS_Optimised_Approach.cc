#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define MAX 3001
#define pb push_back

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

int dp[MAX][MAX];
string inpA, inpB;
int M, N;

int getTheLengthOfLCSTD( int i, int j) {
  // Base case.
  if(i >= N or j >= M) return 0;
  // Recursive.
  if(dp[i][j] != -1) return dp[i][j];
  if(inpA[i] == inpB[j]) {
    return dp[i][j] = 1 + getTheLengthOfLCSTD(i+1, j+1);
  } else {
    dp[i][j] = max(getTheLengthOfLCSTD(i+1, j), getTheLengthOfLCSTD(i, j+1));
  }
  return dp[i][j];
}

string getLCS(int len) {
    int i = 0, j = 0;
    string LCS = "";
    while(len) {
        if(inpA[i] == inpB[j]) {
            LCS.pb(inpA[i]);
            i++, j++;
            len--; 
        } else {
            if(dp[i+1][j] > dp[i][j+1]) i++;
            else j++;
        }
    }
    return LCS;
}

int32_t main() {
  fastio();
  cin >> inpA >> inpB;
  N = inpA.length();
  M = inpB.length();
  memset(dp, -1, sizeof dp);
  int lcsLen = getTheLengthOfLCSTD(0, 0);
  string LCS = getLCS(lcsLen);
  cout << LCS << endl;
  return 0;
}


// Sample Input :

// axyb
// abyxb
// abracadabra
// avadakedavra



// Sample Output :

// axb
// aaadara
