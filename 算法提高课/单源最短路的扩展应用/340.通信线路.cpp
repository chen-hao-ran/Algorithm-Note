#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int l = -1, r = 1000001;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        bool flag;
        vector<bool> vis(n + 1, 0);
        vector<int> dis(n + 1, inf);
        dis[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});
        while (q.size()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            
            for (auto [v, w] : adj[u]) {
                if (dis[v] > dis[u] + (w > mid)) {
                    dis[v] = dis[u] + (w > mid);
                    q.push({dis[v], v});
                }
            }
        }
        if (dis[n] == inf) {
            cout << -1 << endl;
            return 0;
        }

        if (dis[n] > k) flag = false;       
        else flag = true;

        if (flag) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}