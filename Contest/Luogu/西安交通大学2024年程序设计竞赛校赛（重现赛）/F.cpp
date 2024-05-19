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
    int n, m;
    cin >> n >> m;
    vector<ll> a(1e6 + 10, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x] += (ll)i;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        ll ans = a[x] * a[y];
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    init();
    while(t --) {
        solve();
    }
    return 0;
}
