// Problem: D. Zero Remainder Array
// Contest: Codeforces - Codeforces Round 653 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1374/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Catalyst71
// Key Idea: The idea is to find the difference that we need to fullfill. It
// must be noted that, all difference should be distinct as every time we
// perform an operation value of x increases. So we can't do more than one
// operation with a single value of x. lets say we have k = 3 and we have two
// numbers, 5 5. Both needs 1 to be 6 (which is divisible by 3). But lets say we
// have x = 1, if we add this x to first 5, then the x will increase. So we
// can't 1 to the second 5. Now we have to add 4 to second 5 to make it 9. Which
// is valid. So we just need to find all the differences that we need to cover
// and then a loop to find total operations is enough.

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
template <typename F, typename S>
ostream &operator<<(ostream &os, const pair<F, S> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename F, typename S>
ostream &operator<<(ostream &os, const map<F, S> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}

#define dbg(args...)        \
  do {                      \
    cerr << #args << " : "; \
    ab3(args);              \
  } while (0)
void ab3() { cerr << endl; }
template <typename T>
void ab3(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << " ";
  cerr << endl;
}
template <typename T, typename... hello>
void ab3(T arg, const hello &...rest) {
  cerr << arg << " ";
  ab3(rest...);
}
clock_t tStart = clock();
#define timeStamp \
  dbg("Execution Time: ", (double)(clock() - tStart) / CLOCKS_PER_SEC)

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  ull n, k;
  cin >> n >> k;
  vector<ull> v(n), diff;
  map<ull, ll> exist;
  fx(v) cin >> x;
  sort(all(v));
  for (int i = 0; i < n; i++) {
    if (v[i] % k == 0) continue;
    ull sad = 1;
    while (k * sad < v[i]) sad++;
    ull needToAdd = k * sad - v[i];
    if (exist[needToAdd]) {
      exist[needToAdd]++;
      needToAdd += (k * (exist[needToAdd] - 1));
      exist[needToAdd]++;
    } else
      exist[needToAdd] = 1;
    diff.push_back(needToAdd);
  }

  sort(all(diff));

  ull ans = 0, x = 0;
  for (int i = 0; i < diff.size(); i++) {
    ans += diff[i] - x;
    x += diff[i] - x;
    ans++;
    x++;
  }

  cout << ans << "\n";
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