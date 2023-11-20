// Problem: D. Wooden Toy Festival
// Contest: Codeforces - Codeforces Round 878 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1840/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Author: Catalyst71
// Key Idea: The idea is to run a binary search for answer on max waiting time.
// Lets say we fix a max allocation time. Then next, we have to make sure that
// this allocated max waiting time is acheiveable. To check this, we can cout
// how many distinct choice can workers make to staisfy this maximum allocation
// time. If the number of workers is greater than 3 then, we can't pick this
// maximum. Also, we can notice that, if a time t can be allocated then any time
// greater than t can also be allocated.

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

bool ok(vector<long long> v, long long wait) {
  set<long long> dist;
  dist.insert(v[0] + wait);
  long long curr = v[0] + wait;
  for (int i = 0; i < (int)v.size(); i++) {
    if (abs(curr - v[i]) <= wait) continue;
    curr = v[i] + wait;
    dist.insert(curr);
  }
  return dist.size() <= 3;
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  int n;
  cin >> n;
  vl v(n);
  fx(v) cin >> x;
  sort(all(v));
  long long l = 0;
  long long r = v[n - 1];

  while (l + 1 < r) {
    long long mid = (l + r) / 2;
    if (ok(v, mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (ok(v, 0))
    cout << 0 << "\n";
  else
    cout << r << "\n";
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