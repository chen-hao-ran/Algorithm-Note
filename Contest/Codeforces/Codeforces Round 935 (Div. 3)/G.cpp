#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
using namespace std;

void init() {
    
}

void solve() {
    int n, D;
    cin >> n >> D;
    vector<int> k(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) cin >> k[i] >> s[i];
    auto suf = k;
    suf.push_back(0);
    for (int i = n; i >= 1; i--) suf[i] = max(suf[i], suf[i + 1]);
    vector<vector<int>> pos(D + 1);
    set<array<int, 4>> st;
    int ans = -1, cur = 1;
    
    for (int i = 1; i <= D; i++) {
        if (!st.empty() && prev(st.end()) -> at(0) > suf[cur]) {
            auto [pri, tim, s, id] = *prev(st.end());
            s = -s;
            st.erase(prev(st.end()));
            if (i + s < D) pos[i + s].push_back(id);
        } else {
            int id = cur++;
            if (i + s[id] < D) pos[i + s[id]].push_back(id);
        }

        if (cur == n + 1) {
            ans = i;
            break;
        }

        for (auto id : pos[i]) {
            st.insert({k[id], -i, -s[id], id});
        }  
    }
    
    cout << ans << '\n';
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
问题：给定n个排成一队的学生以及每个学生的优先度k，吃饭所用时间s，窗口会在每分钟开始时给队头学生打饭，假设打饭时间为x，每个学生在第x + s分钟结束时回到队伍，并且会向前插队，直到某个学生的k值不小于他，
        问最少多少分钟后所有学生都能吃上一遍饭，若答案大于D，那么输出-1
思路：用set存储已经吃过一次饭且出队的学生的k值，打饭的时间，吃饭的时间以及id，用cur指向未吃过饭的队头位置，并且用suf维护后缀k值最大值，
        那么每次只需要比较cur指向的学生以及st中优先度最高的学生的优先度即可，并在最后将这一分钟末尾进入队伍的学生加入st
*/