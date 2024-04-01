#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int a[N][N], s[N][N];

int main() {
    int t, r, n = 0, m = 0;
    cin >> t >> r;
    for (int i = 1; i <= t; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;
        a[x][y] += w;
        n = max(n, x);
        m = max(m, y);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    int res = 0;
    if (r >= n && r >= m) {
        cout << s[5005][5005] << endl;
        return 0;
    }
    for (int i = 1; i + r - 1 <= n; i++) {
        for (int j = 1; j + r - 1 <= m; j++) {
            int x1 = i;
            int y1 = j;
            int x2 = i + r - 1;
            int y2 = j + r - 1;
            res = max(res, s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
        }
    }
    if (r == 0) res = 0;

    cout << res << endl;

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
    return 0;
}