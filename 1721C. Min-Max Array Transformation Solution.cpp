// Problem: C. Min-Max Array Transformation
// Contest: Codeforces - Educational Codeforces Round 134 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1721/C
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
    int n;
    cin >> n;
    vector<int> up(n),down(n),ansup,ansdown;
    fx(up) cin >> x;
    fx(down) cin >> x;
    for(int i = 0; i < (int)up.size(); i++){
    	int num = up[i];
    	auto it = lower_bound(down.begin(),down.end(),num) - down.begin();
    	int minDiff = down[it] - num;
    	ansup.push_back(minDiff);
    }
    int currUp = up[n-1], currDown = down[n-1];
    ansdown.push_back(currDown-currUp);
    
    for(int i = (int)up.size() - 2; i >= 0; i--){
    	auto it = lower_bound(down.begin(),down.end(),up[i+1]) - down.begin();
    	if(it > i){
    		currDown = down[i];
    		int maxDiff = currDown - up[i];
    		ansdown.push_back(maxDiff);
    	} else {
    		int maxDiff = currDown - up[i];
    		ansdown.push_back(maxDiff);
    	}
    }
    
    for(int i = 0; i < n; i++){
    	cout << ansup[i] << " \n"[i+1==n];
    }
    for(int i = n - 1; i >= 0; i--){
    	cout << ansdown[i] << " \n"[i==0];
    }
    
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