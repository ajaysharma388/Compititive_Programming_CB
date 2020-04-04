#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
#define endl "\n"

void fastio() {
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

// Time Complexity : O(B)
// Space Complexity : O(B)

vector<string> names = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};


void numberName(string s,int i) {
	if(i == s.length()){
		cout << endl;
		return;
	}
	cout << names[s[i] - '0'] << " ";
	numberName(s,i+1);
	return;
}

int main(){
	fastio();
	ll t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		numberName(s,0);
	}
	return 0;
}

// Sample Input :

// 2
// 2048
// 7891

// Sample Output :

// two zero four eight 
// seven eight nine one 