#include <bits/stdc++.h>

#define ll unsigned long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    vector<ll> s(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        s[i] = s[i - 1] + min(a[i], b[i]);
    }

    ll ans = 2e14;
    for (int i = 1; i <= m; i++) {
        ans = min(ans, a[i] + s[n] - s[i]);
    }
    cout << ans << '\n';
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
问题：给定两个序列a和b，小明在第n + 1个位置，他想插队到m个位置及以内，因此插队的代价是目标位置的a以及中间所有位置的b的和，请问成功插队到m及以内的最小代价是多少
思路：每个位置要么是途中位置，要么是目标位置，如果是目标位置那么代价必须为a，如果为途中位置可以取a和b中的较小值，因此可以用前缀和存储从1到n的min(a[i], b[i])的代价和，
        最后遍历从1到m的代价求最小值即可
*/