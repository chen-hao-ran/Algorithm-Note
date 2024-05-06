#include <bits/stdc++.h>

#define ll unsigned long long

using namespace std;

vector<string> str(3);
vector<ll> f(501, 0);

void init() {
    f[1] = 6;
    f[2] = 7;
    for (int i = 3; i <= 500; i++) f[i] = f[i - 2] + f[i - 1];
    str[1] = " COFFEE";
    str[2] = " CHICKEN";
}

string func(int i, ll s, int len) {
    if (i <= 2) {
        string tmp = "";
        for (int j = s; j <= min(s + len - 1, (ll)f[i]); j++) tmp += str[i][j];
        return tmp;
    }

    if (s <= f[i - 2]) {
        if (s + len - 1 <= f[i - 2]) return func(i - 2, s, len);
        else return func(i - 2, s, len) + func(i - 1, 1, s + len - 1 - f[i - 2]);
    } else {
        return func(i - 1, s - f[i - 2], len);
    }
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    string ans = func(n, k, 10);

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {   
        init();
        solve();
    }

    return 0;
}

/*
问题：用类似斐波那契数列的方法处理字符串，给定s[1] = "COFFEE"和s[2] = "CHICKEN", s[n] = s[n - 2] + s[n - 1]，请问在s[n]种第k到第k + 9个字符是什么
思路：考虑递归思想，由于s[n]由s[n - 2]和s[n - 1]前后拼接组成，那么目标字符串只可能在s[n - 2]，s[n - 1]或者s[n - 2]和s[n - 1]中都有，那么只需要递归处理三种情况即可
*/