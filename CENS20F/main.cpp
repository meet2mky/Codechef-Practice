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
#define int long long
#define inf 0x3f3f3f3f
void dfs(int root, vi &a, vvi &g, vi &q, vector<bool> &vis, int d = 0, int evenId = -1, int oddId = -1)
{
    vis[root] = true;
    if (d && oddId != -1)
    {
        a[oddId] += a[root];
        a[root] = 0;
    }
    if (!d && evenId != -1)
    {
        a[evenId] += a[root];
        a[root] = 0;
    }

    for (auto x : g[root])
    {

        if (!vis[x])
        {
            int tevenId = evenId, toddId = oddId;
            if (tevenId == -1)
            {
                if (d == 0 && q[root])
                {
                    tevenId = root;
                }
            }
            if (toddId == -1)
            {
                if (d == 1 && q[root])
                {
                    toddId = root;
                }
            }
            dfs(x, a, g, q, vis, d ^ 1, tevenId, toddId);
        }
    }
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, qsz, u, v;
        cin >> n >> qsz;
        vvi g;
        g.resize(n);
        vi a(n);
        rep(i, 0, n)
        {
            cin >> a[i];
        }
        vi q(n);
        rep(i, 1, n)
        {
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        while (qsz--)
        {
            cin >> v;
            v--;
            q[v] = 1;
        }
        vector<bool> vis(n, false);
        dfs(0, a, g, q, vis);
        for (auto x : a)
        {
            cout << x << ' ';
        }
        cout << '\n';
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