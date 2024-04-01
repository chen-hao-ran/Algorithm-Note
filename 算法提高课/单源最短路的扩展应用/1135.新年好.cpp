#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int g[10][50010];

int main() {
    int n, m;
    cin >> n >> m;
    int id[7];
    id[1] = 1;
    for (int i = 2; i <= 6; i++) {
        cin >> id[i];
    }

    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});     
        adj[v].push_back({u, w});     
    }

    
    for (int i = 1; i <= 6; i++) {
        vector<bool> vis(n + 1, 0);
        vector<int> dis(n + 1, inf);
        dis[id[i]] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, id[i]});
        while (q.size()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;

            for (auto [v, w] : adj[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
        for (int j = 1; j <= 6; j++) {
            g[i][id[j]] = dis[id[j]];
        }
    }    
    int ans = inf;
    int a[7];
    for (int i = 1; i <= 6; i++) {
        a[i] = i;
    }
    do {
        int res = g[a[1]][id[a[2]]];
        for (int i = 2; i <= 5; i++) {
            res += g[a[i]][id[a[i + 1]]];
        }
        ans = min(res, ans);
    } while (next_permutation(a + 2, a + 7));

    cout << ans << endl;
    
    return 0;
}