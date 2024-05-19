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
    double x, y;
    cin >> x >> y;
    double ansx = 1.0 / 2 * x + 1 / 2.0 * y;
    double ansy = sqrt(3.0) / 2 * x - sqrt(3.0) / 2 * y;
    printf("%.8lf %.8lf", ansx, ansy);
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
