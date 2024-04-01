#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

struct node {
    int cost, level;
};

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<node> nod(n + 1);
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> nod[i].cost >> nod[i].level >> x;
        for (int j = 1; j <= x; j++) {
            int v, w;
            cin >> v >> w;
            adj[i].push_back({v, w});
        }
    }
    int ans = inf;
    for (int i = max(1, nod[1].level - m); i <= nod[1].level; i++) {
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
                if (nod[v].level >= i && nod[v].level <= i + m) {
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        q.push({dis[v], v});
                    }
                }
            }
        }
        
        for (int j = 1; j <= n; j++) {
            ans = min(ans, dis[j] + nod[j].cost);
        }
    }

    cout << ans << endl;

    return 0;
}