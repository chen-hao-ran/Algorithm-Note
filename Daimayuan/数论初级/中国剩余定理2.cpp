#include <bits/stdc++.h>

#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, vector<pii>> eqns;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int a, m;
        cin >> a >> m;
        for (int d = 2; d <= m / d; d++) {
            if (m % d == 0) {
                int p = d, pe = 1;
                while (m % p == 0) {
                    m /= p;
                    pe = pe * p;
                }
                eqns[p].push_back({pe, a % pe});
            }
        }
        if (m != 1) eqns[m].push_back({m, a % m});
        for (auto eq : eqns) {
            auto eqn = eq.second;
            int maxpe = max_element(all(eqn)) -> second;
            for (auto p : eqn) {
                if (maxpe % p.first != p.second) ok = false;
            }
        }
    }
    if (ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}