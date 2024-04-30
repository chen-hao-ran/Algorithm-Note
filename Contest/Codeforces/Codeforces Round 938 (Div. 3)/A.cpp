#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        int res = 0;
        if (2 * a >= b) res += n / 2 * b + (n % 2) * a;
        else res += n * a;
        cout << res << '\n';
    }

    return 0;
}

/*
问题：给定三个数要买的商品数n，单买一件商品的价格a，同时买两件商品的价格b，问如何用最低的价格买到n个商品
思路：1. 若2 * a <= b，说明同时买两件商品没有任何优惠
      2. 若2 * a > b, 说明同时买两件商品有优惠，那么需要再判断n的奇偶性，若为偶则直接以同时买两件商品的方式购买，若为奇，则前n - 1个商品以同时买两件商品的方式购买，最后一件以单买的方式购买

*/