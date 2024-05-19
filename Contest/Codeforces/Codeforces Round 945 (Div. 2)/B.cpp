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

int n;

void init() {
    
}

bool check(int mid, vector<vector<int>>& a) {
    vector<int> cnt(20, 0);
    for (int i = 1; i <= mid; i++) {
        for (int j = 0; j < 20; j++) {
            cnt[j] += a[i][j];
        }
    }
    for (int r = mid + 1; r <= n; r++) {
        int l = r - mid;
        for (int j = 0; j < 20; j++) {
            if (a[r][j] && cnt[j] == 0) {
                // cout << "y" << '\n';
                return false;
            }
            cnt[j] += a[r][j];
        }
        for (int j = 0; j < 20; j++) {
            if (a[l][j] && cnt[j] == 1) {
                // cout << "z" << '\n';
                return false;
            }
            cnt[j] -= a[l][j];
        }
    }
    return true;
}

void solve() {

    cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (20, 0));
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 20; j++) {
            a[i][j] = ((x >> j) & 1);
        }
    }

    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        // cout << l << ' ' << r << ' ' << mid << ' ' << check(mid, a) << '\n';
        if (check(mid, a)) r = mid;
        else l = mid;
        // if (mid == 1 && check(mid, a)) cout << "yes" << '\n';
    }
    cout << r << '\n';
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
