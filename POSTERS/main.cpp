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
vi t;
vi d;
int n, q, l, r, h;
void apply(int pos, int value)
{
    t[pos] = value;
    if (pos < n)
    {
        d[pos] = value;
    }
}
void push(int l, int r)
{
    l += n;
    r += n - 1;
    int k = (1 << (h - 1));
    for (int s = h; s > 0; s--, k >>= 1)
    {
        for (int i = l >> s; i <= r >> s; i++)
        {
            if (d[i])
            {
                apply(i << 1, d[i]);
                apply(i << 1 | 1, d[i]);
                d[i] = 0;
            }
        }
    }
}
void update(int l, int r, int value)
{
    push(l, l + 1);
    push(r - 1, r);
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            apply(l++, value);
        }
        if (r & 1)
        {
            apply(--r, value);
        }
    }
    // we don't need to build! do we?
}
void solve()
{
    cin >> q;
    vector<pii> queries(q);
    map<int, int> mp;
    rep(i, 0, q)
    {
        cin >> l >> r;
        mp[l]++;
        mp[r]++;
        queries[i] = {l, r};
    }
    vi coo;
    for (auto x : mp)
    {
        coo.emplace_back(x.first);
    }
    rep(i, 0, SZ(coo))
    {
        mp[coo[i]] = i + 1;
    }
    // one based indexed
    n = SZ(coo);

    t.resize(2 * n + 10);
    setall(t, 0);
    d.resize(n + 5);
    setall(d, 0);
    h = 8 * sizeof(int) - __builtin_clz(n);
    rep(i, 0, q)
    {
        int l = mp[queries[i].first];
        int r = mp[queries[i].second];
        l--;
        r--;
        // we never used 0 as update
        update(l, r + 1, i + 1);
    }
    push(0, n);
    map<int, int> ans;
    rep(i, 0, n)
    {
        if (t[i + n] != 0)
            ans[t[i + n]]++;
    }
    cout << SZ(ans) << '\n';
}
signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    test(zzzz)
        solve();
    return 0;
}