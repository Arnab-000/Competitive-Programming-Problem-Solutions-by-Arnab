// Problem: D1. Magic Powder - 1
// Contest: Codeforces - Codeforces Round 350 (Div. 2)
// URL: https://codeforces.com/problemset/problem/670/D1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Catalyst71
// Key Idea: The idea is to search for maximum number of cookies that can be
// made using k magic ingredients. So we can do a binary search on k. It is
// guaranteed that, if a 5 (for example) cookie can't be made then more than 5
// cookie can't also be made. So there exist a monotonic property, with which we
// can find the maximum number of cookie that can be made.

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

bool comp(pair<int, int> p1, pair<int, int> p2) {
  return p1.second / p1.first < p2.second / p2.first;
}

bool ok(vector<pair<int, int>> vp, int k, int target) {
  for (auto i : vp) {
    int need = i.first;
    int has = i.second;
    int cookie = has / need;
    if (cookie >= target)
      continue;
    else {
      int extra = target * need - has;
      if (extra <= k) {
        k -= extra;
        continue;
      } else {
        return false;
      }
    }
  }

  return true;
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  int n, k, m;
  cin >> n >> k;
  vector<pair<int, int>> vp;
  for (int i = 0; i < n; i++) {
    cin >> m;
    vp.push_back({m, 0});
  }
  for (int i = 0; i < n; i++) {
    cin >> m;
    vp[i].second = m;
  }
  sort(vp.begin(), vp.end(), comp);
  int l = 0;
  int r = 6875;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (ok(vp, k, mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << "\n";
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