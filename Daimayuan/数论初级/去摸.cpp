#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll mul(ll x, ll y, ll m) {
    x %= m, y %= m;
    ll d = ((long double)x * y / m);
    d = x * y - d * m;
    if (d > m) d -= m;
    if (d < 0) d += m;
    
    return d;
}

int main() {
    ll x = 1e10, y = 1e10, m = 1e10;
    cout << mul(x, y, m);
}