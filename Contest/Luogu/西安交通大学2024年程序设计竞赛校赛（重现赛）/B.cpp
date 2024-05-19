#include <bits/stdc++.h>
#include <cmath>
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
const double eps = 1e-8;
const double pi = 3.1415926;

void init() {

}

void solve() {
    double x, y, t, c;
    cin >> x >> y >> t >> c;
    double r2 = x * x + y * y;
    double theta = t * c - (ll)(t * c);
    theta = theta * 2 * pi;
    double ans = 2 * r2 * (1 - cos(theta));
    ans = sqrt(ans); 
    // cout << theta << '\n';
    // cout << ans << '\n';
    printf("%.8lf", ans);
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
