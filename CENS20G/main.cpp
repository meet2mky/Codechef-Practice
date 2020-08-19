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
    test(zzzz)
    {
        string ch;
        cin >> ch;
        int L = 0;
        int R = 0;
        int D = 0;
        int U = 0;
        for (auto x : ch)
        {
            if (x == 'L')
            {
                L--;
            }
            else if (x == 'R')
            {
                R++;
            }
            else if (x == 'U')
            {
                U++;
            }
            else if (x == 'D')
            {
                D--;
            }
        }
        int x1, x2, y1, y2;
        cin >> x1 >> y1;
        int q;
        cin >> q;
        while (q--)
        {
            cin >> x2 >> y2;
            x2 -= x1;
            y2 -= y1;
            if (x2 >= L && x2 <= R && y2 <= U && y2 >= D)
            {
                cout << "YES " << abs(x2) + abs(y2) << '\n';
            }
            else
            {
                cout << "NO\n";
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