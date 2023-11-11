// Problem: D. Divide by three, multiply by two
// Contest: Codeforces - Codeforces Round 479 (Div. 3)
// URL: https://codeforces.com/problemset/problem/977/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Catalyst71
// Key Idea: The idea to go from one number to another. Now lets think of two
// way from a number. first way is to double it and another way is to divide the
// number by three if it is divisible by three then. Now for evey number we just
// need to go to both way if possible and check whether the number exist in
// given array. This is how we can check all possible situation and come up with
// our solution.

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

vector<long long> curr;

bool exist(long long num, vector<long long> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (v[i] == num) return true;
  }
  return false;
}

void dfs(long long n, vector<long long> v) {
  if (exist(n, v)) {
    curr.push_back(n);
    dfs(n * 2, v);
    if (n % 3 == 0) dfs(n / 3, v);
  } else
    return;
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  int n;
  cin >> n;
  vector<long long> v(n);
  fx(v) cin >> x;
  sort(all(v));
  for (int i = 0; i < (int)v.size(); i++) {
    curr.clear();
    dfs(v[i], v);
    vector<long long> temp = curr;
    sort(all(temp));
    if (temp == v) {
      fx(curr) cout << x << " ";
      return;
    }
  }
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