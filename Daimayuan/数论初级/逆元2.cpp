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

unsigned int A, B, C;
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}

void solve() {
    int n, p;
    scanf("%d%d%u%u%u", &p, &n, &A, &B, &C);
    vector<ll> a(n + 1); 
    for (int i = 1; i <= n; i++) a[i] = rng61() % p;

    vector<ll> s(n + 1, 1);
    vector<ll> t(n + 1, 1);
    s[1] = a[1] % p;
    for (int i = 2; i <= n; i++) s[i] = s[i - 1] * a[i] % p;
    int x, y;
    int d = exgcd(s[n], p, x, y);
    if (x < 0) x += p;
    // cout << x << '\n';
    assert(s[n] * x % p == 1);
    t[n] = x;
    for (int i = n - 1; i >= 1; i--) t[i] = t[i + 1] * a[i + 1] % p;
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) continue;
        int tmp = s[i - 1] * t[i] % p;
        ans ^= tmp;
    }

    cout << ans << '\n';
}

int main() {
    solve();

    return 0;
}