// Problem: D. Pair of Topics
// Contest: Codeforces - Codeforces Round 627 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1324/D
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
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), pos, neg;
  ll zero = 0, posn = 0;
  fx(a) cin >> x;
  fx(b) cin >> x;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll diff = a[i] - b[i];
    if (diff == 0) {
      zero++;
    } else if (diff > 0) {
      pos.emplace_back(diff);
      posn++;
    }
  }
  sort(all(pos));
  ans += (posn * (posn-1))/2;
  ans += zero * posn;
  for (int i = 0; i < n; i++) {
    ll diff = a[i] - b[i];
    if(diff < 0) {
      diff *= -1;
      ans += (pos.end() - upper_bound(pos.begin(), pos.end(), diff));
    }
    // dbp(ans);
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