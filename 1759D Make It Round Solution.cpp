// Problem: D. Make It Round
// Contest: Codeforces - Codeforces Round  834 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1759/D
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
  ll n, m;
  cin >> n >> m;
  ll n0 = n;
  int cnt2 = 0, cnt5 = 0;
  ll k = 1;
  while (n > 0 && n % 2 == 0) {
    n /= 2;
    cnt2++;
  }
  while (n > 0 && n % 5 == 0) {
    n /= 5;
    cnt5++;
  }
  while (cnt2 < cnt5 && k * 2 <= m) {
    cnt2++;
    k *= 2;
  }
  while (cnt5 < cnt2 && k * 5 <= m) {
    cnt5++;
    k *= 5;
  }
  while (k * 10 <= m) {
    k *= 10;
  }
  if (k == 1) {
    cout << n0 * m << endl;
  } else {
    k *= m / k;
    cout << n0 * k << endl;
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