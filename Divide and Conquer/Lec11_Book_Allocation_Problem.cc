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

bool checkIfPossible(int *books,int n,int student,int pages) {
	int s = 1;
	int page = 0;
	for(int i = 0; i < n; ++i) {
		if(page + books[i] <= pages) page += books[i];
		else s++;
		if(s > student) return false;
	}
	return true;
}


int allocateBookEvenly(int *books,int n,int student) {
	int s = -1;
	int e = 0;
	for(int i = 0; i < n; ++i) {
		s = max(s,books[i]);
		e += books[i];
	}
	int ans = INT_MAX;
	while(s <= e) {
		int page = (s+e)/2;
		if(checkIfPossible(books,n,student,page)){
			ans = min(ans,page);
			e = page-1;
		} else s = page+1; 
	}
	return ans;
}

int main() {
	fastio(true);
	int testCase;
	cin >> testCase;
	while(testCase--) {
		int n,student;
		cin >> n >> student;
		int*book = new int[n]();
		for(int i = 0; i < n; ++i) 
			cin >> book[i];
		cout << allocateBookEvenly(book,n,student) << endl;
	}
	return 0;
}

// Sample Input :

// 1
// 4 2
// 10 20 30 40

// Sample Output :

// 60