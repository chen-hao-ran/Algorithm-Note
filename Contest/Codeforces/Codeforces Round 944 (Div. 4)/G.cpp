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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, vector<int>> mp;
    vector<int> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i] >> 2].push_back(a[i]);
        q.push_back(a[i] >> 2);
    }
    
    // for (auto x : q) {
    //     sort(all(mp[x]));
    // }
    for (auto &[x, t] : mp) sort(all(t));

    for (int i = n; i >= 1; i--) {
        int tmp = a[i];
        a[i] = mp[a[i] >> 2].back();
        mp[a[i] >> 2].pop_back();
    }
    for (int i = 1; i <= n; i++) cout <<a[i] << ' ';
    cout <<'\n';
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
