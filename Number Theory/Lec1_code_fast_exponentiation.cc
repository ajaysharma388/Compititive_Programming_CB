#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


int fast_exponentiation(int a,int b) {
	// Base Case.
	if(b == 0) return 1;
	int ans = fast_exponentiation(a,b/2);
	ans *= ans;
	return (b & 1) ? a*ans : ans;  
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin >> a >> b;
	cout << fast_exponentiation(a,b) << endl; 
	return 0;
}

// Sample Input :

// 3 3 

// Sample Output :

// 27