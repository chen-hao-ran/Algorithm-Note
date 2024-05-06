#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
    int n, p;
    cin >> p >> n;
    vector<ll> inv(n + 1);
    inv[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
        ans ^= inv[i];
    }

    cout << ans << '\n';
}

int main() {
    solve();

    return 0;
}