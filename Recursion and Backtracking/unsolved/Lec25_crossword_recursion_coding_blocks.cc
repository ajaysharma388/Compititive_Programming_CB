#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vcc vector<vector<char>>
#define vc vector<char>
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
    cin.tie(NULL);
    cout.tie(NULL);
}
// 0 2 1 3 2 4
// s[j-i]

bool search(vcc &grid,int m,string s,int len) {
    int l;
    for(int i = 0; i < m; ++i) {
        l = 0;
        for(int j = i; j < m and j+len-1 < m; ++j) {
            cout << s[j-i] << j <<" : " << grid[i][j] << endl; 
            if(s[j-i] == grid[i][j]) {
                l++;
            }
            if(l == len) return true;
        }
        cout << endl;
    }
    return false;
}

int main(){
    fastio(true);
    int n,m;
    cin >> n;
    map<string,bool> mp;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        mp[s] = false;
    }
    cin >> m;
    vcc grid(m,vc(m,' '));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }    
    for(auto node : mp) {
        string s = node.first;
        int l = s.length();
        bool ans = search(grid,m,s,l);
        if(ans) cout << s << " " << endl;
        else cout << s << ":" << "not found" << endl;
    }
    return 0;
}