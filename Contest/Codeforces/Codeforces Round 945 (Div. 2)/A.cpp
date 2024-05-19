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
    vector<int> a(3, 0);
    for (int i = 0; i < 3; i++) cin >> a[i];
    int cnt = 0;
    int sum = a[0] + a[1] + a[2];
    if (sum % 2) {
        cout << -1 << '\n';
        return;
    }
    while (a[1] && a[2]) {
        cnt++;
        a[1]--;
        a[2]--;
        sort(all(a));
    }

    cout << cnt <<'\n';
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
