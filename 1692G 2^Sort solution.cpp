// Problem: G. 2^Sort
// Contest: Codeforces - Codeforces Round 799 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1692/G
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
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 1), prefix(n + 1, 0), yo(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 2; i <= n; i++) {
    yo[i] = (v[i] * 2 > v[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + yo[i];
  }

  int ans = 0;
  for (int i = k + 1; i <= n; i++) {
    if (prefix[i] - prefix[i - k] == k) ans++;
  }
  cout << ans << "\n";
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