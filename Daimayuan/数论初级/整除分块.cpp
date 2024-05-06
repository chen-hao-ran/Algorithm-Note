#include <bits/stdc++.h>

#define u64 unsigned long long

using namespace std;

void solve() {
    u64 n;
    cin >> n;
    u64 sum = 0;
    for (u64 l = 1; l <= n; l++) {
        u64 d = n / l, r = n / d;
        sum += n * (r - l + 1) - d * (l + r) * (r - l + 1) / 2;
        l = r;
    }
    u64 ans = sum % ((u64)1 << 60);
    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}