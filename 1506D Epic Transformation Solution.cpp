// Problem: D. Epic Transformation
// Contest: Codeforces - Codeforces Round 710 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1506/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Catalyst71
// Key Idea: It is a very easy implementation problem. Our first claim is, if n is odd then minimum answer is 1 and if n is even minimum answer is 0. Now this answer can be changed if there exist such number with which, we can not pair anything. If occurence of any number is greater than other numbers than, after all operation there will be some number left which can't be paired.

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
  int n, x;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (!mp[x])
      mp[x] = 1;
    else
      mp[x]++;
  }
  int maxn = -1;
  for (auto i : mp) {
    maxn = max(maxn, i.second);
  }

  int ans = (n & 1);
  if (maxn >= (n - maxn))
    cout << maxn - (n - maxn) << "\n";
  else
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