#include <bits/stdc++.h>

using namespace std;

const int N = 250010;

int b[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c, d;
        cin >> n >> c >> d;
        long long minv = 0x3f3f3f3f;
        bool ok = true;
        map<long long, int> mp;
        for (int i = 0; i < n * n; i++) {
            cin >> b[i];
            minv = min(minv, 1LL * b[i]);
        }

        for (int i = 0; i < n; i++) {
            minv += i * c;
            for (int j = 0; j < n; j++) {
                minv += j * d;
                mp[minv]++;
                // cout << minv << ' ';
                minv -= j * d;
            }
            // cout << '\n';
            minv -= i * c;
        }
        // for (int i = 0; i < n * n; i++) {
        //     cout << b[i];
        // }
        // cout << '\n';
        for (int i = 0; i < n * n; i++) {
            if (mp[b[i]] == 0) {
                ok = false;
                break;
            } else mp[b[i]]--;
        }
        if (ok) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
} 

/*
问题：给定一种n * n矩阵构造方式，给定a[1][1]值后，a[i + 1][j] = a[i][j] + c, a[i][j + 1] = a[i][j] + d，
        问给定大小为n * n的数组b，其是否能构造出上述矩阵
思路：
    首先需要考虑初始位置a[1][1]的值，而根据题目条件可知矩阵在两个维度均是递增的，那么a[1][1]显然为数组b中的最小值，再用一个map来存储用b构造出的特殊矩阵中每个数的个数，
    因此，只需遍历一遍数组b，同时map[b[i]] - 1，当map[b[i]]为0时，说明b不能构造出该矩阵，否则可以构造
ps：考虑用int存储b构造出的矩阵中每个数的个数，而不是bool，是因为题目要求用b中的n * n个元素构造
*/