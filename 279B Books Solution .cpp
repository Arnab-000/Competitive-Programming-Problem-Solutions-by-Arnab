// Problem: B. Books
// Contest: Codeforces - Codeforces Round 171 (Div. 2)
// URL: https://codeforces.com/problemset/problem/279/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Catalyst71
// Key Idea: As we only need to check the consecutive ones we can use two
// pointers to check for the range which can be potential answer. If any range
// exceeds out time limit then we will move both pointers to right otherwise we
// will only move right pointer to find the greatest length for answer.

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
  int n, t;
  cin >> n >> t;
  vector<long long> book(n + 1), psum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> book[i];
    psum[i] = psum[i - 1] + book[i];
  }
  int ans = 0;
  for (int l = 1, r = 1; r <= n;) {
    long long time = psum[r] - psum[l - 1];
    int temp = r - l + 1;
    if (time <= t)
      ans = max(ans, temp), r++;
    else
      l++, r++;
  }
  cout << ans;
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