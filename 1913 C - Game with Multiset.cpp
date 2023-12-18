// Problem: C. Game with Multiset
// Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1913/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll LOG2(ll n){ll v=1,c=0;while(v<=n)c++,v*=2;return c-1;}


void solve()
{
    /* 0 ? 1 ? n ? equal ? */
    int n; cin >> n;
    
    
    ll one = 0ll;
    vector<ll> power(33,0);
    ll u,v;
    while(n--){
    	cin >> u >> v;
    	if(u == 1){
    		if(v == 0) one++;
    		else power[v]++;
    	} else {
    		if(v == 0 || one >= v) {cout << "YES\n"; continue;}
    		ll maxpow = LOG2(v);
    		
    		bool ok = false;
    		
    		for(ll i = maxpow; i >= 1; i--){
    			if(power[i]){
    				ll num = binpow(2,i);
    				ll abc = v/num;
    				ll take = min(abc, power[i]);
    				v -= (take * num);
    			}
    			if(one >= v){
    				cout << "YES\n";
    				ok = true;
    				break;
    			}
    		}
    		
    		if(!ok)cout << "NO\n";
    		
    	}
    	
    }

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