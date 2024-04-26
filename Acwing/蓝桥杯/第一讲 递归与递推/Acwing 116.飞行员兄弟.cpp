#include <bits/stdc++.h>

using namespace std;

const int N = 5;

char str[N][N];
int g[N][N];
bool st[N][N];
pair<int, int> res[100];
int mincnt = 0x3f3f3f3f;

void dfs(int u, int cnt) {
    if (cnt >= mincnt) return;
    if (u > 16) {
        bool ok = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (!g[i][j]) ok = false;
            }
        }
        if (ok) {
            mincnt = cnt;
            int r = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (st[i][j]) res[r++] = {i + 1, j + 1};
                }
            }
        }
        return;
    }
    int x = (u - 1) / 4;
    int y = (u - 1) % 4;
    int backup[5][5];
    memcpy(backup, g, sizeof g);
    for (int i = 0, j = 0; i < 4; i++, j++) {
        g[x][j] = !g[x][j];
        g[i][y] = !g[i][y];
    }
    g[x][y] = !g[x][y];
    st[x][y] = true;

    dfs(u + 1, cnt + 1);

    memcpy(g, backup, sizeof g);
    st[x][y] = false;

    dfs(u + 1, cnt);
}

int main() {
    for (int i = 0; i < 4; i++) cin >> str[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            g[i][j] = (str[i][j] == '-');
        }
    }

    dfs(1, 0);

    cout << mincnt << endl;

    for (int i = 0; i < mincnt; i++) {
        cout << res[i].first << ' ' << res[i].second << endl;
    }  

    return 0;
}