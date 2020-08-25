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

// using bit can also be solved using seg trees
const int N = 300009;
int BIT[N];
int n, q;
void update(int pos, int value, int n)
{
    while (pos <= n)
    {
        BIT[pos] += value;
        pos += (pos & (-pos));
    }
}
int query(int pos, int n)
{
    assert(pos <= n);
    int res = 0;
    while (pos > 0)
    {
        res += BIT[pos];
        pos -= (pos & (-pos));
    }
    return res;
}
void solve()
{
    cin >> n;
    vector<pii> a(n);
    rep(i, 0, n)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    cin >> q;
    vector<pair<pii, pii>> queries(q);
    vi ans(q, 0);
    rep(i, 0, q)
    {
        cin >> queries[i].second.first >> queries[i].second.second >> queries[i].first.first;
        queries[i].first.second = i;
    }

    sort(all(a));
    sort(all(queries));
    reverse(all(queries));
    reverse(all(a));
    int current_loc = -1;
    rep(i, 0, q)
    {
        int l = queries[i].second.first;
        int r = queries[i].second.second;
        int here = queries[i].first.second;
        int k_now = queries[i].first.first;
        while (current_loc + 1 < n && a[current_loc + 1].first > k_now)
        {
            update(a[current_loc + 1].second, 1, n);
            current_loc++;
        }
        ans[here] = query(r, n) - query(l - 1, n);
    }
    rep(i, 0, q)
    {
        cout << ans[i] << '\n';
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