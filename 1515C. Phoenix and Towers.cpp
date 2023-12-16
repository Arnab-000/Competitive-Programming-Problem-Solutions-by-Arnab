// Problem: C. Phoenix and Towers
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/problemset/problem/1515/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Catalyst71
// Key Idea: One important observation is, no given h is greater than x. So, we
// can always rearrange the blocks in such way that no difference is greater
// than x. It means, the answer can never be "NO". Now as we are sure that,
// there always exist an answer we can just add a block in the lowest height
// tower.

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
  int n, m, k, h;
  cin >> n >> m >> k;
  cout << "YES\n";
  set<pair<int, int>> s;
  for (int i = 0; i < m; i++) {
    s.insert({0, i});
  }
  for (int i = 0; i < n; i++) {
    cin >> h;
    pair<int, int> p = *s.begin();
    cout << p.second + 1 << " \n"[i == n - 1];
    s.erase(p);
    s.insert({p.first + h, p.second});
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