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
const int MAXN = 10010;
const int MAXK = 51;
const int M = 5000000;
int BIT[MAXK][MAXN];
int query(int this_bit, int pos, int n)
{
    int res = 0;
    while (pos > 0)
    {
        res = addmod(res, BIT[this_bit][pos], M);
        pos -= (pos & (-pos));
    }
    return res;
}
void update(int this_bit, int pos, int value, int n)
{
    while (pos <= n)
    {
        BIT[this_bit][pos] = addmod(BIT[this_bit][pos], value, M);
        pos += (pos & (-pos));
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    map<int, int> mp; // mapping
    rep(i, 0, n)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vi here;
    for (auto x : mp)
    {
        here.emplace_back(x.first);
    }
    sort(all(here));
    rep(i,0,SZ(here))
    {
        mp[here[i]] = i + 1;
    }
    // upper_bound of bit is SZ(here)
    rep(i, 0, n)
    {
        a[i] = mp[a[i]];
    }
    int ans = 0;
    rep(i, 1, n + 1)
    {
        int pos = a[i - 1];
        rep(KK, 1, k + 1)
        {
            int res;
            if (KK == 1)
            {
                res = 0;
                update(KK, pos, 1, n);
            }
            else
            {
                res = query(KK - 1, pos - 1, n);
                update(KK, pos, res, n);
            }
        }
    }
    rep(i, 1, n + 1)
    {
        ans = addmod(ans, submod(query(k, i, n), query(k, i - 1, n), M), M);
    }
    error(ans);
    cout << ans << "\n";
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