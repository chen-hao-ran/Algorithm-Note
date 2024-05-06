#include <bits/stdc++.h>

#define ll long long
using namespace std;

int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int xx, yy;
    int d = exgcd(b, a % b, xx, yy);
    x = yy;
    y = xx - a / b * yy;

    return d;
}

void solve() {
    int a, b;
    ll m;
    cin >> a >> b >> m;
    int x, y;
    int d = exgcd(a, b, x, y);

    bool ok = true;
    ll ansx, ansy;
    if (m % d != 0) ok = false;
    else {
        a /= d;
        b /= d;
        m /= d;
        ansx = (ll)x * (m % b) % b;
        ansx %= b;
        if (ansx < 0) ansx += b;
        ansy = (m - a * ansx) / b;
        if (ansy < 0) ok = false;
    }
    if (ok) cout << (ll)ansx << ' ' << (ll)ansy << '\n';
    else cout << -1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}