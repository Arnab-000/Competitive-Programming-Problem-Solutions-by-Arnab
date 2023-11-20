// Problem: D. Game With Array
// Contest: Codeforces - Codeforces Round 643 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1355/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Catalyst71
// Key idea: Okay, lets say we are given a sum S and we need N elements for
// array, if N is greater than S/2 then, after filling the array, it will always
// sum to all numbers as there will be 1's and number which will sum up to all
// numbers from 1 to S. If N is smaller than half of S then, we always have an
// option to fill the array with 1 and at last, we put what ever left. There
// will be always a number which will not add up in this fashion.

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
  int n, s;
  cin >> n >> s;
  if (n > (s / 2)) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < n - 1; i++) {
      cout << 1 << " ";
    }
    cout << s - (n - 1) << "\n";
    cout << s - (n - 1) - 1 << "\n";
  }
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