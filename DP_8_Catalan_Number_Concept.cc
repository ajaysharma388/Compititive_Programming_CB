/**********************************************
* AUTHOR : AJAY SHARMA, ajay2201@gmail.com    *
* Github Username : ajaysharma388             *
***********************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define N 100005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second


void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
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


struct book {
	int bookid;
	string title;
	float price;
	void input()
	{
		cin >> bookid;
		getline(cin, title);
		cin >> price;
	}
	void display()
	{
		cout<<"Id : "<<bookid<<"\nTitle : " << title << "\nPrice : " << price;

	}
};

int32_t main() {
	fastio(true);
	book b1;
	b1.input();
	b1.display();
	return 0;
}

// 001  c++ by saourab shukla  350


// 001  c++ by saourab shukla  350
