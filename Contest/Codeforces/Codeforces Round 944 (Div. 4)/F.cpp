#include <bits/stdc++.h>

#define ll long long
#define u32 unsigned int
#define u64 unsigned long long
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
using namespace std;
const ll infll = 1 << 63 - 1;
const int infint = 1 << 31 - 1;
const int inf = 0x3f3f3f3f;

void init() {

}

void solve() {
    ll r;
    cin >> r;
    ll ans = 0;
    for (ll i = 1; i <= r; i++) {
        ll _l = r * r - i * i;
        ll _r = (r + 1) * (r + 1) - i * i - 1;
        ll ls = sqrt(_l), rs = sqrt(_r);
        if (ls * ls < _l) ls++;
        ans += (rs - ls + 1) * 4;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    init();
    while(t --) {
        solve();
    }
    return 0;
}
