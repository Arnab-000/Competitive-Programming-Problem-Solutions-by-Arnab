// Problem: C. Adding Powers
// Contest: Codeforces - Educational Codeforces Round 83 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1312/C
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
    long long n,k;
    cin >> n >> k;
    vector<long long> v(n);
    fx(v) cin >> x;
    
    long long val = 1;
    while(val < 1e16){
      val *= k;
    }
    int cnt = 0;
    while (val > 0) {
      for (int i = 0; i < n; i++) {
        if (v[i] >= val) {
          v[i] -= val;
          cnt++;
        }
      }
      if (cnt > 1){
      	cout << "NO\n";
      	return;
      }
      cnt = 0;
      val /= k;
    }
    sort(rall(v));
    cout << (v[0]==0ll ? "YES" : "NO") << "\n";
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