// Problem: E1. Unforgivable Curse (easy version)
// Contest: Codeforces - Codeforces Round 855 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1800/E1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Catalyst71
// Key Idea: Any charachter can be moved 1 time using 4 and 3 operation, So for
// any string which is greater than length 6, the answer is always YES (If no
// charachter exist which is only present in one of the string or no charachter
// missing). Now for 4 and 5 because for n <= 3 we can't do any operation. So we
// need to check for 4 and 5. for length 4 only operation we can do is swap
// (1,4). So, after swapping we just need to check if both of the strings are
// matched or not. Now for length 5, we need to check the middle one, or index
// 3, as we can't do any operation on the middle one. So if middle index is not
// same then the answer is NO otherwise if charachter count matches then answer
// is YES.

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
vector<string> v = {"NO", "YES"};

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  int n, k;
  cin >> n >> k;
  string s1, s2;
  cin >> s1 >> s2;
  if (n >= 6) {
    sort(all(s1));
    sort(all(s2));
    cout << v[s1 == s2] << "\n";
  } else if (n <= 3) {
    cout << v[s1 == s2] << "\n";
  } else if (n == 4) {
    if (s1 != s2) {
      swap(s1[0], s1[3]);
    }
    cout << v[s1 == s2] << "\n";
  } else {
    if (s1[2] == s2[2]) {
      sort(all(s1));
      sort(all(s2));
    }
    cout << v[s1 == s2] << "\n";
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