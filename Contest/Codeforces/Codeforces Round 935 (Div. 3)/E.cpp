#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    int x_loc;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == x) x_loc = i;
    }

    int l = 1, r = n + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) l = mid;
        else r = mid;
    }

    int k;
    if (a[l] == x) cout << 0 << '\n';
    else {
        cout << 1 << '\n';
        cout << l << ' ' << x_loc << '\n';
    }
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
问题：给定一个序列，要求在最多两次交换以后，在序列上以指定方式二分后得到的结果为x，具体二分方式参考原题：https://codeforces.com/contest/1945/problem/E
思路：非常有意思的一道题目，只需要做一次二分，如果不是x的话就把x与该位置交换...复杂度为根号n
*/