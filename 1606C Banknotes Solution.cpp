// Problem: C. Banknotes
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1606/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Catalyst71
// Key Idea: Our main idea is to minimize the amount. So best approach is to
// take more of low value note and less of high value notes. But main catch here
// is, if I take all low value notes then this amount can be replaced with a
// single high value note. For example, if I take 11, 100 burle note then amount
// is 1100 but this can be replaced with a single 1000 and a single 100 burle
// note. If this happens, then we will not have the minimum amount that we're
// trying to make. Lets ask ourselves, when we can't replace an amount? in
// previous example if I take 9, 100 burle notes then we can't replace 900 with
// a 1000 burle note. So, our main idea is to take low value notes in such a way
// that, bigger value note can't replace them. :)

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

long long pw(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  ll k;
  int n, m;
  cin >> n >> k;
  ll target = k + 1;
  vector<ll> notes;
  for (int i = 0; i < n; i++) {
    cin >> m;
    notes.pb(pw(10ll, m));
  }
  vector<ll> taken;
  ll count = 0;
  for (int i = 0; i < n - 1; i++) {
    ll mxTake = (notes[i + 1] / notes[i]) - 1;
    if (count + mxTake >= target) {
      taken.pb(target - count);
      count = target;
      break;
    } else {
      taken.pb(mxTake);
      count += mxTake;
    }
  }
  if (count < target) {
    taken.pb(target - count);
  }

  ll ans = 0;
  for (int i = 0; i < (int)taken.size(); i++) {
    ans += notes[i] * taken[i];
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