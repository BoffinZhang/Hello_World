#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

const int MAXN = 1000000;
int N, S[MAXN], T[MAXN];
pair<int, int> itv[MAXN];

void solve() {
    for (int i = 0; i < N; i++) {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv,itv+N);
    int ans = 0,t = 0;
    for(int i=0;i<N;i++){
        if(t<=itv[i].second){
            ans++;
            t = itv[i].first;
        }
    }
    if(ans==1) printf("My king, at most %d road can be built.\n\n", ans);
    else printf("My king, at most %d roads can be built.\n\n", ans);
}

int main(){
    int count = 1;
    while(~scanf("%d",&N)){
        int s,t;
        for(int i=0;i<N;i++){
            scanf("%d%d",&s,&t);
            if(s>t) swap(s,t);
            S[i] = s;
            T[i] = t;
        }
        printf("Case %d:\n",count);
        count++;
        solve();
    }
    return 0;
}