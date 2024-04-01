#include <bits/stdc++.h>

using namespace std;

const int N = 5000010;

struct Node {
    int s, c, d;
    bool operator<(const Node& other) {
        if (s != other.s) return s < other.s;
        if (c != other.c) return c < other.c;
        return d < other.d;
    }
}cdsum[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    int k = 0;
    for (int c = 0; c * c <= n; c++) {
        for (int d = c; c * c + d * d <= n; d++) {
            cdsum[k++] = {c * c + d * d, c, d};
        }
    }
    sort (cdsum, cdsum + k);

    for (int a = 0; a * a <= n; a++) {
        for (int b = a; a * a + b * b <= n; b++) {
            int last = n - a * a - b * b;
            // int l = 0, r = k - 1;
            // while(l < r)
            // {
            //     int mid = l + r >> 1;
            //     if(cdsum[mid].s >= last) r = mid;
            //     else l = mid + 1;
            // }
            int l = -1, r = k - 1;
            while (l + 1 < r) {
                int mid = l + r >> 1;
                if (cdsum[mid].s >= last) r = mid;
                else l = mid;
            }

            if (cdsum[r].s == last) {
                cout << a << ' ' << b << ' ' << cdsum[r].c << ' ' << cdsum[r].d << endl;   
                return 0;
            }
        }
    }

    return 0;
}



