#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    auto check = [&](int x) -> bool {
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) continue;
                dp[i][j] = (a[i][j] % x == 0);
                if (i == 1) {
                    dp[i][j] &= dp[i][j - 1];
                } else if (j == 1) {
                    dp[i][j] &= dp[i - 1][j];
                } else {
                    dp[i][j] &= dp[i - 1][j] | dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    };

    int ans = 0;
    for (int i = 1; i <= a[1][1] / i; i++) {
        if (a[1][1] % i) continue;
        if (check(i)) {
            ans = max(ans, i);
            // cout << i << '\n';
        }
        if (check(a[1][1] / i)) {
            ans = max(ans, a[1][1] / i);
            //  cout << a[1][1] / i << '\n';
        }
    }

    cout << ans << '\n';
    // cout << "--------------------------------" << '\n';
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
问题：给定一个矩阵，从左上角走到右下角，且只能向下或者向右的情况下，设ans为路径上所有元素的gcd，求ans的最大值
思路：最后的答案一定是a[1][1]的因子，因此只需要遍历第一个元素的所有因子，然后每一个因子跑一次dp求是否存在路径使得路径上的所有元素都为该因子的倍数
*/