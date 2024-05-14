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

int n, k1, k2, k;
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

bool check(int mid, auto& z) {
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
    assert(k1 == k2);
    k = k1;
    cin >> s;
    auto z = z_algorithm(s);

    // for (int i = 0; i < n; i++) cout << z[i] << ' ';
    // cout << '\n';

    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid, z)) l = mid;
        else r = mid;
        // cout << "mid: " << mid << " check: " << check(mid, z) << '\n';
    }
    cout << l << '\n';
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
问题：给定一个字符串，设定f_i为将字符串分割为i个连续子串后他们的最大公共前缀(LCP)，问f_k是多少
思路：先考虑用z函数处理每个位置与整个字符串的最大公共前缀，再考虑二分答案，在检查函数中贪心的寻找下一个端点，只要z[i] > mid并且他与前一个子串的端点距离至少为mid，就将他加入端点，
        比较找到的端点数与k
*/