/*****************************************************************
IN GOD WE TRUST !!   

Author:- meet2mky
Date: -
Problem:-
Institue:- NITA
******************************************************************/
#include <iostream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>
#include <cassert>
#include <cctype>
#include <stack>
#include <ctime>
#include <iterator>
#include <sstream>
using namespace std;
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repi(i, a, b) for (int i = (a); i > (b); i--)
#define all(x) (x).begin(), (x).end()
#define setall(x, val) fill(all(x), val)
#define pb push_back
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define endl '\n'
#define MOD 1000000007
#define ll long long
#define ld long double
#define SZ(z) (int)(z).size()
#define test(t) \
    int t;      \
    cin >> t;   \
    while (t--)

#define int long long
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
const int mod = 1e9 + 7;
//variadic functions
template <typename T>
T sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

//Debugger  -------------------------------------------->
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
//Debugger  <--------------------------------------------
template <typename T>
T gcd(T a, T b)
{
    return a == 0 ? b : gcd(b % a, a);
}
template <typename T>
T mulmod(T a, T b, T m)
{
    //assumed a and b in [0...(m-1)];
    return (a * b) % m;
}
template <typename T>
T addmod(T a, T b, T m)
{
    //assumed a and b in [0...(m-1)];
    return a + b >= m ? a + b - m : a + b;
}
template <typename T>
T submod(T a, T b, T m)
{
    //assumed a and b in [0...(m-1)];
    return a - b < 0 ? a - b + m : a - b;
}
int C2(int N)
{
    return (N * (N - 1)) / 2;
}
int powmod(int a, int b, int m)
{
    int res = 1LL;
    while (b > 0)
    {
        if (b & 1LL)
        {
            res = mulmod(res, a, m);
        }
        b /= 2LL;
        a = mulmod(a, a, m);
    }
    return res;
}
int C(int n, int r)
{
    int up = 1;
    int dwn = 1;
    rep(i, 0, r)
    {
        up = mulmod(up, n, mod);
        n--;
        dwn = mulmod(i + 1, dwn, mod);
    }
    int modinv = powmod(dwn, mod - 2, mod);
    up = mulmod(up, modinv, mod);
    return up;
}

void solve()
{
    test(zzz)
    {
        int n, m, ai;
        cin >> n >> m;
        int cnt[n] = {0};
        bool ok = true;
        int res = 1;
        rep(i, 1, n)
        {
            cin >> ai;
            cnt[ai]++;
        }
        cnt[0] = 1;
        rep(i, 1, n)
        {
            if (cnt[i] > 0)
            {
                if (cnt[i - 1] == 0)
                {
                    ok = false;
                }
                else
                {

                    int mult = powmod(cnt[i - 1], cnt[i], mod);
                    res = mulmod(res, mult, mod);
                }
            }
            if (ok == false)
            {
                break;
            }
        }
        if (!ok)
        {
            cout << "0\n";
        }
        else
        {
            int rem_edges = m - (n - 1);
            if (rem_edges == 0)
            {
                cout << res << '\n';
            }
            else
            {
                int max_edges_poss = 0;
                rep(i, 1, n)
                {
                    max_edges_poss += C2(cnt[i]);
                }
                if (max_edges_poss >= rem_edges)
                {
                    int ways = C(max_edges_poss, rem_edges);
                    res = mulmod(res, ways, mod);

                    cout << res << '\n';
                }

                else
                {
                    cout << "0\n";
                }
            }
        }
    }
}

signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}