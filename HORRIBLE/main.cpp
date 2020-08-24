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
#define mp make_pair
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

//variadic functions
template <typename T>
T sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

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
const int N = 200010;
const int N_2 = 100005;
int t[N];
int d[N_2];
int h, n, c, p, q, v, type;
void apply(int pos, int value, int k)
{
    t[pos] += value * k;
    if (pos < n)
    {
        d[pos] += value;
    }
}
void calc(int pos, int k)
{
    t[pos] = t[pos << 1] + t[pos << 1 | 1] + d[pos] * k;
}
void build(int l, int r)
{
    // builds bottom up [l....r)
    int k = 2;
    for (l += n, r += n - 1; l > 0; k <<= 1)
    {
        l >>= 1, r >>= 1;
        for (int i = r; i >= l; i--)
        {
            calc(i, k);
        }
    }
}
void push(int l, int r)
{
    // push top down to [l....r)
    l += n;
    r += n - 1;
    int k = (1LL << (h - 1));
    for (int s = h; s > 0; --s, k >>= 1)
    {
        for (int i = (l >> s); i <= (r >> s); i++)
        {
            if (d[i])
            {
                apply(i << 1, d[i], k);
                apply(i << 1 | 1, d[i], k);
                d[i] = 0;
            }
        }
    }
}
void update(int l, int r, int value) // [l....r) += value
{
    int l0 = l;
    int r0 = r;
    int k = 1;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1)
    {
        if (l & 1)
        {
            apply(l++, value, k);
        }
        if (r & 1)
        {
            apply(--r, value, k);
        }
    }
    build(l0, l0 + 1);
    build(r0 - 1, r0);
}
int query(int l, int r)
{
    int res = 0;
    push(l, l + 1);
    push(r - 1, r);
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res += t[l++];
        }
        if (r & 1)
        {
            res += t[--r];
        }
    }
    return res;
}
void solve()
{
    test(zzzz)
    {
        cin >> n >> c;
        rep(i, 0, n)
        {
            d[i] = t[i] = t[i + n] = 0;
        }
        h = 8LL * sizeof(int) - __builtin_clzll(n);
        while (c--)
        {
            cin >> type;
            if (type)
            {
                cin >> p >> q;
                p--;
                q--;
                cout << query(p, q + 1) << '\n';
            }
            else
            {
                cin >> p >> q >> v;
                p--;
                q--;
                update(p, q + 1, v);
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