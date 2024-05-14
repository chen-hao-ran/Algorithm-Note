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
const int N = 200010;

int n, k, pb, ps;
vector<int> p(N), a(N);

void init() {

}

ll func (int st) {
    int stand = st;
    ll ans = 0, sum = 0;
    int cnt = 1;
    while (1) {
        sum = sum + a[stand];
        ans = max(ans, sum + (ll)(k - cnt) * a[stand]);    
        cnt++;
        if (cnt > k) break;
        
        stand = p[stand];
        if (stand == st) break;
    }
    return ans;
}

void solve() { 
    cin >> n >> k >> pb >> ps;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll maxb = func(pb), maxs = func(ps);
    if (maxb > maxs) cout << "Bodya" << '\n';
    else if (maxb == maxs) cout << "Draw" << '\n';
    else cout << "Sasha" << '\n';
    // cout << "bob: " << maxb << " sas: " << maxs << '\n';
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
问题：给定一组排列p和一组数组a，bob的初始位置为pb，sas的初始位置为ps，在每一轮他们的得分会加上a[pos]，并且在这一轮结束后他们可以选择走到
        p[pos]，请问在两者都选最优方案的情况下，谁赢
思路：很显然只需要遍历一遍bob或者sas能走的位置，假设bob最后停留在了这个位置，那么只需要比较已经得到的分数加上未来在这个位置上的到的分数即可
*/