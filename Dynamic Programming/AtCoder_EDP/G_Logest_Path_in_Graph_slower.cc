#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define MAX 100001
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

int N, M;

int getMaxLengthPath(vector<int> graph[], int src) {
  queue<int> Q;
  int dis[N+1];
  int pathLen = 0;
  memset(dis, 0, sizeof dis);
  Q.push(src);
  dis[src] = 0;
  while(!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for(auto nbr : graph[cur]) {
      if(dis[nbr] < dis[cur]+1) {
        dis[nbr] = max(dis[nbr], dis[cur]+1);
        Q.push(nbr);
        pathLen = max(pathLen, dis[nbr]);
      }
    }
  }
  return pathLen;
}

void solve() {
  cin >> N >> M;
  vector<int> graph[N+1];
  for(int e = 1; e <= M; ++e) {
    int x, y;
    cin >> x >> y;
    graph[x].pb(y);
  }
  int ans = INT_MIN;
  for(int i = 1; i <= N; ++i) {
    ans = max(ans, getMaxLengthPath(graph, i));
  }
  cout << ans << endl;
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
// 4 5
// 1 2
// 1 3
// 3 2
// 2 4
// 3 4
// 6 3
// 2 3
// 4 5
// 5 6
// 5 8
// 5 3
// 2 3
// 2 4
// 5 2
// 5 1
// 1 4
// 4 3
// 1 3

// Sample Output :

// Case #1 :3
// Case #2 :2
// Case #3 :3