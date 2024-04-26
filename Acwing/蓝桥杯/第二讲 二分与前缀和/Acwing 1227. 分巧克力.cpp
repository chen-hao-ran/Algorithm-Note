#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int h[N], w[N];
int n, k;

bool check(int mid) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += h[i] / mid * (w[i] / mid);
    }

    if (sum >= k) return true;
    else return false;
}

int main() {
    cin >> n >> k;
    int maxr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i];
        maxr = max(maxr, h[i]);
        maxr = max(maxr, w[i]);
    }

    int l = 0, r = maxr + 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;

    return 0;
}