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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 5, 0);
    vector<int> b(k + 5, 0);
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];
    
    while (q--) {
        int x;
        cin >> x;
        int l = 0, r = k + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (x >= a[mid]) l = mid;
            else r = mid;
        }
        cout << x << ' ' << a[l] << '\n'; 
        int len = x - a[l];
        ll op = 1ll * len * (b[l + 1] - b[l]) / (a[l + 1] - a[l]);
        cout << op + b[l] << ' ';
        // cout << (int)(((double)(x - a[l])) / ((double)(a[l + 1] - a[l])) * (b[l + 1] - b[l])) + b[l] << ' '; 
    }
    cout << '\n';
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
