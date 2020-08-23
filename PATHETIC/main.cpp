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
#define N (int)2e18
void solve()
{
    // max path len = 99
    // a number that is divisible by all nums from 1 to 99
    // let pi is a prime number s.t. 1 <= pi <= 99
    // let ai = pi^x s.t. pi^x <=99 and pi^(x+1) > 99
    // then req is product of all ai
    vector<int> ess = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int p1 = 1, p2 = 1;
    reverse(all(ess));
    for (auto x : ess)
    {
        if (p1 <= p2)
        {
            p1 *= x;
        }
        else
        {
            p2 *= x;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> g[n];
        rep(i, 1, n)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vi d(n, 0);
        vb vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        d[0] = 0;
        while (!q.empty())
        {
            int here = q.front();
            q.pop();
            for (auto nxt : g[here])
            {
                if (!vis[nxt])
                {
                    d[nxt] = d[here] + 1;
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        rep(i, 0, n)
        {
            if (d[i] & 1)
            {
                cout << p1 << ' ';
            }
            else
            {
                cout << p2 << ' ';
            }
        }
        cout << endl;
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