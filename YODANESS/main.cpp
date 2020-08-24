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
const int MAXN = 30000;
int BIT[MAXN + 1];
int query(int pos, int n)
{
    int res = 0;
    assert(pos <= n);
    while (pos > 0)
    {
        res += BIT[pos];
        pos -= (pos & (-pos));
    }
    return res;
}
void update(int pos, int value, int n)
{
    while (pos <= n)
    {
        BIT[pos] += value;
        pos += (pos & (-pos));
    }
}
void solve()
{
    test(zzz)
    {
        int n;
        cin >> n;
        // init BIT
        rep(i, 0, n)
        {
            BIT[i + 1] = 0;
        }
        error(n);
        vector<string> inp(n);
        string words;
        map<string, int> mp; // mapping
        rep(i, 0, n)
        {
            cin >> inp[i];
        }
        rep(i, 0, n)
        {
            cin >> words;
            mp[words] = i + 1;
        }

        int ans = 0;
        rep(i, 0, n)
        {
            ans += i - query(mp[inp[i]], n);
            update(mp[inp[i]], 1, n);
        }
        error(ans);
        cout << ans << endl;
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