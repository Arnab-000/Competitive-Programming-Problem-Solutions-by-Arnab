// Problem: C. Basketball Exercise
// Contest: Codeforces - Codeforces Round 574 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1195/C
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

long long dp[3][100005], n;
long long arr[3][100005];

long long yoo(long long row, long long col) {
  if (row == 2 && col == n) {
    return arr[row][col];
  } else if (row == 1 && col == n) {
    return arr[row][col];
  }

  if (dp[row][col] != -1) return dp[row][col];

  if (row == 1) {
    if (col + 1 <= n)
      dp[row][col] = max(dp[row][col], arr[row][col] + yoo(row + 1, col + 1));
    if (col + 2 <= n) {
      dp[row][col] = max(dp[row][col], arr[row][col] + yoo(row, col + 2));
      dp[row][col] = max(dp[row][col], arr[row][col] + yoo(row + 1, col + 2));
    }
  } else if (row == 2) {
    if (col + 1 <= n)
      dp[row][col] = max(dp[row][col], arr[row][col] + yoo(row - 1, col + 1));
    if (col + 2 <= n) {
      dp[row][col] = max(dp[row][col], arr[row][col] + yoo(row, col + 2));
      dp[row][col] = max(dp[row][col], arr[row][col] + yoo(row - 1, col + 2));
    }
  }

  return dp[row][col];
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }
  cout << max(yoo(1, 1), yoo(2, 1)) << "\n";
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