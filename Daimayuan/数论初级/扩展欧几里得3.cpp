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

ll floordiv(ll a, ll b) {
    if (a % b == 0) return a / b;
    else if (a > 0) return a / b;
    else return a / b - 1;
}

ll ceildiv(ll a, ll b) {
    if (a % b == 0) return a / b;
    else if (a > 0) return a / b + 1;
    else return a / b;
}

void solve() {
    int a, b;
    ll m, l1, r1, l2, r2;
    cin >> a >> b >> m >> l1 >> r1 >> l2 >> r2;
    int x, y;
    int d = exgcd(a, b, x, y);

    if (m % d != 0) {
        cout << 0 << '\n';
        return;
    }

    a /= d;
    b /= d;
    m /= d;
    ll ansx = (ll)x * (m % b) % b;
    if (ansx < 0) ansx += b;
    ll ansy = (m - a * ansx) / b;
    ll l = max(ceildiv(l1 - ansx, b), ceildiv(ansy - r2, a));
    ll r = min(floordiv(r1 - ansx, b), floordiv(ansy - l2, a));
    
    cout << max((ll)0, r - l + 1) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}