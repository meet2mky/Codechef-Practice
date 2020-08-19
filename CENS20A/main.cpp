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
void solve()
{
    int n, m;
    cin >> n >> m;
    char g[n][m];
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    int q;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> g[i][j];
        }
    }
    cin >> q;
    int x1, x2, y1, y2;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        dp[x1][y1] += 1;
        dp[x1][y2 + 1] -= 1;
        dp[x2 + 1][y1] -= 1;
        dp[x2 + 1][y2 + 1] += 1;
    }
    rep(i, 0, n)
    {
        rep(j, 1, m)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }
    rep(j, 0, m)
    {
        rep(i, 1, n)
        {
            dp[i][j] += dp[i - 1][j];
        }
    }
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (dp[i][j] % 2 == 1)
            {
                cout << (char)(g[i][j] ^ '1' ^ '0');
            }
            else
            {
                cout << g[i][j];
            }
        }
        cout << '\n';
    }
    cout << '\n';
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