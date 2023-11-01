// Problem: B. Taxi
// Contest: Codeforces - VK Cup 2012 Qualification Round 1
// URL: https://codeforces.com/contest/158/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
  int ans = 0;
  int seat[5] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    seat[m]++;
  }
  ans += seat[4];
  ans += seat[3];
  seat[1] -= min(seat[3], seat[1]);
  if (seat[2] & 1) {
    ans += (seat[2] - 1) / 2;
    ans++;
    seat[1] -= min(2, seat[1]);
  } else
    ans += seat[2] / 2;

  if (seat[1] < 4 && seat[1])
    ans++;
  else {
    if (seat[1] % 4) {
      ans += seat[1] / 4;
      ans++;
    } else
      ans += seat[1] / 4;
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