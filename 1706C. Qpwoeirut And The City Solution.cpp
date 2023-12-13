// Problem: C. Qpwoeirut And The City
// Contest: Codeforces - Codeforces Round 809 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1706/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Catalyst71
// Key Idea: Check for every building, how many blocks I need if I add a
// building and how many blocks I need if I skip e building. It's main priciple
// is inclusion exclusion DP.

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

pair<ll, ll> solve(vector<ll> &v, ll index, vector<pair<ll, ll>> &dp) {
  ll n = v.size() - 1;
  if (index > n - 1) return {0, 0};
  if (index == n - 1) {
    ll temp = (max(v[index - 1], v[index + 1]) >= v[index]
                   ? (max(v[index - 1], v[index + 1]) - v[index] + 1)
                   : 0);
    return dp[index] = {1, temp};
  }

  if (dp[index].first != -1 && dp[index].second != -1) return dp[index];

  ll temp = (max(v[index - 1], v[index + 1]) >= v[index]
                 ? (max(v[index - 1], v[index + 1]) - v[index] + 1)
                 : 0);

  pair<ll, ll> gotBack = solve(v, index + 2, dp);
  pair<ll, ll> take = {1 + gotBack.first, temp + gotBack.second};
  gotBack = solve(v, index + 1, dp);
  pair<ll, ll> skip = {gotBack.first, gotBack.second};
  if (take.first != skip.first)
    dp[index] = max(take, skip);
  else
    dp[index] = min(take, skip);
  return dp[index];
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  ll n;
  cin >> n;
  vl v(n);
  vector<pair<ll, ll>> dp(n + 1, {-1, -1});
  fx(v) cin >> x;
  solve(v, 1, dp);
  cout << dp[1].second << "\n";
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
