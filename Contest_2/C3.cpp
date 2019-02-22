#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 1000000 + 10;
const int INF = 1e9;
int N;
typedef pair<int, int> P;
vector<P> vec;
int dp[MAXN];
int main() {
    int count = 1;
    while (~scanf("%d", &N)) {
        vec.clear();
        for (int i = 0; i < N; i++) {
            int f, s;
            scanf("%d%d", &f, &s);
			vec.push_back(P(f,s));
            dp[i] = INF;
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++) {
            *lower_bound(dp, dp + N, vec[i].second) = vec[i].second;
        }
        int ans = lower_bound(dp, dp + N, INF) - dp;
        printf("Case %d:\n", count);
		count++;
        if (ans == 1)
            printf("My king, at most %d road can be built.\n\n", ans);
        else
            printf("My king, at most %d roads can be built.\n\n", ans);
    }
    return 0;
}