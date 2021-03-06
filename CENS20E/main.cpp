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
int find(int i, vi &p)
{
    if (p[i] == i)
        return i;
    return p[i] = find(p[i], p);
}
void uni(int a, int b, vi &sz, vi &p)
{
    a = find(a, p);
    b = find(b, p);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vi wi(n);
        rep(i, 0, n) cin >> wi[i];
        rep(i, 0, n)
        {
            wi[i] = __builtin_popcount(wi[i]);
            wi[i] = (wi[i] % 2 == 1);
        }
        vi p(n, -1);
        vi sz(n, 0);
        rep(i, 0, n)
        {
            sz[i] = 1;
            p[i] = i;
        }
        int u, v;
        rep(i, 0, m)
        {
            cin >> u >> v;
            u--;
            v--;
            if (wi[u] == wi[v])
                uni(u, v, sz, p);
        }
        int oddmax = 0;
        int evenmax = 0;
        rep(i, 0, n)
        {
            if (find(i, p) == i)
            {
                if (wi[i])
                    oddmax = max(oddmax, sz[i]);
                else
                    evenmax = max(evenmax, sz[i]);
            }
        }
        int q, type, k;
        cin >> q;
        while (q--)
        {
            cin >> type >> k;
            k = __builtin_popcount(k);
            k = (k % 2 == 1);
            type %= 2;
            if (type == k)
            {
                cout << evenmax << '\n';
            }
            else
            {
                cout << oddmax << '\n';
            }
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