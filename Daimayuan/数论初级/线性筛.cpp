#include <bits/stdc++.h>

#define u32 unsigned int

using namespace std;

void solve() {
    int n;
    u32 a, b;
    cin >> n >> a >> b;
    vector<int> p(n + 1, 0);
    vector<int> pr;
    u32 ans = 0;
    p[1] = 1;
    for (u32 i = 2; i <= n; i++) {
        if (!p[i]) {
            p[i] = i;
            pr.push_back(i);
            ans ^= (a * i + b);
        }
        for (int j = 0; j < pr.size() && i * pr[j] <= n; j++) {
            p[i * pr[j]] = pr[j];
            if (p[i] == pr[j]) break;
        }
    }
    cout << ans << '\n';
}

int main() {
    solve();

    return 0;
}
