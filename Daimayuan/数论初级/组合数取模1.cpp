#include <bits/stdc++.h>

#define ll long long
#define u32 unsigned int
#define u64 unsigned long long
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 10000000;
const int mod = 1000000007;
vector<ll> fac(N + 2);
vector<ll> fnv(N + 2);

ll powmod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll binom(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * fnv[m] % mod * fnv[n - m] % mod;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % mod;
    fnv[N] = powmod(fac[N], mod - 2);
    for (int i = N; i >= 1; i--) fnv[i - 1] = fnv[i] * i % mod;
    assert(fnv[0] == 1);
}

void solve() {
    int n, m;
    cin >> n >> m;
    ll ans = binom(n, m);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}