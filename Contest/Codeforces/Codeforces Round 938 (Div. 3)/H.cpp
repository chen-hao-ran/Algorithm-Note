#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define ll unsigned long long

using namespace std;

array<int, 30> pw3;

void init() {
    pw3[0] = 1;
    for (int i = 1; i < 30; i++) {
        pw3[i] = pw3[i - 1] * 3;
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<array<int, 3>> tower(k);
    for (int i = 0; i < k; i++) {
        auto &[x, y, p] = tower[i];
        cin >> x >> y >> p;
        x--, y--;
    }

    auto calc = [&](int id, int r) -> ll {
        ll hurt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto &[x, y, p] =  tower[id];
                if (s[i][j] == '.') continue;
                if ((x - i) * (x - i) + (y - j) * (y - j) > r * r) continue;
                hurt += p;
            }
        }
        return hurt;
    };

    int t = 0;
    while (pw3[t] <= n * m * 500) t++;
    vector<vector<pii>> b(k);
    for (int i = 0; i < k; i++) {
        for (int r = 1; r < t; r++) {
            int hurt = calc(i, r);
            hurt -= pw3[r];
            if (hurt > 0) b[i].push_back({r, hurt});
        }
    }
    vector<int> f(1<<t, 0);
    for (int j = 0; j < k; j++) {
        for (int i = (1 << t) - 1; i >= 1; i--) {
            for (auto [r, hurt] : b[j]) {
                if (~i >> r & 1) continue;
                f[i] = max(f[i], f[i - (1 << r)] + hurt);
            }
        }
    }

    int ans = *max_element(all(f));

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        solve();
    }

    return 0;
}

/*
问题：给定一个n * m的矩阵，上面有一条以#显示的路径和以.显示的空位，有k个给定位置的塔放置于空位，敌人以每秒一格的速度沿着路径从(1, 1)前往(n, m)，设敌人的初始血量为h，防御塔的攻击范围为r，
        且敌人的最终血量 = h + 3 ^ r[1] + 3 ^ r[2] + ... 3 ^ r[k], 并且每个塔的攻击范围都不同，请问在敌人走不到终点的情况下
        ，h的最大值是多少
思路：首先确定每个防御塔的攻击范围r的取值范围，考虑每个防御塔对敌人伤害的贡献 = 攻击范围内的路径格数*p - 3 ^ r，求h最大也就是求每个防御塔对路径的总贡献最大是多少，
        那么显然可以知道每个防御塔的贡献必须大于0才有意义，也就是说r < log(n * m * 500)，
        后面只需要预计算出每个防御塔的r的可能取值，再用dp遍历所有塔以及所有状态即可
*/