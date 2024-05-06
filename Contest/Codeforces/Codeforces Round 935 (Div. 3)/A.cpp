#include <bits/stdc++.h>

#define ll  unsigned long long

using namespace std;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    bool ok = true;
    int sum = a + b / 3;

    if (b % 3 && b % 3 + c < 3) ok = false;
    sum += (b % 3 + c) / 3 + ((b % 3 + c) % 3 != 0);

    if (!ok) cout << "-1" << '\n';
    else cout << sum << '\n';
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
问题：给定a个i人和b个e人以及c个随性人，每个帐篷可以容纳3个人，i人只喜欢一个人住，e人喜欢3个人住，随性人随意，请问最少需要多少个帐篷，如果无法满足上述条件输出-1
思路：很简单的贪心，首先满足i人和e人的条件计算出初始帐蓬数a + b / 3，那么还剩最多两个e人，只需要特判剩下的随性人是否够e人凑成3人即可，若可以的话则帐蓬数还要添加（剩下的e人 + 随性人）/ 3
*/