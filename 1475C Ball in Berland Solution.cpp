// Problem: C. Ball in Berland
// Contest: Codeforces - Codeforces Round 697 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1475/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Catalyst71
// Key Idea : Lets first consider a couple {boy a , girl b} now this couple
// can't be paired with any other couple which has boy a in it, and any other
// couple which has girl b in it. So for any couple we need to subtract the
// number of couple with boy a in it and the number of couple with girl b in it.
// This approach will work as all pairs are distinct, so no overlapping pair can
// occur.

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
  int a, b, k, n;
  cin >> a >> b >> k;
  map<int, int> boy, girl;
  vector<pair<int, int>> couple;
  for (int i = 0; i < k; i++) {
    cin >> n;
    if (boy[n])
      boy[n]++;
    else
      boy[n] = 1;
    couple.push_back({n, 0});
  }
  for (int i = 0; i < k; i++) {
    cin >> n;
    if (girl[n])
      girl[n]++;
    else
      girl[n] = 1;
    couple[i].second = n;
  }

  if (k == 1) {
    cout << 0 << "\n";
    return;
  }

  long long ans = 0;
  for (auto i : couple) {
    ans += ((long long)k - (boy[i.first] - 1) - (girl[i.second] - 1) - 1);
  }
  cout << ans / 2 << "\n";
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