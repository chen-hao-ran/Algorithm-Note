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
    
    vector<bool> vis(n + 2, false);
    vector<int> dis(n + 2, inf);
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
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
    if (dis[n] == inf) cout << -1 << endl;
    else cout << dis[n] << endl;

    return 0;
}