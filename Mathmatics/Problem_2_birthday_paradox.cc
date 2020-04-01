#include<iostream>
using namespace std;
typedef long long int ll;

ll minNoPeople(double p) {
	ll person = 0;
	double possible = 1;
	double num = 365;
	double deno = 365;
	// 1. person birthday
	// 1/365 * 
	while(possible > (1-p)) {
		possible *= (num/deno);
		num--;
		person++;
	}
	return person;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double p;
	cin >> p;
	cout << minNoPeople(p) << endl;
	return 0;
}