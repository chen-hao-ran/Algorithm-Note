#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    ll ans = 2 + m / a + m / b;
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
问题：给定两桶烟花同时发射，左边的烟花每隔a秒发射一次，右边的每隔b秒发射一次，每束烟花在空中最多持续m + 1秒，请问空中最多同时出现多少烟花
思路：在第一束烟花发射后的m + 1秒内，同时呈现的烟花最多，那么左边的烟花桶最多1 + m / a束，右边的最多1 + m / b束，两者相加即为答案
*/