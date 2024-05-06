#include <bits/stdc++.h>

#define ll long long
#define u32 unsigned int
#define u64 unsigned long long
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
using namespace std;

const ll infll = 1ll << 63 - 1;
ll n, m, q;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll xx, yy;
    ll d = exgcd(b, a % b, xx, yy);
    x = yy;
    y = xx - a / b * yy;

    return d;
}

ll merge(ll a, ll b, ll c, ll d) {
    ll x, y;
    ll g = exgcd(b, d, x, y);
    if ((c - a) % g != 0) {
        return infll;
    }
    d /= g;
    ll t = ((c - a) / g) % d * x % d;
    if (t < 0) t += d;
    return (b * t + a) % (b * d);
}

ll func(ll x, ll y) {
    x = (x + 2 * n) % (2 * n);
    y = (y + 2 * m) % (2 * m);
    return merge(x, 2 * n, y, 2 * m);
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++) {
        ll x, y;
        cin >> x >> y;
        ll T = n / gcd(n, m) * m;
        ll ans = min({func(x, y), func(x, -y), func(-x, y), func(-x, -y)});
        if (ans > T) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}

/*
把反射看作是平面的展开，再转换成线性同余方程
*/