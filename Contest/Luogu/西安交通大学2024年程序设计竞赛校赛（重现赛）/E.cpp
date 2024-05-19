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
    map<double, int> mp;
    vector<double> a(n + 1, 1);
    double db = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x; 
        if (x == 0) {
            mp[db] = i;
            a[i] = db--;
        }
        else {
            auto it = mp.find(a[x]);
            double cr = it->first;
            ++it;
            if (it == mp.end()) {
                ++cr;
            } else {
                cr = (it->first + cr) / 2;
            }
            mp[cr] = i;
            a[i] = cr;
        } 
    }   
    for (auto x : mp) {
        cout << x.second << ' ';
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
