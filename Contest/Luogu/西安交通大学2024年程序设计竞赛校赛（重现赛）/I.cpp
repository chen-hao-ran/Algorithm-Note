#include <bits/stdc++.h>

#define ll long long
#define u32 unsigned int
#define u64 unsigned long long
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
using namespace std;
const ll infll = 1 << 63 - 1;
const int infint = 1 << 31 - 1;
const int inf = 0x3f3f3f3f;

const int maxn =2e6+5;
struct node {
    int node;
}tree[maxn][30];

int sonnum[maxn];
int son[maxn];
int fa[maxn];
int flagg[maxn];
int tot;
int cmdnum;

void insert_(const string str)
{
   int len = str.length();
   int root = 0;
   for(int i = 0; i < len; i++)
   {
       int id = str[i] - 'a';
       if(!tree[root][id].node) {
            tree[root][id].node = ++tot;
            fa[tree[root][id].node] = root;
            sonnum[root]++;
            son[root] = tot;
       }
       root = tree[root][id].node;
   }
   flagg[root] = ++cmdnum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    // cout << n << m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert_(s);
    }
    // cout << tot << '\n';
    string str;
    cin >> str;
    int root = 0;
    for (int i = 0; i < m; i++) {
        if (str[i] == 'T') {
            while (sonnum[root] == 1 && !flagg[root]) {
                root = son[root];
            }
        }
        else if (str[i] == 'B') {
            root = fa[root];
        }
        else if (str[i] == 'E') {
            if (flagg[root]) {
                cout << flagg[root] << ' ';
            } else {
                cout << -1 << ' ';
            }
            // cout << root << '\n';
            // cout << tot << '\n';
            root = 0;
        }
        else {
            int id = str[i] - 'a';
            if (!tree[root][id].node) {
                tree[root][id].node = ++tot;
                fa[tree[root][id].node] = root;
            }
            root = tree[root][id].node;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
