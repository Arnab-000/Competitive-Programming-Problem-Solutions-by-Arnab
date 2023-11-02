// Problem: C. Column Swapping
// Contest: Codeforces - Codeforces Round 792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1684/C
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
  int n, m;
  cin >> n >> m;
  int arr[n + 1][m + 1];
  vector<int> prev;

  if (m == 1) {
    for (int i = 0; i < n; i++) {
      cin >> arr[i][0];
    }
    cout << "1 1\n";
    return;
  }
  for (int j = 0; j < m; j++) {
    cin >> arr[0][j];
    prev.push_back(arr[0][j]);
  }
  sort(all(prev));
  if (n == 1) {
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < (int)prev.size(); i++) {
      if (prev[i] != arr[0][i]) {
        cnt++;
        ans.emplace_back(i + 1);
      }
    }
    if (cnt == 0) {
      cout << "1 1\n";
      return;
    }
    if (cnt == 2) {
      for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
      }
    } else
      cout << "-1\n";
  } else {
    set<int> ans;
    bool terminate = false;
    for (int i = 1; i < n; i++) {
      int cnt = 0;
      vector<int> curr;
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];

        curr.push_back(arr[i][j]);
        if (prev[j] != arr[i - 1][j]) {
          cnt++;
          ans.insert(j + 1);
        }
      }
      if (cnt > 2) {
        terminate = true;
      }
      prev.clear();
      swap(prev, curr);
      sort(all(prev));
    }
    if (terminate) {
      cout << "-1\n";
      return;
    }

    int cnt = 0;
    for (int j = 0; j < m; j++) {
      if (prev[j] != arr[n - 1][j]) {
        cnt++;
        ans.insert(j + 1);
      }
    }
    if (cnt > 2) {
      cout << "-1\n";
      return;
    }
    if (ans.size() > 2) {
      cout << "-1\n";
      return;
    } else if (ans.size() == 2) {
      auto it = ans.begin();
      int first = *it;
      advance(it, 1);
      int second = *it;

      for (int i = 0; i < n; i++) {
        swap(arr[i][first - 1], arr[i][second - 1]);
        if (arr[i][first - 1] <= arr[i][second - 1]) continue;
        cout << "-1\n";
        return;
      }
      cout << first << " " << second << "\n";
    } else
      cout << "1 1\n";
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