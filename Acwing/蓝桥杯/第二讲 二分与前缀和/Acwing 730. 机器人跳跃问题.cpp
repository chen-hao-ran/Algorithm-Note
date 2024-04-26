#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];
int n;

bool check(long long mid) {
    double e = mid;
    for (int i = 1; i <= n; i++) {
        e += e - a[i];
        if (e < 0) return false;
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long l = -1, r = 1e10;
    while (l + 1 < r) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;

    return 0;
}