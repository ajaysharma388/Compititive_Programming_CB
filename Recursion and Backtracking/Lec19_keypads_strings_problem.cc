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

char keypad[10][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void keypadStrings(char*input,char*output,int i,int j) {
	if(input[i] == '\0') {
		output[j] = '\0';
		cout << output << " ,";
		return;
	}
	// fetching the current digit.
	int digit = input[i]-'0';
	// as we don't have any mapping with 0 and 1.
	// we will simply ignore them.
	if(digit == 0 or digit == 1) {
		keypadStrings(input,output,i+1,j);
	}
	// iterating over the all possible char that 
	// current digit can contribute to.
	for(int k = 0; keypad[digit][k] != '\0'; ++k) {
		output[j] = keypad[digit][k];
		keypadStrings(input,output,i+1,j+1);
	}
	return;
}

int main() {
	fastio(true);
	char input[100];
	char output[100];
	cin >> input;
	keypadStrings(input,output,0,0);
	return 0;
}

// Sample Input :

// 623

// Sample Output :

// MAD ,MAE ,MAF ,MBD ,MBE ,MBF ,MCD ,MCE ,MCF ,NAD ,NAE ,NAF ,NBD ,NBE ,NBF ,NCD ,NCE ,NCF ,OAD ,OAE ,OAF ,OBD ,OBE ,OBF ,OCD ,OCE ,OCF ,