// Problem: C. No Prime Differences
// Contest: Codeforces - Codeforces Round 877 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1838/C
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

bool isprime(int n) {
  for (int i = 2; i <= sqrt(n + 1); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  int n, m;
  cin >> n >> m;
  {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i % 2 == 0)
          cout << (n / 2 + i / 2) * m + j + 1 << ' ';
        else
          cout << (i / 2) * m + j + 1 << ' ';
      }
      cout << "\n";
    }
    cout << "\n";
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