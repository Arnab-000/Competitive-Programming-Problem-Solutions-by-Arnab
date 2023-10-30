// Problem: A. Meximum Array
// Contest: Codeforces - Codeforces Round 767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/A
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
  int n;
  cin >> n;
  vector<int> v(n), ans;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (cnt[v[i]])
      cnt[v[i]]++;
    else
      cnt[v[i]] = 1;
  }
  int i = 0;
  while (i < n) {
    int mex = 0;
    while (cnt[mex] > 0) mex++;
    vector<bool> taken(mex, false);
    int unique = 0;
    while (i < n) {
      if (v[i] < mex && !taken[v[i]]) {
        taken[v[i]] = true;
        unique++;
      }
      cnt[v[i]]--;
      i++;
      if (unique == mex) break;
    }
    ans.push_back(mex);
  }
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i << " ";
  cout << "\n";
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