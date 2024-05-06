#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    vector<int> b(n + 2, 0);
    string s;
    cin >> s;

    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i - 1] == '0');
    }
    for (int i = n; i >= 1; i--) {
        b[i] = b[i + 1] + (s[i - 1] == '1');
    }
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // cout << '\n';

    // for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    // cout << '\n';
    
    int ans_loc = 0x3f3f3f3f, ans_val = 0x3f3f3f3f;
    for (int i = 0; i <= n; i++) {
        if (a[i] >= (i + 1) / 2 && b[i + 1] >= (n - i + 1) / 2) {
            if (abs(i - n / 2.0) < ans_val) {
                ans_loc = i;
                ans_val = abs(i - n / 2.0);
            }
        }
    }
    cout << ans_loc << '\n';
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
问题：给定一组由01组成的序列，请找到最接近n / 2的位置i，使位置<=i的序列中value为0的和 > (i + 1) / 2，使位置 > i的序列中value为1的和 > (n - i + 1) / 2，若能找到多个最接近的位置，取左边
思路：用两个前缀和数组分别存从从1至i的value为0的个数和，以及从n到i的value为-的个数和，再遍历一遍所有位置即可
*/