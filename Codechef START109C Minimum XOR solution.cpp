// Problem: Minimum XOR
// Contest: CodeChef - START109C
// URL: https://www.codechef.com/START109C/problems/MINMXOR?tab=statement
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Catalyst71

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fx(s) for (auto &x : s)
#define EPS 1e-10
#define vl vector<ll>
#define vi vector<int>
#define dbp(x) cout << #x << " = " << x << endl
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  int n, m;
  cin >> n;
  vector<int> v(n);
  cin >> v[0];
  int ans = v[0];
  for (int k = 1; k < n; k++) {
    cin >> v[k];
    ans = (ans ^ v[k]);
  }
  int mx = 1e9;
  for (int i = 0; i < n; i++) {
    mx = min(mx, (ans ^ v[i]));
  }
  cout << min(mx,ans) << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
