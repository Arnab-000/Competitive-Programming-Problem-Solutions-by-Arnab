// Problem: C. Dominant Character
// Contest: Codeforces - Codeforces Round 754 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1605/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Catalyst71
// Key Idea: To satisfy the given conditions we only need to check the length of
// 2,3,4,7 substring. Because no other length can be made such that it satisfy
// all the coditions. an example of 7 length is abbacca. If I add any other
// charachter and satisfy the coditions then there will be always a substring
// which will be less than 7 .

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
  vector<char> s(n + 1, '0');
  vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + (s[i] - 'a' == 0 ? 1 : 0);
    b[i] = b[i - 1] + (s[i] - 'b' == 0 ? 1 : 0);
    c[i] = c[i - 1] + (s[i] - 'c' == 0 ? 1 : 0);
  }

  vector<int> length = {1, 2, 3, 6};

  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= n - length[i]; j++) {
      int end = j + length[i];
      int an = a[end] - a[j - 1];
      int bn = b[end] - b[j - 1];
      int cn = c[end] - c[j - 1];

      if (an > bn && an > cn) {
        cout << length[i] + 1 << "\n";
        return;
      }
    }
  }
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
