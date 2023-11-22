// Problem: B. Toy Blocks
// Contest: Codeforces - Educational Codeforces Round 98 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1452/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    int n,m;
    cin >> n;
    vl block(n+1);
    ll sum = 0, ans = 0 , mx= -1LL;
    for(int i = 1; i <= n; i++){
    	cin >> block[i];
    	sum += block[i];
    	mx = max(mx,block[i]);
    }
    ll div = ceil((double) sum / (double)(n-1));
    ll temp = max(div , mx);
    ans = temp*(n-1) - sum;
    cout << ans << "\n";
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1 ;
    cin >> t ;
    while (t--)
    {
        solve();
    }

    return 0 ;
}