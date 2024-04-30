#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    bool ok = false;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        ok = false;
        if (m >= n) {
            if (k < n - 1) ok = true;
        } else {
            if (k < n - (n / m + (n % m != 0))) ok = true;
        }

        if (ok) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}

/*
问题：给定位置数n，颜色数m，以及bob最多能影响的位置数k，判断是否存在一种情况，在alice使用最多m种颜色影响n个位置后，bob能够将所有位置染成同一种颜色
思路：判断n，m，k之间的大小关系，只需要判断存在的情况
        1. 当n <= m时，alice最多影响n - 1个位置使其颜色不能被bob使用
        2. 当n > m时，alice最多影响n - (n / m + (n % m != 0))个位置使其颜色不能被bob使用
*/