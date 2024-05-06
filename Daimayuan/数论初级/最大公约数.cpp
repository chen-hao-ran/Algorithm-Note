#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
// int gcd(int a, int b) {
//     if (a < b) return gcd(b, a);
//     if (b == 0) return a;   
//     if (a % 2 && b % 2) return gcd(a - b, b);
//     if (a % 2) return gcd(a, b / 2);
//     if (b % 2) return gcd(a / 2, b);
//     return 2 * gcd(a / 2, b / 2);
// }

void solve() {
    int a, b;
    cin >> a >> b;
    int ans_gcd = gcd(a, b);
    // int ans_gcd = __gcd(a, b);
    ll ans_lcm = (ll)a * b / ans_gcd;
    cout << ans_gcd << ' ' << ans_lcm << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}