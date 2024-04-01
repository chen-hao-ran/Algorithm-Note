#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        int l = -1, r = n;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (a[mid] <= k) l = mid;
            else r = mid;
        }
        int resr = l;
        l = -1, r = n;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (a[mid] < k) l = mid;
            else r = mid;
        }
        int resl = r;
        if (a[resr] != k || a[resl] != k) cout << -1 << ' ' << -1 << endl;
        else cout << resl << ' ' << resr << endl;
    }

    return 0;
}