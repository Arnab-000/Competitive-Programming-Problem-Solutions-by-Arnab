// Problem: B. Fortune Telling
// Contest: Codeforces - Codeforces Round 770 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1634/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Catalyst71
// Key Idea : What is the common thing between plus and xor ? even + even = even
// , even + odd = odd , odd + odd = even. Same goes for xor also, as parity bits
// will be zero is both is 1 and 0 so odd^odd = even and even^even = even. And
// for any other parity bit will be one as 1 ^ 0 / 0 ^ 1 is 1. so even^odd will
// be odd. Now lets say alice starts with odd number, and total sum of given
// array is odd also, then Alice will end up with a odd number. From starting
// with odd, he can never get the even number. So if Alice can't get it Bob will
// have it. Moreover, Bob starts with Alice + 3. So Parity changes for Bob.

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
  long long n, s, y;
  cin >> n >> s >> y;
  long long sum = 0;
  vector<long long> num(n);
  fx(num) cin >> x, sum += x;
  if ((sum + s + y) % 2 == 0) {
    cout << "Alice\n";
  } else
    cout << "Bob\n";
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