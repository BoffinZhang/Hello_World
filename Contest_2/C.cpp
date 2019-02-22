#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

const int MAXN = 1000000 + 10;
struct Qu {
    int s, t;
} q[MAXN];

bool cmp(Qu q1, Qu q2) {
    if (q1.t == q2.t) {
        return q1.s < q2.s;  //结束时间相同，选取开始较早的那个
    } else
        return q1.t < q2.t;  //结束时间较早的在前
}
int n, ans;
int main() {
    int count = 1;
    while (~scanf("%d", &n)) {
        // cout << "Case " << count++ << ":" << endl;
        printf("Case %d:\n", count);
        count++;
        ans = 0;
        for (int i = 0; i < n; i++) {
            int s, t;
            // cin >> s >> t;
            scanf("%d%d", &s, &t);
            q[i].s = min(s, t);
            q[i].t = max(s, t);
        }
        sort(q, q + n, cmp);
        int cur_t = 0;
        for (int i = 0; i < n; i++) {
            if (q[i].s >= cur_t) {
                cur_t = q[i].t;
                // cout << "pick " << q[i].s << " " << q[i].t << endl;
                ans++;
            }
        }
        // cout << ans << endl;
        // cout << "My king, at most " << ans << " road can be built." << endl;
        if (ans == 1)
            printf("My king, at most %d road can be built.\n\n", ans);
        else
            printf("My king, at most %d roads can be built.\n\n", ans);
    }
    return 0;
}