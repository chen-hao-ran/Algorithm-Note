#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> q;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) q.emplace_back(i);
    }

    int sum = 0;
    for (int i = 0; i < q.size(); i += 2) {
        sum += q[i + 1] - q[i];
    }
    cout << sum << endl;

    return 0;
}