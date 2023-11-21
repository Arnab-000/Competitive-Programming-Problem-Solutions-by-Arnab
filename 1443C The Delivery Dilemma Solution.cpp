// Problem: C. The Delivery Dilemma
// Contest: Codeforces - Codeforces Round 681 (Div. 2, based on VK Cup 2019-2020
// - Final) URL: https://codeforces.com/problemset/problem/1443/C Memory Limit:
// 256 MB Time Limit: 2000 ms
// Author : Catalyst71
// Key Idea: Just look for minimum, maximum waiting time between (delivery and
// pickup). we only need to be concerned about maximum because, if we can find
// the optimal maximum delivery time, then all other times will be lesser than
// maximum and we don't need to worry about that.

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
  long long n, x;
  cin >> n;
  vector<pair<long long, long long>> vp;
  for (int i = 0; i < n; i++) {
    cin >> x;
    vp.push_back({x, 0});
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    vp[i].second = x;
  }
  sort(all(vp));
  vector<long long> up, down;
  vector<long long> suffix(n + 1, 0);
  fx(vp) {
    up.push_back(x.first);
    down.push_back(x.second);
  }
  for (int i = n - 1; i >= 0; i--) {
    suffix[i] = down[i] + suffix[i + 1];
  }
  long long ans = suffix[0];
  for (int i = 0; i < n; i++) {
    long long temp = max(up[i], suffix[i + 1]);
    ans = min(ans, temp);
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