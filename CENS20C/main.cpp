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
vi prefix_fun(string &str)
{
    int n = SZ(str);
    vi p(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while (j > 0 && str[i] != str[j])
        {
            j = p[j - 1];
        }
        if (str[i] == str[j])
            j++;
        p[i] = j;
    }
    return p;
}
void solve()
{
    string s, t;
    cin >> s >> t;
    int n_s = SZ(s);
    int q, n;
    cin >> q;
    string here = t;
    here += '#';
    here += s;
    here += s;
    vi pi = prefix_fun(here);
    int t_s = SZ(t);
    vi dp(2 * n_s + 1, 0);
    rep(i, 1, 2 * n_s + 1)
    {
        dp[i] += dp[i - 1] + (pi[i + t_s] == t_s);
    }
    while (q--)
    {
        cin >> n;
        int full = n / n_s;
        int partial = n - full * n_s;
        int ans = 0;
        ans += full * dp[n_s];
        ans += max(full - 1, 0) * (dp[2 * n_s] - 2 * dp[n_s]);
        if (full > 0)
            ans += (dp[n_s + partial] - dp[n_s] - dp[partial]);
        ans += dp[partial];
        cout << ans << '\n';
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