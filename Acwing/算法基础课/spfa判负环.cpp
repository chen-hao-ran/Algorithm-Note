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
    vector<int> cnt(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;    
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        st[u] = false;

        for (auto [v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
                    puts("Yes");
                    return 0;
                }
                if (!st[v])
                    q.push(v);
            }
        }
    }
    puts("No");

    return 0;
}