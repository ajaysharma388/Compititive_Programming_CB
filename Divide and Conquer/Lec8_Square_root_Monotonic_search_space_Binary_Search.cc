#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUDGE
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

// The time complexity of this code is of the order
// O(log2(N) + 10*precision)
// let us say c1 = 10*precision
// so, our time complexity now is O(log2(N) + c1)
// -> that is equivelent to O(log2(N)).

float findRoot(int num,int precision) {
	int s = 1;
	int e = num;
	float ans = 0;
	while(s <= e) {
		int m = (s+e)/2;
		if(m*m <= num) {
			ans = m;
			s = m+1; 
		} else e = m-1;
	}
	if(ans*ans == num) return ans;
	float inc = 0.1;
	for(int i = 0; i < precision; ++i) {
		while(ans*ans < num) {
			ans += inc;
		}
		ans -= inc;
		inc /= 10;
	}
	return ans;
}


int main() {
	fastio(true);
	ll testCase;
	cin >> testCase;
	while(testCase--) {
		ll n,p;
		cin >> n >> p;
		cout << findRoot(n,p) << endl;
	}
	return 0;
}

// Sample Input :

// 5
// 156 3
// 78 3
// 49 3
// 81 3
// 164 3

// Sample Output :

// 12.489
// 8.831
// 7
// 9
// 12.806