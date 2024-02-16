// Problem: D. Bracket Coloring
// Contest: Codeforces - Educational Codeforces Round 149 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1837/D
// Memory Limit: 512 MB
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
    string s;
    cin >> s;
    int l = 0, r = 0;
    for(int i = 0; i < (int)s.size(); i++){
    	if(s[i] == '(') l++;
    	else r++;
    }
    if(l == r){
    	vector<int> v;
        vector<int> c1, c2, ans(n);

        if (s[0] == '(') {
          for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
              v.push_back(i);
            } else {
              if (v.size()) {
                c1.push_back(i);
                c1.push_back(v.back());
                v.pop_back();
              } else
                c2.push_back(i);
            }
          }
        } else {
          for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == ')') {
              v.push_back(i);
            } else {
              if (v.size()) {
                c1.push_back(i);
                c1.push_back(v.back());
                v.pop_back();
              } else
                c2.push_back(i);
            }
          }
        }
        while(v.size()){
    		c2.push_back(v.back());
    		v.pop_back();
    	}
    	int color = 1;
    	bool f1 = false, f2 = false;
    	for(int i = 0; i < c1.size(); i++){
    		ans[c1[i]] = color;
    		f1 = true;
    	}
    	if(f1) color++;
    	for(int i = 0; i < c2.size();i++){
    		ans[c2[i]] = color;
    		f2 = true;
    	}
    	cout << (f1 and f2 ? 2 : 1) << "\n";
    	for(auto i : ans) cout << i << " ";
    	cout << endl;
    } else cout << -1 << "\n";
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