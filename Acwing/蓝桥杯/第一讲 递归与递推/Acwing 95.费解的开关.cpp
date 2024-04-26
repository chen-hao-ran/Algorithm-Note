#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int g[N][N], backup[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void turn(int i, int j) {
    g[i][j] = !g[i][j];
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        g[nx][ny] = !g[nx][ny];
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        for (int i = 0; i < 5; i++) {
            cin >> s;
            for (int j = 0; j < 5; j++) {
                g[i][j] = (s[j] == '1');
            }
        }

        int res = 0x3f3f3f3f;
        for (int k = 0; k < 32; k++) {
            memcpy(backup, g, sizeof g);
            int step = 0;
            // 第一行的情况
            for (int j = 0; j < 5; j++) {
                if (k >> j & 1) {
                    step++;
                    turn(0, j);
                }
            }
            // 2~4行的情况
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 5; j++) {
                    if (!g[i][j]) {
                        step++;
                        turn(i + 1, j);
                    }
                }
            }
            // 检查最后一行的状态
            bool dark = false;
            for (int j = 0; j < 5; j++) {
                if (!g[4][j]) dark = true;
            }
            if (!dark) {
                res = min(res, step); 
            }
            memcpy(g, backup, sizeof g);
        }
        if (res > 6) res = -1;
        cout << res << endl;
    }
    
    return 0;
}