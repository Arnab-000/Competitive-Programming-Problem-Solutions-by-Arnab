// Problem: D. Add to Neighbour and Remove
// Contest: Codeforces - Codeforces Round 690 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1462/D
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
  int n;
  cin >> n;
  vector<int> v(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += (long long)v[i];
  }

  for (int i = n; i >= 1; i--) {
    bool ok = true;
    if (sum % i == 0) {
      long long target = sum / i;
      long long curr = 0;
      for (int j = 0; j < n; j++) {
        curr += v[j];
        if (curr > target) {
          ok = false;
          break;
        } else if (curr == target)
          curr = 0;
      }
      if (ok) {
        cout << n - i << "\n";
        return;
      }
    }
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