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

//#define int long long
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

// Segment tree + merge sort / vectors
// Note: Official testcases are bugged
const int maxn = 600010;
vi t[maxn];
int n, l, r, k, q;
vi combine(int a, int b)
{
    int p = SZ(t[a]);
    int q = SZ(t[b]);
    vi here;
    int pi = 0, qi = 0;
    while (pi < p && qi < q)
    {
        if (t[a][pi] < t[b][qi])
        {
            here.push_back(t[a][pi++]);
        }
        else
        {
            here.push_back(t[b][qi++]);
        }
    }
    while (pi < p)
    {
        here.push_back(t[a][pi++]);
    }
    while (qi < q)
    {
        here.push_back(t[b][qi++]);
    }
    return here;
}
int compute(int pos, int k)
{
    // base case
    if (t[pos][0] > k)
        return SZ(t[pos]);
    if (t[pos].back() <= k)
        return 0;
    // invariant simple
    int l = 0;
    int r = SZ(t[pos]) - 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (t[pos][mid] > k)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return SZ(t[pos]) - r;
}
void build()
{
    for (int i = n - 1; i > 0; i--)
    {
        t[i] = combine(i << 1, i << 1 | 1);
    }
}
int query(int l, int r, int k)
{
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        // error(l, r);
        if (l & 1)
        {
            res += compute(l++, k);
        }
        if (r & 1)
        {
            res += compute(--r, k);
        }
    }
    return res;
}
void solve()
{
    cin >> n;
    //  error(n);
    rep(i, 0, n)
    {
        cin >> l;
        t[i + n].push_back(l);
    }
    build();
    cin >> q;
    //  error(q);
    rep(i, 0, q)
    {
        cin >> l >> r >> k;
        l--;
        r--;
        cout << query(l, r + 1, k) << '\n';
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