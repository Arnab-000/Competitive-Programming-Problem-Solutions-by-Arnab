// Problem: B2. Wonderful Coloring - 2
// Contest: Codeforces - Codeforces Round 734 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1551/B2
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
    int n,k;
    cin >> n >> k;
    vi num(n+1,0), v(n);
    vector<pair<int,int>> store;
    map<pair<int,int>,int> color;
    int sum = 0;
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    	if(num[v[i]]+1 <= k) {
    		store.push_back({v[i],i});
    		num[v[i]]++;
    		sum++;
    	}
    }
    int extra = sum % k;
    sum -= extra;
    
    sort(all(store));
    for(int i = 0, c = 1, j = 0;i < (int)store.size() && j < sum; i++){
    	color[{store[i].first, store[i].second}] = c;
    	c++;
    	j++;
    	if(c == k+1) c = 1;
    }
    for(int i = 0; i < n; i++){
    	if(color[{v[i],i}]){
    		cout << color[{v[i],i}] << " ";
    	} else cout << "0 ";
    }
    cout << "\n";
    

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