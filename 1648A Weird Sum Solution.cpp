// Problem: A. Weird Sum
// Contest: Codeforces - Codeforces Round 775 (Div. 1, based on Moscow Open
// Olympiad in Informatics) URL:
// https://codeforces.com/problemset/problem/1648/A Memory Limit: 256 MB Time
// Limit: 2000 ms
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

long long calculateTotal(map<int, vector<pair<int, int>>> mp) {
  long long ans = 0;
  for (auto it : mp) {
    vector<pair<int, int>> vp = it.second;
    sort(vp.begin(), vp.end());

    long long sum = 0;
    for (auto i : vp) sum += (long long)i.first;
    for (int i = 0; i < (int)vp.size(); i++) {
      sum -= (long long)vp[i].first;
      ans += sum - (vp.size() - i - 1) * vp[i].first;
    }
  }
  return ans;
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  int n, m;
  cin >> n >> m;

  int arr[n][m];
  map<int, vector<pair<int, int>>> mpx, mpy;

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> arr[r][c];
      mpx[arr[r][c]].push_back({r, c});
      mpy[arr[r][c]].push_back({c, r});
    }
  }

  cout << calculateTotal(mpx) + calculateTotal(mpy) << "\n";
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