// Problem: B. Two Out of Three
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/B
// Memory Limit: 512 MB
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
  vector<int> v(n), ans(n, -1);
  int num[105] = {0};
  set<int> s;
  fx(v) {
    cin >> x;
    num[x]++;
    s.insert(x);
  }

  if ((int)s.size() == 1) {
    cout << -1 << "\n";
    return;
  }

  int x1 = -1, x2 = -1;
  int time = 1;
  for (int i = 0; i < 105; i++) {
    if (num[i] > 1 && time == 1) {
      x1 = i;
      time++;
    } else if (num[i] > 1 && time == 2)
      x2 = i;
  }
  if (x1 == -1 || x2 == -1) {
    cout << -1 << "\n";
    return;
  }
  int t1 = 1, t2 = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] == x1 && t1 == 1) {
      ans[i] = 1;
      t1++;
    } else if (v[i] == x1 && t1 == 2) {
      ans[i] = 2;
      t1++;
    }
    if (v[i] == x2 && t2 == 1) {
      ans[i] = 1;
      t2++;
    } else if (v[i] == x2 && t2 == 2) {
      ans[i] = 3;
      t2++;
    }
  }
  for (int i = 0; i < (int)ans.size(); i++) {
    if (ans[i] == -1) ans[i] = 1;
  }
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
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