// Problem: B. Amr and Pins
// Contest: Codeforces - Codeforces Round 287 (Div. 2)
// URL: https://codeforces.com/problemset/problem/507/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Catalyst71

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nn endl
#define sp " "
#define fx(s) for(auto &x:s)
#define EPS 1e-10
#define vl vector<ll>
#define vi vector<int>
#define dbp(x) cout << #x << " = " << x << endl
int dx[8] = {1, -1, 0,  0, 1,  1, -1, -1};
int dy[8] = {0,  0, 1, -1, 1, -1,  1, -1};

void solve()
{
    /* 0 ? 1 ? n ? equal ? */
    double r,x1,y1,x2,y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    r *= 2;
    double dis = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    cout << ceil(dis/r) ;
    
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1 ;
    //cin >> t ;
    while (t--)
    {
        solve();
    }

    return 0 ;
}