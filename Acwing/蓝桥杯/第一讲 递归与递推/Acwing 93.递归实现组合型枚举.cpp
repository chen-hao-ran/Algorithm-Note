#include <bits/stdc++.h>

using namespace std;

int n, m;
bool st[30];

void dfs(int u, int cnt) {
    if (cnt > m) return;
    if (u > n) {
        if (cnt == m) {
            for (int i = 1; i <= n; i++) {
                if (st[i]) cout << i << ' ';
            }
            cout << endl;
        }
        return;
    }

    st[u] = true;
    dfs(u + 1, cnt + 1);
    st[u] = false;
    dfs(u + 1, cnt);
}

int main() {
    cin >> n >> m;
    dfs(1, 0);

    return 0;
}