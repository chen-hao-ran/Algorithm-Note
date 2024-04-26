#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int n, m;

int main() {
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1]; 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<bool> st(n + 1, false);
    vector<int> dis(n + 1, inf);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (auto [v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!st[v])
                    q.push(v);
            }
        }
    }
    if (dis[n] == inf) puts("impossible");
    else cout << dis[n] << endl;

    return 0;
}