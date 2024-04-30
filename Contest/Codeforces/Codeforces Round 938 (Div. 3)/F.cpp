#include <bits/stdc++.h>

using namespace std;

void solve() { 
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sum = d / 2;
    int extra = (a % 2 && b % 2 && c % 2);
    sum += (a / 2) + (b / 2) + (c / 2) + extra;
    cout << sum << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
问题：给定四个数字分别代表1，2，3，4的个数，请问在每进行一次对局就要选择其中一个数减1的情况下，假定所有数字异或和为0的情况为ans，如何操作使ans最大
思路：首先，数字4与其他三个数字没有关系，所以只要4的个数为偶数那么才有可能得到结果0
        再看a，b，c，可以发现若要异或和为0，那么a，b，c必须同为奇数或者同为偶数，计算出每个数字个数为偶数的情况有多少种，相加后特判初始情况是否为奇数，若是则再加1
        
*/