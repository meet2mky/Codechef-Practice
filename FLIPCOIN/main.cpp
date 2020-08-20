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
#define dbg(x) cout << #x << " is: " << x << endl
#define test(t) \
    int t;      \
    cin >> t;   \
    while (t--)
//#define int long long
#define inf 0x3f3f3f3f
const int N = 200010;
const int N_2 = 100005;
int n, h;
pair<int, int> t[N];
int d[N];
void apply(int pos)
{
    swap(t[pos].first, t[pos].second);
    if (pos < n)
    {
        d[pos] ^= 1;
    }
}
pair<int, int> add(pair<int, int> a, pair<int, int> b)
{
    return {a.first + b.first, a.second + b.second};
}
void build()
{
    for (int i = n - 1; i > 0; i--)
    {
        t[i] = add(t[i << 1], t[i << 1 | 1]);
    }
}
void build(int pos)
{
    pos >>= 1;
    for (; pos > 0; pos >>= 1)
    {
        t[pos] = add(t[pos << 1], t[pos << 1 | 1]);
        if (d[pos])
        {
            swap(t[pos].first, t[pos].second);
        }
    }
}
void update(int l, int r)
{
    l += n;
    r += n;
    int r0 = r;
    int l0 = l;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            apply(l++);
        }
        if (r & 1)
        {
            apply(--r);
        }
    }
    build(l0);
    build(r0 - 1);
}
void push(int pos)
{
    for (int s = h; s > 0; --s)
    {
        int i = (pos >> s);
        if (d[i])
        {
            apply(i << 1);
            apply(i << 1 | 1);
            d[i] = 0;
        }
    }
}
pair<int, int> query(int l, int r)
{
    pair<int, int> res = {0, 0};
    l += n;
    r += n;
    push(l);
    push(r - 1);
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res = add(res, t[l++]);
        }
        if (r & 1)
        {
            res = add(t[--r], res);
        }
    }
    return res;
}
void solve()
{
    cin >> n; // {head,tail}
    h = 8 * sizeof(int) - __builtin_clz(n);
    for (int i = 0; i < n; i++)
    {
        t[i + n] = {0, 1};
    }
    build();
    int q, type, l, r;
    cin >> q;
    while (q--)
    {
        cin >> type >> l >> r;
        r++;
        if (type == 0)
        {
            update(l, r);
        }
        else
        {
            cout << query(l, r).first << endl;
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