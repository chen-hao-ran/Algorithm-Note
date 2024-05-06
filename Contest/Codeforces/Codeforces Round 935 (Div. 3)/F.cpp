#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
using namespace std;

void init() {
    
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> p(n + 1);
    multiset<ll, greater<ll>> to_pick;
    multiset<ll, less<ll>> picked;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        to_pick.insert(a[i]);
    }
    for (int i = 1; i <= n ;i++) cin >> p[i];
    pair<ll, int> ans = {0, 0};
    int k = 1;
    while (!to_pick.empty()) {
        if (k >= 2) {
            ll val = a[p[k - 1]];
            if (to_pick.find(val) != to_pick.end()) to_pick.erase(to_pick.find(val));
            else picked.erase(picked.find(val));
        }

        while (picked.size() < k) {
            picked.insert(*to_pick.begin());
            to_pick.erase(to_pick.begin());
        }

        ll tmp = k * (*picked.begin());
        if (tmp > ans.first) {
            ans.first = tmp;
            ans.second = k;
        }

        k++;
        if (k + k - 1 > n) break;
    }

    cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t --) {
        init();
        solve();
    }
    return 0;
}

/*
问题：给定一组大小为n的数组，每个元素代表第i个蘑菇的魔力值，并且给定另一个大小为n的排列，当取了k个蘑菇后，排列中前k - 1个蘑菇会失效，问k * min(挑选的所有蘑菇中的最小值)的最大值是多少
思路：用大根堆维护可被挑选的蘑菇to_pick，小根堆维护已经挑选的蘑菇picked，每次挑选一个蘑菇后，弹出失效的蘑菇
*/