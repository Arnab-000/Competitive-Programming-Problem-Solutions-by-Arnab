// Problem: Save People
// Contest: CodeChef - START106D
// URL: https://www.codechef.com/START106D/problems/FIZZBUZZ2306
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

long long tr, tc, ar, ac;
bool valid(long long row, long long col) {
  return row >= 1ll && col >= 1ll && row <= tr && col <= tc;
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  cin >> tr >> tc >> ar >> ac;

  long long maxs = -1;
  if (valid(ar + 1, ac)) {
    long long nr = ar + 1;
    long long saved = (tr - nr + 1) * tc;
    maxs = max(maxs, saved);
  }
  if (valid(ar - 1, ac)) {
    long long nr = ar - 1;
    long long saved = (nr * tc);
    maxs = max(maxs, saved);
  }
  if (valid(ar, ac + 1)) {
    long long nc = ac + 1;
    long long saved = (tc - nc + 1) * tr;
    maxs = max(maxs, saved);
  }
  if (valid(ar, ac - 1)) {
    long long nc = ac - 1;
    long long saved = nc * tr;
    maxs = max(maxs, saved);
  }
  cout << maxs << "\n";
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