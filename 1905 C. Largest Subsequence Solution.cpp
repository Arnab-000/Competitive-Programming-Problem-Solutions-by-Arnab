// Problem: C. Largest Subsequence
// Contest: Codeforces - Codeforces Round 915 (Div. 2)
// URL: https://codeforces.com/contest/1905/problem/C#
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
  vector<vector<int>> pos(30);
  string s, sss;
  cin >> s;
  sss = s;
  sort(all(sss));
  if (sss == s) {
    cout << 0 << "\n";
    return;
  }

  for (int i = 0; i < (int)s.size(); i++) {
    pos[s[i] - 'a'].push_back(i);
  }
  string sub;
  int last = -1;
  vector<int> change;

  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < (int)pos[i].size(); j++) {
      if (pos[i][j] > last) {
        last = pos[i][j];
        change.pb(last);
        char c = 'a' + i;
        sub += c;
      }
    }
  }
  char largest = sub[0];
  reverse(all(sub));
  for (int i = 0; i < (int)change.size(); i++) {
    s[change[i]] = sub[i];
  }

  if (sss == s) {
    cout << (int)change.size() - 1 - (pos[largest - 'a'].size() - 1) << "\n";
  } else
    cout << -1 << "\n";
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