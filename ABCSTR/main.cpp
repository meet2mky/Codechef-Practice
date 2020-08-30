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
#include <iomanip>
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
#define sp(x) setprecision(x)
#define endl '\n'
#define ll long long
#define ld long double
#define SZ(z) (int)(z).size()
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define eps 0.0000001 // eps = 1e-7
#define PI 3.141592653589793238

//#define int long long
const int MOD = 1000000007;

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
struct HASH
{
    size_t operator()(const pair<int, int> &x) const
    {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};
void solve()
{
    ll res = 0;
    string s;
    cin >> s;
    int n = SZ(s);
    vvi dp(n, vi(3, 0));
    dp[0][s[0] - 'A'] = 1;
    rep(i, 1, n)
    {
        dp[i][0] += dp[i - 1][0];
        dp[i][1] += dp[i - 1][1];
        dp[i][2] += dp[i - 1][2];
        dp[i][s[i] - 'A']++;
    }
    unordered_map<pair<int, int>, int, HASH> mp;
    mp[{0, 0}] = 1;
    rep(i, 0, n)
    {
        int x = dp[i][0] - dp[i][1];
        int y = dp[i][1] - dp[i][2];
        res += (ll)mp[{x, y}];
        mp[{x, y}]++;
    }
    cout << res << '\n';
}

signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}