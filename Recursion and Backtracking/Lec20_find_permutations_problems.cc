#include <bits/stdc++.h>
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

void permute(char*input,int i) {
	if(input[i] == '\0') {
		cout << input << ", ";
		return;
	}
	for(int j = i; input[j] != '\0'; ++j) {
		swap(input[i],input[j]);
		permute(input,i+1);
		// backtracking step.
		swap(input[i],input[j]);
	}
	return;
}

int main() {
	fastio(true);
	char input[100];
	cin >> input;
	permute(input,0);
	return 0;
}

// Sample Input :

// abc

// Sample Output :

// abc, acb, bac, bca, cba, cab, 