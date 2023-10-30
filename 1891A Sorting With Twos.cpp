// Problem: A. Sorting with Twos
// Contest: Codeforces - Codeforces Round 907 (Div. 2)
// URL: https://codeforces.com/contest/1891/problem/A
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
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  if (n <= 2) {
    cout << "YES\n";
  } else {
    for (int i = 4; i <= min(4, n); i++) {
      if (v[i] < v[i - 1]) {
        cout << "NO\n";
        return;
      }
    }
    for (int i = 6; i <= min(8, n); i++) {
      if (v[i] < v[i - 1]) {
        cout << "NO\n";
        return;
      }
    }
    for (int i = 10; i <= min(16, n); i++) {
      if (v[i] < v[i - 1]) {
        cout << "NO\n";
        return;
      }
    }
    for (int i = 18; i <= min(20, n); i++) {
      if (v[i] < v[i - 1]) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
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