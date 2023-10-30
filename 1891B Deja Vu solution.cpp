// Problem: B. Deja Vu
// Contest: Codeforces - Codeforces Round 907 (Div. 2)
// URL: https://codeforces.com/contest/1891/problem/B
// Memory Limit: 256 MB
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
  int n, q, num;
  vector<bool> seen(31, false);
  cin >> n >> q;
  vector<long long> v(n);
  vector<pair<long, long>> vp;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> num;
    if (!seen[num]) {
      seen[num] = true;
      vp.push_back({num, i});
    }
  }
  for (int j = 0; j < n; j++) {
    long long temp = v[j];
    int power = 0;
    while (temp % 2 == 0) {
      temp /= 2;
      power++;
    }
    for (auto i : vp) {
      if (i.first <= power) {
        long long powVal = pow(2, i.first - 1);
        v[j] += powVal;
        power = i.first - 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << " \n"[i == n - 1];
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