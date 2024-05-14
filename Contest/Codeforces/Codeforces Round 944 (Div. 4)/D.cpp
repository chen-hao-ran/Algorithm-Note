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
    string s;
    cin >> s;
    int len = s.length();
    vector<int> pre(len + 5, 0);
    for (int i = 1; i <= len; i++) {
        pre[i] = pre[i - 1] + (s[i - 1] == '1');
    }

    bool flag = false;
    int cnt = 0;
    char last = 's';
    for (int i = len - 1; i >= 0; i--) {
        if (flag) {
            if (s[i] != last) cnt++;
            last = s[i];
        } else {
            if (s[i] != last) {
                if (s[i] == '0') {
                    if (last == '1') {
                        flag = true;
                        last = '0';
                    }
                    else {
                        cnt++;
                        last = '0';
                    }
                } else {
                    cnt++;
                    last = '1';
                }
            }
        }
    }   
    cout << cnt << '\n';
    // for (int i = 1; i <= len; i++) {
    //     cout << pre[i] << ' ';
    // }
    // cout << '\n';
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
