#include <bits/stdc++.h>

using namespace std;

const int N = 100010;   

long long s[N];
map<long long, int> b;

int main() {
    int n, k;
    cin >> n >> k;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
        cnt += b[s[i] % k];
        b[s[i] % k]++;
        if (s[i] % k == 0) cnt++;
    }
    cout << cnt << endl;

    return 0;
}