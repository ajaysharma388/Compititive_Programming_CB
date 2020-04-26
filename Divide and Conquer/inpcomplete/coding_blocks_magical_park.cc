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

int main() {
	fastio(true);
	int r,c,k,s;
	cin>>r>>c>>k>>s;
	char A[r][c];
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			cin>>A[i][j];
		}
	}
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			if(s>=k){
				if(A[i][j]=='#') break;
				if(A[i][j]=='*') s+=5;
				if(A[i][j]=='.') s-=2;
				if(j<c-1) s--;
			}
		}
	}
	if(s>=k)cout<<"Yes\n"<<s<<endl;
	else cout<<"No\n";
	return 0;
}