#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int inf = 0x3f3f3f3f;

struct Edge {
    int a, b, w;
}e[N];
int n, m, k;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> e[i].a >> e[i].b >> e[i].w;
    }
    int dis[N], backup[N];
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for (int i = 1; i <= k; i++) {
        memcpy(backup, dis, sizeof dis);
        for (int j = 0; j < m; j++) {
            int a = e[j].a;
            int b = e[j].b;
            int w = e[j].w;
            dis[b] = min(dis[b], backup[a] + w);
        }
    }
    if (dis[n] > inf / 2) puts("impossible");
    else cout << dis[n] << endl;

    return 0;
}