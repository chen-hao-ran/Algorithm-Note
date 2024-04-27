#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        
        int sum = n;
        for (int d = 2; d <= n / d; d++) {
            int x = n % d; 
            if (x == 0) {
                sum = sum / d * (d - 1);
                while (n % d == 0) n /= d;
            }
        }
        cout << n << ' ' << '\n';

        if (n != 1) sum = sum / n * (n - 1);
        cout << sum << '\n';
    }
    return 0;
}

/*
问题：求解n以为所有与n互质的数的个数
思路：问题可以转化成容斥原理，所求的个数等同于（n以为的不整除n任何一个素因子的数的个数）
核心目标：找出n的所有素因子，并通过公式计算出最终答案
注意点：1. d <= n / d 是为了防止超时，若d > n / d 且整除与n，那么在根号n之内一定会有一个数也整除与n，所以只需要根号n以为的即可
       2. 最后需要判定n是否为1，因为有可能d > n / d 时素因子还找全，那么最后的非1的n也是素因子   
*/