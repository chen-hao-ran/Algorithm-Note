#include <bits/stdc++.h>
#define pii pair<int, int> 
#define ll signed long long int
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve() {
    int n, m;
    size_t k;
    cin >> n >> m >> k;
    multiset<int> todo, done, extra;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        todo.insert(b);
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int val = a[i];
        if (todo.find(val) != todo.end()) {
            done.insert(val);
            todo.erase(todo.find(val));
        } else {
            extra.insert(val);
        }
    }
    ans += (done.size() >= k);

    for (int i = m; i < n; i++) {
        int l = i - m, r = i;
        int val_l = a[l], val_r = a[r];
        if (extra.find(val_l) != extra.end()) {
            extra.erase(extra.find(val_l));
        } else if (done.find(val_l) != done.end()) {
            done.erase(done.find(val_l));
            todo.insert(val_l);
        }

        if (todo.find(val_r) != todo.end()) {
            todo.erase(todo.find(val_r));
            done.insert(val_r);
        } else {
            extra.insert(val_r);
        }
        
        ans += (done.size() >= k);
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
！思路为cf官方题解
问题：给定大小为n的数组a，大小为m的数组b，请问在a中能够找到多少个大小为m的连续子数组，其中包含了b中至少k个元素
思路：用三个multiset分别存储b中还未被使用的元素，已经从b中拿走的元素，以及连续子数组中非b的元素
        从前向后遍历数组a，取其中连续的大小为m的子数组s，判断s为好数组的条件是done的元素数量 >= k
        那么处理的时候首先需要将第一个元素出队，并判断其为extra中元素还是done中元素，注意需要先判断是否为extra中元素，这是因为extra中存的元素包含因为超出b中数值的元素的数量而无法被判定为从b中拿走的元素
        再将最后一个元素入队，判断其是否从b中拿还是不从b中拿
        最后判断是否为好数组
*/