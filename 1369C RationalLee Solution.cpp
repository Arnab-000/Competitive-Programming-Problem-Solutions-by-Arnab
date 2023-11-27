// Problem: C. RationalLee
// Contest: Codeforces - Codeforces Round 652 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1369/C
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
    int n,k; cin >> n >> k;
    vl temp;
    vl w(n); fx(w) cin >> x;
    vl f(k); fx(f) {cin >> x; if(x == 1)temp.pb(x);}
    
    sort(rall(w));
    sort(rall(f));
    fx(f) if(x!=1) temp.pb(x);
    ll l=0,r=n-1,ans=0;
    for(int i = 0; i < k; i++)
    {
        if(temp[i]==1)
        {
            ans+=(2*w[l]);
            l++;
        }
        else
        {
            ans+=(w[l]+w[r]);
            l++;
            r-=(temp[i]-1);
        }
    }
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