#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;
const int MAXM = 100000 + 10;
const int MAXN = 100 + 10;

int dp[MAXM];
int a[MAXN], m[MAXN];
int n,K;
void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=K;i++){
        if(dp[i]>=0) ans++;
    }
    printf("%d\n",ans);
}

int main(){
    while(1){
        scanf("%d%d",&n,&K);
        if(n==0&&K==0) break;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&m[i]);
        }
        solve();
    }
}