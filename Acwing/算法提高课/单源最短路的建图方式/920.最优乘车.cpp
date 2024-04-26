#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
    int n, m;
    cin >> m >> n;
    cin.ignore();
    
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        int x;
        bool flag = true;
        int last;
        while (iss >> x) {
            if (flag) {
                flag = false;
                last = x;
            } else {
                adj[last].push_back({x, i});
                last = x;
            }
        }
    }

    vector<bool> vis(n + 1, 0);
    vector<int> dis(n + 1, inf);
    vector<int> ty(n + 1, -1);
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    while (q.size()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dis[v] >= dis[u] + (ty[u] != w)) {
                dis[v] = dis[u] + (ty[u] != w);
                ty[v] = w;
                // if (v == 50) cout << u << ' ' << v << ' ' << ty[u] << endl;
                q.push({dis[v], v});
            }
        }
    }

    if (dis[n] == inf) cout << "NO" << endl;
    else cout << dis[n] - 1 << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": " << dis[i] - 1 << endl;
    // }

    return 0;
}