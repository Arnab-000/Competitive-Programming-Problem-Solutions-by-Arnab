// Problem: C. Rotation Matching
// Contest: Codeforces - Codeforces Round 648 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1365/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Catalyst71
// Key Idea: Any way I rotate any array that does not really matter. So lets
// assume we will always rotate b array in always in clock wise direction. Now,
// which elements can be placed into same position? we can only place those
// elements in same place after rotating , which elements have same difference
// in position before rotating. Now we need to calculate how much difference are
// there in positions of elements in both array. Because to place them in same
// position we need to perform rotation equal to the difference.

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
  vi posa(n + 1), posb(n + 1), posdiff(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> m;
    posa[m] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> m;
    posb[m] = i;
  }
  for (int i = 1; i <= n; i++) {
    int diff = posb[i] - posa[i];
    if (diff > 0) {
      diff = n - posb[i] + posa[i];
    } else
      diff *= -1;
    posdiff[diff]++;
  }

  int ans = -1;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, posdiff[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t ;
  while (t--) {
    solve();
  }

  return 0;
}