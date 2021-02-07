#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

typedef tree< int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update > PDBS;

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

int main() {
  PDBS st;
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
      int tmp; cin >> tmp;
      st.insert(tmp);
  }
  for(int i = 0; i < n; ++i) {
      cout << i << " Location Contains => " << *(st.find_by_order(i)) << endl;
  }
  return 0;
}


// Sample Input :

// 6
// 12
// 2
// 33
// 45
// 89
// 21

// Sample Output :

// 0 Location Contains => 2
// 1 Location Contains => 12
// 2 Location Contains => 21
// 3 Location Contains => 33
// 4 Location Contains => 45
// 5 Location Contains => 89