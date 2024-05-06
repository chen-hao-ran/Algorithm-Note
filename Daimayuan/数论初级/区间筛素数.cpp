#include <bits/stdc++.h>

#define ll long long
#define u32 unsigned int
// #define u64 unsigned long long
// #define pii pair<int, int> 
// #define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
using namespace std;
// const ll infll = 1 << 63 - 1;
// const int infint = 1 << 31 - 1;
// const int inf = 0x3f3f3f3f;
const int N = 10000000;

void init() {

}

void solve() {
    ll l, r;
    u32 a, b;
    cin >> l >> r >> a >> b;
    vector<int> p(N + 10, 0);
    vector<int> pr;
    vector<bool> notprime(N + 10, false);
    p[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!p[i]) {
            p[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && i * pr[j] <= N; j++) {
            p[i * pr[j]] = pr[j];
            if (p[i] == pr[j]) break;
        }
    }

    for (int i = 0; i < pr.size(); i++) {
        int p = pr[i];
        for (ll j = r / p * p; j >= l && j > p; j -= p) {
            notprime[j - l] = true;
        }
    }

    u32 ans = 0;
    for (ll i = max(2ll, l); i <= r; i++) {
        if (!notprime[i - l]) ans ^= a * (u32)i + b;
        // cout << notprime[i] << '\n';
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();
    solve();
    return 0;
}