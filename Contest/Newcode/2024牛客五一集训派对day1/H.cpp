#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<vector<int>> adj(7);
    vector<int> edges(7, 0);
    for (int i = 1; i <= 5; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int one = 0, two = 0, three = 0, four = 0;

    for (int i = 1; i <= 6; i++) {
        int cnt = 0;
        for (auto v : adj[i]) cnt++;
        edges[i] = cnt;
        if (cnt == 1) one++;
        else if (cnt == 2) two++;
        else if (cnt == 3) three++;
        else four++;
    }

    if (three == 0) {
        if (four) cout << "2,2-dimethylbutane" << '\n';
        else cout << "n-hexane" << '\n';
    } else if (three == 2) {
        cout << "2,3-dimethylbutane" << '\n';
    } else {
        for (int i = 1; i <= 6; i++) {
            if (edges[i] == 3) {
                int cnt = 0;
                for (auto v : adj[i]) {
                    if (edges[v] == 2) cnt++;
                }
                if (cnt == 2) cout << "3-methylpentane" << '\n';
                else cout << "2-methylpentane" << '\n';
            }
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*
问题：给定六个点与五条边，保证每个点都至少与其他一个点相连，请问他们的连接模式属于以上五种的哪一种，具体见原题：https://ac.nowcoder.com/acm/contest/80186/H
思路：分类讨论每个点与其他点相连的边数即可
*/