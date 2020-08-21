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
const int N = 1000010;
vi spf(N, -1);
void sieve()
{
    rep(i, 0, N) spf[i] = i;
    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
            {
                spf[j] = i;
            }
        }
    }
}
void solve()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> mp;
        int n;
        cin >> n;
        while (n--)
        {
            int var;
            cin >> var;
            while (var > 1)
            {
                mp[spf[var]]++;
                var /= spf[var];
            }
        }
        int ans = 1;
        for (auto x : mp)
        {
            ans *= (x.second + 1);
        }
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