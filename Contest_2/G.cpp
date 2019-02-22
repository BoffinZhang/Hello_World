#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 100000 + 10;
const int MAXM = 100000 + 10;
const ll INF = 2e13;
struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct Node {
    int n;
    ll d;  // n-编号,d-最短距离
    Node() {}
    Node(int n, ll d) : n(n), d(d) {}
    bool operator<(const Node& N) const {
        return d > N.d;  //队列中，距离小的顶点在前
    }
};

int V, E;                      //顶点数，边数
long long dis[MAXN];           //最短距离
int preV[MAXN];                //前导顶点
vector<Edge> G[MAXN];          //邻接表
void dijkstra(int s, int t) {  //第一次修改pre[V]
    //初始化
    fill(dis, dis + MAXN, INF);

    priority_queue<Node> q;
    q.push(Node(s, 0));
    dis[s] = 0;
    while (!q.empty()) {
        Node p = q.top();
        q.pop();
        int u = p.n, v, w;
        ll d = p.d;
        if (dis[u] < d) continue;
        for (int i = 0; i < G[u].size(); i++) {
            v = G[u][i].v;
            w = G[u][i].w;
            // if (!G[u][i].ok) continue;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(Node(v, dis[v]));
                preV[v] = u;  //前导顶点
            }
        }
    }
    if (dis[t] < INF) {
        stack<int> Road;
        Road.push(t);
        for (int i = t; i != s; i = preV[i]) {
            Road.push(preV[i]);
        }
        while (!Road.empty()) {
            int r = Road.top();
            Road.pop();
            cout << r << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
}

void solve() {
    cin >> V >> E;
    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        G[u].push_back(Edge(u, v, w));
        G[v].push_back(Edge(v, u, w));
    }
    dijkstra(1, V);
}

int main() {
    solve();
    return 0;
}