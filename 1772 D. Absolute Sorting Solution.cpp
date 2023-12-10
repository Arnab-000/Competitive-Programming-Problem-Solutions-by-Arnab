// Problem: D. Absolute Sorting
// Contest: Codeforces - Codeforces Round 839 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1772/D
// Memory Limit: 512 MB
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
  vector<int> v(n);
  fx(v) cin >> x;
  int mn = 0, mx = int(1e9);
  for (int i = 1; i < n; i++) {
    int x = v[i - 1];
    int y = v[i];
    int midL = (x + y) / 2;
    int midR = (x + y + 1) / 2;
    if (x < y) mx = min(mx, midL);
    if (x > y) mn = max(mn, midR);
  }
  if (mn <= mx)
    cout << mn << endl;
  else
    cout << -1 << endl;
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