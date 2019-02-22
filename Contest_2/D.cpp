#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1000 + 10;
const int MOD = 1000000007;
int dp[MAXN][MAXN];
int m, n;
int main() {
    int T;
    cin >> T;
    // pre calculate
    m = 1005, n = 1005;
    for (int i = 0; i < m; i++) {
        dp[0][i] = 1;
        dp[i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m; j++) {
            dp[i][j + 1] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
    }
    while (T--) {
        cin>>m>>n;
        if(m<n) swap(m,n);
        cout<<dp[n][m]<<endl;
    }
    return 0;
}