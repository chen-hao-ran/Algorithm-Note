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
    cout << "1 1" << '\n';
    cout << "1 2" << '\n';
    if (n > 2) {
        for (int i = 3; i <= n; i++) cout << i << ' ' << i << '\n';
    }
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
问题：给定一个n x n的方阵，在上面摆放n个棋子，使得两两棋子之间的曼哈顿距离的类别最多
思路：可以发现第一个位置摆在1 1，第二个位置摆在1 2，剩下的全都摆在对角线上，就可以取到最大值
*/