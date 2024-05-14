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
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    int i = 0, j = 0;
    while (j < m) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else j++;
    }
    int ans = i;
    cout << ans << '\n';
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
问题：给定两个01组成的字符串a，b，请问a中的最大前缀是多少，使得该前缀属于b的子串
思路：贪心，a中的前缀字符在b中先匹配上的话就直接匹配，留更多位置给后面的字符
*/