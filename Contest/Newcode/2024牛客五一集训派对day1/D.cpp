#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define ll __int128
using namespace std;
 
 
bool ok = true;
 
inline void print(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
 
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
     
    ll xx, yy;
    ll d = exgcd(b, a % b, xx, yy);
    x = yy;
    y = xx - a / b * yy;
 
    return d;
}
 
void merge(ll& a, ll& b, ll c, ll d) {
    ll x, y, g, t;
    g = exgcd(b, d, x, y);
    if ((c - a) % g != 0) {
        ok = false;
        return;
    }
    d /= g;
    t = ((c - a) / g) % d * x % d;
    if (t < 0) t += d;
    a = b * t + a;
    b = b * d;
    if (b < 0) b = -b;
}
 
void solve() {
    ll n = 0, k = 0, a = 0, b = 1, c = 0, d = 0;
    scanf("%lld%lld", &n, &k);
    scanf("%lld%lld", &b, &a);
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld", &d, &c);
        merge(a, b, c, d);
    }
 
    ll ans = (a % b + b) % b;
    if (!ok) cout << "he was definitely lying" << '\n';
    else {
        if (ans > k) cout << "he was probably lying" << '\n';
        else print(ans);
    }
}
 
int main() {
    solve();
     
    return 0;
}

/*
此题会爆long long，增量法过了，素因子分解法只过了95%，找不出原因
原题链接：https://ac.nowcoder.com/acm/contest/80186/D
*/
// #include <bits/stdc++.h>

// #define ll __int128
// #define pll pair<ll, ll>
// #define all(x) (x).begin(), (x).end()
// using namespace std;


// bool ok = true;

// inline void print(__int128 x)
// {
//     if(x<0)
//     {
//         putchar('-');
//         x=-x;
//     }
//     if(x>9)
//         print(x/10);
//     putchar(x%10+'0');
// }

// ll exgcd(ll a, ll b, ll& x, ll& y) {
//     if (b == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     }
    
//     ll xx, yy;
//     ll d = exgcd(b, a % b, xx, yy);
//     x = yy;
//     y = xx - a / b * yy;

//     return d;
// }

// void merge(ll& a, ll& b, ll c, ll d) {
//     ll x, y, g, t;
//     g = exgcd(b, d, x, y);
//     if ((c - a) % g != 0) {
//         ok = false;
//         return;
//     }
//     d /= g;
//     t = ((c - a) / g) % d * x % d;
//     if (t < 0) t += d;
//     a = b * t + a;
//     b = b * d;
//     if (b < 0) b = -b;
// }

// void solve() {
//     ll n = 0, k = 0, a = 0, m = 0;
//     map<int, vector<pll>> eqns;
//     vector<pll> crt;
//     scanf("%lld%lld", &n, &k);
//     for (int i = 1; i <= n; i++) {
//         scanf("%lld%lld", &m, &a);
//         for (ll d = 2; d <= m / d; d++) {
//             if (m % d == 0) {
//                 ll p = d, pe = 1;
//                 while (m % p == 0) {
//                     m /= p;
//                     pe = pe * p;
//                 }
//                 eqns[p].push_back({pe, a % pe});
//             }
//         } 
//         if (m != 1) eqns[m].push_back({m, a % m});

//         for (auto eq : eqns) {
//             auto eqn = eq.second;
//             auto maxp = *max_element(all(eqn));
//             crt.push_back(maxp);
//             int maxpe = maxp.second;
            
//             for (auto p : eqn) {
//                 if (maxpe % p.first != p.second) ok = false;
//              }
//         }

//     }

//     a = 0;
//     ll b = 1, c = 0, d = 0;
//     for (auto eq : crt) {
//         c = eq.second, d = eq.first;
//         merge(a, b, c, d);
//     }

//     ll ans = (a % b + b) % b;
//     if (!ok) cout << "he was definitely lying" << '\n';
//     else {
//         if (ans > k) cout << "he was probably lying" << '\n';
//         else print(ans);
//     }
// }

// int main() {
//     solve();
    
//     return 0;
// }


