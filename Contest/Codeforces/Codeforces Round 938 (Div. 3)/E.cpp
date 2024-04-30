#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    for (int k = 1; k <= n; k++) {
        int cnt = 0;
        bool ok = true;
        vector<int> a(n);
        // cout << k << '\n';
        for (int i = 0; i < n; i++) {
            if (i - k >= 0) {
                if (a[i - k]) cnt--;
            } 
            // cout << i << ' ' << cnt << ' ' << s[i] << ' ' << a[i] << '\n';
            if (s[i] == '0' && cnt % 2 == 0) {
                if (i + k - 1 >= n) {
                    // cout << "::::" << i << '\n';
                    ok = false;
                    break;
                }
                cnt++;
                a[i] = 1;
            }
            if (s[i] == '1' && cnt % 2 == 1) {
                if (i + k - 1 >= n) {
                    ok = false;
                    // cout << "::::" << i << '\n';
                    break;
                }
                cnt++;
                a[i] = 1;
            }
        }
        if (ok) ans = max(ans, k);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

/*
!问题思路为cf官方题解
问题：给定大小为n的由01组成的字符串，选定最大的步数k( <= n)，使字符串在只能任意次数反转k个字符的情况下，能够转变为全是1的字符串
思路：遍历k的大小已经字符串s，对于已经为1的字符，无需将其转换，否则再将其转回来相当于无用功，若是碰到0，则需要将其转换，此时时间复杂度为n^2*k
        而优化的思路是用int变量cnt存储前k - 1个位置中转变的次数(因为只有前k - 1个位置的转变会影响该位置)，若s[i]为0且cnt为偶数，那么需要转变，若s[i]为1且cnt为奇数也需要转变，
        那么就可以通过n^2的复杂度来找到最大k，需要注意的是，若i - k的位置对转变有贡献，此时他对位置i是没有影响的，那么cnt需要减1，用vector容器存储每个位置的转变贡献
*/