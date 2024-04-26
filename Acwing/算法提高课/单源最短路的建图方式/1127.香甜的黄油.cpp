#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
    int n, p, c;
    cin >> n >> p >> c;
    vector<int> cow(p + 1, 0);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cow[x]++;
    }
    
    vector<pair<int, int>> adj[p + 1];
    for (int i = 1; i <= c; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    long long ans = inf;
    for (int i = 1; i <= p; i++) {
        vector<bool> val(p + 1, 0);
        vector<int> dis(p + 1, inf);
        dis[i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, i});
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

        long long sum = 0;
        for (int j = 1; j <= p; j++) {
            sum += 1LL * cow[j] * dis[j];
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}