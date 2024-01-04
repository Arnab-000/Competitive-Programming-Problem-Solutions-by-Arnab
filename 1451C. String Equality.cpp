// Problem: C. String Equality
// Contest: Codeforces - Codeforces Round 685 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1451/C
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

template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename T >ostream &operator << ( ostream & os, const multiset< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}


#define dbg(args...) do {cerr << #args << " : "; ab3(args); } while(0)
void ab3 () {cerr << endl;}
template <typename T>void ab3( T a[], int n ) {for(int i = 0; i < n; ++i) cerr << a[i] << " ";cerr << endl;}
template <typename T, typename ... hello>void ab3( T arg, const hello &... rest) {cerr << arg << " ";ab3(rest...);}
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void solve()
{
    /* 0 ? 1 ? n ? equal ? */
    int n,k;
    cin >> n >> k;
    vector<int> up(30,0), down(30,0);
    string s1,s2;
    cin >> s1 >> s2;
    for(int i = 0; i < (int)s1.size(); i++){
    	up[s1[i]-'a']++;
    }
    for(int i = 0; i < (int)s2.size(); i++){
    	down[s2[i]-'a']++;
    }
    
    for(int i = 0; i < 26; i++){
    	if(up[i] && down[i]) {
    		int temp = min(up[i],down[i]);
    		up[i] -= temp;
    		down[i] -= temp;
    	}
    }
    if(down[0]) {
    	cout << "No\n";
    	return;
    }
    for(int i = 1; i < 26; i++){
    	if(!down[i]) continue;
        if (down[i] % k) {
          cout << "No\n";
          return;
        }
        for (int j = 0; j < i; j++) {
        
          if (up[j]) {
          	while(up[j] >= k && down[i] != 0){
          		down[i] -= k;
          		up[j] -= k;
          	}
          }
        }
        if(down[i]){
        	cout << "No\n";
        	return;
        }
    }
    cout << "Yes\n";
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