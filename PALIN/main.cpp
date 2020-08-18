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
    int t;
    cin >> t;
    while (t--)
    {
        string num;
        cin >> num;
        string nine(SZ(num), '9');
        if (num == nine)
        {
            string zero(SZ(num) + 1, '0');
            zero[0] = zero[SZ(num)] = '1';
            cout << zero << '\n';
            continue;
        }
        if (SZ(num) == 1)
        {
            cout << ++num[0] << '\n';
            continue;
        }
        char mid = '_';
        if (SZ(num) & 1)
        {
            mid = num[SZ(num) / 2];
        }
        string rnum = num;
        rnum.resize(SZ(rnum) / 2);
        reverse(all(rnum)); //
        reverse(all(num));
        num.resize(SZ(num) / 2);
        reverse(all(num));
        if (mid != '_')
        {
            if (rnum > num)
            {
                reverse(all(rnum));
                cout << rnum;
                cout << mid;
                reverse(all(rnum));
                cout << rnum;
            }
            else
            {
                reverse(all(rnum));
                if (mid == '9')
                {
                    mid = '0';
                    repi(i, SZ(rnum) - 1, -1)
                    {
                        if (rnum[i] < '9')
                        {
                            rnum[i]++;
                            rep(j, i + 1, SZ(rnum))
                            {
                                rnum[j] = '0';
                            }
                            break;
                        }
                    }
                }
                else
                {
                    mid++;
                }
                cout << rnum;
                cout << mid;
                reverse(all(rnum));
                cout << rnum;
            }
        }
        else
        {
            if (rnum > num)
            {
                reverse(all(rnum));
                cout << rnum;
                reverse(all(rnum));
                cout << rnum;
            }
            else
            {
                reverse(all(rnum));
                //     cout << "Need Reversal: " << rnum << endl;
                repi(i, SZ(rnum) - 1, -1)
                {
                    if (rnum[i] < '9')
                    {
                        rnum[i]++;
                        rep(j, i + 1, SZ(rnum))
                        {
                            rnum[j] = '0';
                        }
                        break;
                    }
                }
                cout << rnum;
                reverse(all(rnum));
                cout << rnum;
            }
        }
        cout << "\n";
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