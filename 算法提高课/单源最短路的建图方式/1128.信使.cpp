#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> val(n + 1, 0);
    vector<int> dis(n + 1, inf);
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    while (q.size()) {
        int u = q.top().second;
        q.pop();
        if (val[u]) continue;
        val[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }

    bool flag = true;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = max(ans, dis[i]);
        if (dis[i] == inf) {
            flag = false;
            break;
        }
    }
    if (flag) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
