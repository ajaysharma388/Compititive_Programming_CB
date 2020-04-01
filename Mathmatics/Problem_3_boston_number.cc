#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isPrime(ll num) {
	if(num == 2) return true;
	if(num%2==0) return false;
	for(ll i = 3;i*i<=num; i+=2) {
		if(num%i == 0) return false;
	}
	return true;
}

ll getDigitSum(ll A) {
	ll resA = 0;
	while(A) {
		resA += (A%10);
		A/=10;
		if(resA > 10) {
			A = A+resA%10;
			resA/=10;
		}
	}
	return resA;
}

bool primeFactors(ll num) {
	ll no = num;
	ll ans = 0;
	ll sq = sqrt(num);
	for(ll i = 2; i <= sq;) {
		if(num == 1) break;
		else if(num%i == 0 and isPrime(i)) {
			ans += i;
			num = num/i;
		} else {
			i++;
		}
	}
	if(num > 1 and isPrime(num)) {
		ans+=num;
	}
	return getDigitSum(ans) == getDigitSum(no);
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while(t--) {
		ll num;
		cin >> num;
		(primeFactors(num)) ? cout << "1" << endl : cout << "0" << endl; 
	}
	return 0;
}

// Sample Input :

// 4
// 58
// 85
// 22
// 378

// Sample Output :

// 1
// 1
// 1
// 1