#include <bits/stdc++.h>

#define ll long long

using namespace std;

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

void merge(ll& a, ll& b, ll c, ll d) {
    if (a == -1 && b == -1) return;
    ll x, y;
    ll g = exgcd(b, d, x, y);
    if ((c - a) % g != 0) a = b = -1;
    d /= g;
    ll t = ((c - a) / g) % d * x % d;
    if (t < 0) t += d;
    a = b * t + a;
    b = b * d;
}

void solve() {
    int n;
    cin >> n;
    ll a = 0, b = 1, c, d;
    for (int i = 1; i <= n; i++) {
        cin >> c >> d;  
        merge(a, b, c, d);
    }   

    cout << a << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}