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

void subsequences(char*input,char*output,int i,int j) {
	if(input[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}
	// Exclude The current character.
	subsequences(input,output,i+1,j);
	// Include The current character.
	output[j] = input[i];
	subsequences(input,output,i+1,j+1);
	return;
}

int main() {
	fastio(true);
	char input[100];
	char output[100];
	cin >> input;
	subsequences(input,output,0,0);
	return 0;
}

// Sample Input :

// abc

// Sample Output :

// 
// c
// b
// bc
// a
// ac
// ab
// abc