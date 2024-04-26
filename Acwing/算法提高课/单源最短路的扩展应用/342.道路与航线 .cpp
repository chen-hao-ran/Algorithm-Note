#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
    int n, r, p, s;
    cin >> n >> r >> p >> s;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= r; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int cnt = 0;
    vector<int> group(n + 1);
    vector<bool> st(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            cnt++;
            group[i] = cnt;
            st[i] = true;
            function<void(int)> dfs = [&](int u) {
                st[u] = true;
                group[u] = cnt;
                for (auto [v, w] : adj[u]) {
                    if (st[v]) continue;
                    dfs(v);
                }
            };
            dfs(i);
        }
    }

    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= p; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    fill(st.begin(), st.end(), 0);
    function<void(int)> dfs2 = [&](int u) {
        if (st[u]) return;
        st[u] = true;
        
        for (auto [v, w] : adj[u]) {
            if (group[u] != group[v])
                deg[group[v]]++;
        }
    };
    dfs2(s);
    

    vector<bool> vis(n + 1, 0);
    vector<int> dis(n + 1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    dis[s] = 0;
    q.push({0, s});
    
    vector<pair<int,int>> gmin(n + 1, {inf, 0});
    while (q.size()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (group[u] == group[v]) {
                    q.push({dis[v], v});
                } 
            }
            if (group[u] != group[v]) {
                deg[group[v]]--;
                if (gmin[group[v]].first > dis[v]) {
                    gmin[group[v]].first = dis[v];
                    gmin[group[v]].second = v;
                }
                if (!deg[group[v]])
                    q.push({gmin[group[v]].first, gmin[group[v]].second});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dis[i] == inf) puts("NO PATH");
        else cout << dis[i] << endl;
    }

    return 0;
} 