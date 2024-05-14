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

int n, k1, k2;
string s;

void init() {

}

vector<int> z_algorithm(const string &s){
    int n = s.size();
    vector<int> a(n);
    a[0] = n;
	for(int i = 1, l = 0, r = 0; i < n; i++){
		if (i <= r) a[i] = min(a[i - l], r - i + 1);
		while(i + a[i] < n && s[i + a[i]] == s[a[i]]) ++a[i];
		if (i + a[i] - 1 > r) l = i, r = i + a[i] - 1;
	}
    return a;
}

bool check(int mid, auto& z, int k) {
    int last = 0, seg = 1;
    for (int i = 1; i < n; i++) {
        if (z[i] >= mid && i - last >= mid) {
            seg++;
            last = i;
        }
    }
    if (seg >= k) return true;
    return false;
}

void solve() {
    cin >> n >> k1 >> k2;
    cin >> s;
    auto z = z_algorithm(s);
    vector<int> ans(n + 1, 0);
    const int E = floor(sqrt(n));
    for (int k = 1; k <= E; k++) {
        int l = 0, r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(mid, z, k)) l = mid;
            else r = mid;
        }
        ans[k] = l;  
    }

    for (int len = 1; len <= E; len++) {
        int last = 0, seg = 1;
        for (int i = 1; i < n; i++) {
            if (z[i] >= len && i - last >= len) {
                seg++;
                last = i;
            }
        }
        ans[seg] = max(ans[seg], len);
    }
    for (int i = n - 1; i >= 1; i--) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = k1; i <= k2; i++) cout << ans[i] << ' ';
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
问题：和上一题相似，只不过改为求f[l]到f[r]的值
思路：先求出f[1~n]的值，再根据l和r输出
        首先，考虑当k <= 根号n时, 用easy版本的方法求解，时间复杂度为: 根号n * nlogn
        再看k > 根号n时，根据k * lcp <= n，可以发现lcp <= 根号n，那么考虑遍历所有可能的lcp值，并且求出当前lcp值下最大的k值，不断更新ans[k]即可
*/