// Problem: E. Accidental Victory
// Contest: Codeforces - Codeforces Round 702 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1490/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Catalyst71
// Key Idea: The idea is to check every player's winning condition. Lets say a
// player will win if it gathers more token than the player with more token
// initially. So we can just sort the array, find the that player for which,
// even if he collects all the token from his left side player, the total token
// that he collects is still lower than the player to his right ( Obviously, is
// a sorted array ). If we find this player, than we can simply say no more
// player will be winner as to his left, number of tokens is going to be smaller
// than him. So total - his position is the answer.

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
  cin >> n;
  vector<pair<long long, long long>> input, ans;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    input.push_back({m, i});
  }
  sort(input.begin(), input.end());
  vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < (int)input.size(); i++) {
    prefix[i + 1] = prefix[i] + input[i].first;
  }

  ans.push_back(input[n - 1]);
  for (int i = n - 1; i >= 1; i--) {
    long long curr = prefix[i];
    long long right = input[i].first;
    if (curr >= right) {
      ans.push_back(input[i - 1]);
    } else
      break;
  }

  sort(ans.begin(), ans.end(),
       [](pair<long long, long long> a, pair<long long, long long> b) {
         return a.second < b.second;
       });

  cout << ans.size() << "\n";
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i].second << " \n"[i + 1 == (int)ans.size()];
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