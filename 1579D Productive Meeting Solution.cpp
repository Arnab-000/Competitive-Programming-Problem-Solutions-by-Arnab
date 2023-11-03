// Problem: D. Productive Meeting
// Contest: Codeforces - Codeforces Round 744 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1579/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
  priority_queue<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    if (m) q.push({m, i});
  }
  vector<pair<int, int>> ans;
  while (q.size() >= 2) {
    auto x = q.top();
    q.pop();
    auto y = q.top();
    q.pop();
    ans.push_back({x.second, y.second});
    x.first--;
    y.first--;
    if (x.first) q.push(x);
    if (y.first) q.push(y);
  }
  
  cout << ans.size() << "\n";
  for(int i = 0; i < (int)ans.size(); i++){
  	cout << ans[i].first << " " << ans[i].second << "\n";
  }
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