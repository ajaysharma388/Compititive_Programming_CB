#include <iostream>
#include <stdio.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
#define endl "\n"

void fastio(bool read = false) {
  if(read) {
  	#ifndef ONLINE_JUGDE
  	freopen("input.txt","r",stdin);
  	freopen("output.txt","w",stdout);
  	freopen("error.txt","w",stderr);
  	#endif
  }
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

void towerOfHanio(int n,char src,char dest,char helper) {
  // Base Case.
  if(n == 0) return;
  // 1. Move N-1 Disk from Src to Helper.
  towerOfHanio(n-1,src,helper,dest);
  // 2. Move the Nth Disk From Src to Dest.
  cout << "Moving " << n << "th Disk from " << src << " to " << dest << endl;
  // 3. Move N-1 Disk from Helper to Dest.
  towerOfHanio(n-1,helper,dest,src);
  return;
}

int main() {
  int n;
  cin >> n;
  towerOfHanio(n,'A','C','B');
  return 0;
}
