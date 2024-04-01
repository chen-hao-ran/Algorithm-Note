#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
    int n, m, s, d;
    cin >> n >> m;
    vector<pair<int, double>> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, (1 - w / 100.0)});
        adj[v].push_back({u, (1 - w / 100.0)});
    }
    cin >> s >> d;

    vector<bool> val(n + 1, 0);
    vector<double> dis(n + 1, 0);
    dis[s] = 1;
    priority_queue<pair<double, int>, vector<pair<double, int>>> q;
    q.push({0, s});
    while (q.size()) {
        int u = q.top().second;
        q.pop();
        if (val[u]) continue;
        val[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dis[v] < dis[u] * w) {
                dis[v] = dis[u] * w;
                q.push({dis[v], v});
            }
        }
    }

    cout << setiosflags(ios::fixed) << setprecision(8);
    cout << 100 / dis[d] << endl;

    return 0;
}