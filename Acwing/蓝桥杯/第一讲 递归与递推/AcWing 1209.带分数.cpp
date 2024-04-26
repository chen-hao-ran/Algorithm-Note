#include <bits/stdc++.h>

using namespace std;

int num[10];

int calc(int i, int j) {
    int sum = 0;
    for (int x = i; x <= j; x++) {
        sum = sum * 10 + num[x];
    }

    return sum;
}

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < 9; i++) {
        num[i] = i + 1;
    }

    do {
        for (int i = 0; i < 7; i++) {
            for (int j = i + 1; j < 8; j++) {
                int x = calc(0, i);
                int y = calc(i + 1, j);
                int z = calc(j + 1, 8);
                if (y % z) continue;
                if (x + y / z == n) cnt++;
            }
        } 
    } while (next_permutation(num, num + 9));
    
    cout << cnt << endl;

    return 0;
}