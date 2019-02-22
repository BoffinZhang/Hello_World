#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, t, ans = 0;
    queue<int> q1, q2, q3;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 1)
            q1.push(i + 1);
        else if (t == 2)
            q2.push(i + 1);
        else if (t == 3)
            q3.push(i + 1);
    }
    ans = min(q1.size(), q2.size());
    ans = min(ans, (int)q3.size());
    cout<<ans<<endl;
    while (!q1.empty() && !q2.empty() && !q3.empty()) {
        int a1 = q1.front();
        int a2 = q2.front();
        int a3 = q3.front();
        q1.pop();
        q2.pop();
        q3.pop();
        cout << a1 << " " << a2 << " " << a3 << endl;
    }
    return 0;
}