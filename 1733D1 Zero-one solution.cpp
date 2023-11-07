// Problem: D1. Zero-One (Easy Version)
// Contest: Codeforces - Codeforces Round 821 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1733/D1
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// Author: Catalyst71
// Key Idea: It is guaranteed that y is lesser than x, for if we need more than
// two flips than we can always find that combination where we can flip the
// string using y cost only. But if there are only two such index and both are
// consequent then, we have two option. Either just swap both which will cost x,
// other is to flip with other index 2 times, which will cost 2 * y. So minimum
// of these two will be answer.
// And also if there exist odd number of inequal bits then there will always be
// such a bit which will inequal no matter how we do operation on them.

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
  long long n, x, y, flip = 0;
  string s1, s2;
  cin >> n >> x >> y >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) flip++;
  }
  if (flip & 1) {
    cout << -1 << "\n";
  } else {
    if (flip == 2) {
      for (int i = 0; i < n - 1; i++) {
        if (s1[i] != s2[i] && s1[i + 1] != s2[i + 1]) {
          cout << min(x, 2 * y) << "\n";
          return;
        }
      }
      cout << y << "\n";
    } else
      cout << (flip / 2) * y << "\n";
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