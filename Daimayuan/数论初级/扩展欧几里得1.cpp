#include <bits/stdc++.h>

using namespace std;

int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int xx, yy;
    int d = exgcd(b, a % b, xx, yy);
    x = yy;
    y = xx - a / b * yy;

    return d;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int x, y;
    int d = exgcd(a, b, x, y);
    y = -y;
    while (x < 0 || y < 0) x += b / d, y += a / d;
    while (x >= b / d && y >= a / d) x -= b / d, y -= a / d;
    cout << x << ' ' << y << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}