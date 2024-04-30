#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool head = true;

        int i = 0, j = n - 1, cnt = 0;
        while (i <= j) {
            // cout << i << ' ' << j << '\n';
            if (i == j) {
                // cout << ":::" << cnt << '\n';
                if (a[i] > k) break;
                else {
                    cnt++;
                    i++;
                }
            } else {
                if (head) {
                    if (a[i] <= a[j]) {
                        if (2 * a[i] - 1 > k) break;
                        else {
                            k -= 2 * a[i] - 1;
                            a[j] -= a[i] - 1;
                            head = !head;
                            cnt++;
                            i++;
                        }
                    } else {
                        if (2 * a[j] > k) break;
                        else {
                            k -= 2 * a[j];
                            a[i] -= a[j];
                            cnt++;
                            j--;
                        }
                    }
                } else {
                    if (a[i] < a[j]) {
                        if (2 * a[i] > k) break;
                        else {
                            k -= 2 * a[i];
                            a[j] -= a[i];
                            cnt++;
                            i++;
                        }
                    } else {
                        if (2 * a[j] - 1 > k) break;
                        else {
                            k -= 2 * a[j] - 1;
                            a[i] -= a[j] - 1;
                            head = !head;
                            cnt++;
                            j--;
                        }
                    }
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}

/*
问题：给定一组数组，请问在k步内能抵消掉多少个位置的值，抵消方式为：首先在头部减1，再在尾部减1，如此循环直至到达k步
思路：若模拟k步操作，循环k次会超时，因此每次需要比较数组头尾两个位置的大小关系，必定有一个位置先被抵消，
        那么只需要分类讨论即可，用bool类型变量head存储目前处于头部还是尾部
ps：个人认为有更好的方法，没有深究
*/