#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;

int main() {
    double n;
    cin >> n;
    double l = -100.0, r = 100.0;
    while(l < r - eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid <= n) l = mid;
        else r = mid;
    }
	cout << fixed << setprecision(6);
    cout << l << endl;

    return 0;
}