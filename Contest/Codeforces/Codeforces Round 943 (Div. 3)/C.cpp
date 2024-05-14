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
    vector<int> x(n + 5);
    vector<int> a(n + 5);
    for (int i = 2; i <= n; i++) cin >> x[i];
    a[1] = x[2] + 1;
    for (int i = 2; i < n; i++) {
        if (x[i] > x[i + 1]) a[i] = x[i];
        else if (x[i] == x[i + 1]) {
            a[i] = x[i] + a[i - 1];
        } else {
            int tmp = x[i + 1] - x[i];
            a[i] = (tmp / a[i - 1] + 1) * a[i - 1] + x[i];
        }
    }
    a[n] = a[n - 1] + x[n];
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
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

/*
问题：给定数组x（2~n），请构造数组a使得a[i] % a[i - 1] = x[i]
思路：首先可以列出方程：a[i] = a[i - 1] * t + x[i] 并且要保证a[i - 1] > x[i]
        那么只需要设置a[1]为x[2] + 1, 剩下的慢慢推即可
*/