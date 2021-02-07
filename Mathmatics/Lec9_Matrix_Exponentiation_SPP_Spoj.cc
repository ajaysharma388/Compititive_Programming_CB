/**********************************************
* AUTHOR : AJAY SHARMA, ajay2201@gmail.com    *
* Github Username : ajaysharma388             *
**********************************************/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
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

const int MAX = 18;
//const int MODULO = 1000000000;
int MODULO;

struct matrix{
    int rowSize = MAX - 1;
    int columnSize = MAX - 1;
    int data[MAX][MAX];
    matrix () {
        for (int i = 1; i <= rowSize; i ++) {
            for (int j = 1; j <= columnSize; j ++) {
                data[i][j] = 0;
            }
        }
    }
    matrix operator * (const matrix other) const{
        assert(columnSize == other.rowSize);
        matrix result = matrix();
        for (int i = 1; i <= rowSize; i ++) {
            for (int j = 1; j <= other.columnSize; j ++) {
                for (int k = 1; k <= columnSize; k ++) {
                    result.data[i][j] = (result.data[i][j] + 1LL * data[i][k] * other.data[k][j] % MODULO) % MODULO;
                }
            }
        }
        result.rowSize = rowSize;
        result.columnSize = other.columnSize;
        return result;
    }
    matrix power(long long e) {
        if (e == 1) {
            return *this;
        }
        if (e & 1) {
            return (*this) * power(e - 1);
        }
        matrix half = power(e >> 1);
        return half * half;
    }
};

int getNthSum(matrix transformation, matrix identity, long long N) {
    if (N <= identity.rowSize - 1) {
        int sum = 0;
        for (int i = 1; i <= N; i ++) {
            sum = (sum + identity.data[identity.rowSize + 1 - i][1]) % MODULO;
        }
        return sum;
    }
    matrix result = transformation.power(N) * identity;
    return (result.data[1][1] + MODULO) % MODULO;
}

int T;
int K;
long long M, N;
int b[MAX], c[MAX];

int32_t main() {
	fastio(true);
    cin >> T;
    for (int cases = 0; cases < T; cases ++) {
        cin >> K;
        for (int i = 1; i <= K; i ++) {
            cin >> b[i];
        }
        for (int i = 1; i <= K; i ++) {
            cin >> c[i];
        }
        cin >> M >> N >> MODULO;
        if (N <= K) {
            int result = 0;
            for (int i = (int)M; i <= (int)N; i ++) {
                result = (result + b[i]) % MODULO;
            }
            cout << result << endl;
            continue;
        }
        
        matrix t, I;
        t.rowSize = K + 1;
        t.columnSize = K + 1;
        t.data[1][1] = 1;
        for (int i = 2; i <= K + 1; i ++) {
            t.data[i - 1][i] = 1;
        }
        for (int i = 1; i <= K; i ++) {
            t.data[K + 1][i + 1] = c[K - i + 1];
        }
        I.rowSize = K + 1;
        I.columnSize = 1;
        I.data[1][1] = 0;
        for (int i = 1; i <= K; i ++) {
            I.data[i + 1][1] = b[i];
        }
        
        int l = getNthSum(t, I, M - 1);
        int r = getNthSum(t, I, N);
        cout << (r - l + MODULO) % MODULO << endl;
    }
    
    return 0;
}


// Sample Input :

// 1
// 2
// 1 1
// 1 1
// 2 10 1000003

// Sample Output :

142