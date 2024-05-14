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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 5, 0);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        mp[a[i]].push_back(i);
    }  
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // cout << '\n';

    while (q--) {
        int l, r;
        cin >> l >> r;
        if ((a[l - 1] ^ a[r]) == 0) {
            cout << "YES" << '\n';
            continue;
        } 
        auto &v1 = mp[a[r]];
        auto it = lower_bound(all(v1), l);
        if (it == v1.end() || *it >= r) {
            cout << "NO" << '\n';
            continue;
        }
        int pos = *it;
        auto &v2 = mp[a[l - 1]];
        auto nit = lower_bound(all(v2), pos + 1);
        if (nit != v2.end() && *nit < r) cout << "YES" << '\n';
        else cout << "NO" << '\n';
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
问题：给定一组数组以及q个查询，每个查询中给出l和r，l~r这一段子数组是否能被分割成至少两个数组，是他们的组内异或和相同
思路：可以发现若存在这样的分割方法，那么一定也存在分割成2组或者分割成3组的方法
        首先预处理前缀异或和，然后可以发现如果可以被分割成两组，那么整个l~r的异或和应该为0，
        再看分成3组的情况，假设存在这样的情况，那么两两之间的异或和肯定是为0的，可以发现最后两段数组的异或和等于a[pos] ^ a[r]，前两段数组的异或和等于a[pos2] ^ a[l - 1]那么只需要二分找到这两个位置即可
        如果找不到以上任意一种情况，说明不存在这样的方法满足题目的条件
*/