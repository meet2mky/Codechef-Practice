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

//#define int long long
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
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
const int N = 200009;
const int N_2 = 100005;
int d[N_2];

int n, h, l, r, v, q;
struct Node
{
    int cnt[3];
    Node()
    {
        cnt[0] = cnt[1] = cnt[2] = 0;
    }
};
Node t[N];
Node combine(const Node &a, const Node &b)
{
    Node t;
    rep(i, 0, 3) t.cnt[i] = a.cnt[i] + b.cnt[i];
    return t;
}
Node rotate_right(Node &a, int numr)
{
    Node here;
    rep(i, 0, 3)
    {
        here.cnt[(i + numr) % 3] = a.cnt[i];
    }
    return here;
}
void apply(int pos, int value)
{
    // this node t[pos] include this effect
    // how are you today?
    t[pos] = rotate_right(t[pos], value);
    if (pos < n)
    {
        d[pos] += value;
    }
}
void calc(int pos)
{

    // so many swaps going on?
    t[pos] = combine(t[pos << 1], t[pos << 1 | 1]);
    t[pos] = rotate_right(t[pos], d[pos]);
}
void build()
{
    for (int i = n - 1; i > 0; i--)
    {
        t[i] = combine(t[i << 1], t[i << 1 | 1]);
    }
}
void build(int pos)
{
    for (pos >>= 1; pos > 0; pos >>= 1)
    {
        calc(pos);
    }
}
void update(int l, int r, int value)
{
    l += n;
    r += n;
    int l0 = l;
    int r0 = r;
    for (; l < r; l >>= 1, r >>= 1)
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
    build(l0);
    build(r0 - 1);
}
void push(int pos)
{
    int s = h;
    for (; s > 0; --s)
    {
        int id = (pos >> s);
        if (d[id])
        {
            apply(id << 1, d[id]);
            apply(id << 1 | 1, d[id]);
            d[id] = 0;
        }
    }
}
Node query(int l, int r)
{
    Node res;
    l += n;
    r += n;
    push(l);
    push(r - 1);
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            res = combine(res, t[l++]);
        }
        if (r & 1)
        {
            res = combine(t[--r], res);
        }
    }
    return res;
}
void solve()
{
    cin >> n >> q;
    //error(n, q);
    rep(i, 0, n)
    {
        t[i + n].cnt[0] = 1;
    }
    h = 8 * sizeof(int) - __builtin_clz(n);
    //error(h);
    build();
    //error(query(0, n).cnt[0]);
    rep(i, 0, q)
    {
        cin >> v >> l >> r;
        if (v)
        {
            cout << query(l, r + 1).cnt[0] << "\n";
        }
        else
        {
            update(l, r + 1, 1);
        }
    }
    error("I do not stop!");
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