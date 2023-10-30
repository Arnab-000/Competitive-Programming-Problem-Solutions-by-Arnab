// Problem: B. Mashmokh and ACM
// Contest: Codeforces - Codeforces Round 240 (Div. 1)
// URL: https://codeforces.com/problemset/problem/414/B
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

int dp[2005][2005];
int MOD = 1000000007;

int itachi(int n, int k, int position) {
  if (k <= 0) return 1;
  if (dp[position][k] != -1) return dp[position][k];

  int ans = 0;
  for (int i = position; i <= n; i += position) {
    ans += itachi(n, k - 1, i) % MOD;
    ans %= MOD;
  }
  dp[position][k] = ans;
  return ans;
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  int n, k;
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  cout << itachi(n, k, 1) << "\n";
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