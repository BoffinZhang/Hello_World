//并查集

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 30 + 10;  //字母

int par[MAXN];     //父亲
int rank_x[MAXN];  //树的高度
//初始化n个元素
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank_x[i] = 0;
    }
    // cout << "initial finished" << endl;
}

//查询树根
int find(int x) {
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);  //同时缩短连接路径
}

//合并x和y所属的集合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;           //两个节点在一棵树上
    if (rank_x[x] < rank_x[y]) {  // y的树高些，把x连接到y上
        par[x] = y;
    } else {
        par[y] = x;
        if (rank_x[x] == rank_x[y]) rank_x[x]++;
    }
}

//判断x和y是否属于同一个集合
bool same(int x, int y) { return find(x) == find(y); }

char a[100000 + 10], b[100000 + 10];
int ans = 0;
char an1[100], an2[100];
int main() {
    int n;
    cin >> n >> a >> b;
    init(30);
    for (int i = 0; i < n; i++) {
        int s1 = a[i] - 'a';
        int s2 = b[i] - 'a';
        if (!same(a[i] - 'a', b[i] - 'a')) {
            unite(s1, s2);
            an1[ans] = a[i];
            an2[ans] = b[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<an1[i]<<" "<<an2[i]<<endl;
    }
    return 0;
}