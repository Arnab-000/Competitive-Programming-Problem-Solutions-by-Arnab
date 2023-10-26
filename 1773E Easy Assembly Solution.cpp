// Problem: E. Easy Assembly
// Contest: Codeforces - 2022-2023 ICPC, NERC, Northern Eurasia Onsite (Unrated,
// Online Mirror, ICPC Rules, Teams Preferred) URL:
// https://codeforces.com/problemset/problem/1773/E Memory Limit: 1024 MB Time
// Limit: 3000 ms
// Author: Catalyst71
// [Key Idea : Lets start with a question, when we must need to perform a split
// operation ? if number is decresing then we must need to perfom a split
// operation as we need to make the towers non-decreasing. So if we split
// whenever we encounter a value which is less than previous, all the split will
// be sorted in order. for example : 1 2 5 3 7, if we split it on decreasing
// point then we have two towers 1 2 5 and 3 7 and both are sorted. Now here is
// a catch, even if we have all the sorted part we still can't guarantee that we
// don't need any more splits. just look at the example above, 1 2 5 and 3 7. we
// need to split again to make it proper non-decreasing. So we need to split
// again, 1 2, 5, 3, 7 . Now we can perform merge operation to combine. So the
// real problem is how we can understand if we need to split again or not. Here
// we need an observation. Key Observation is, we need to split again if there
// exists any number which is in the block l ... to r but not in l...r block.
// Lke our example above. 3 exists in between 2, 7 but it is not present in
// tower 1 2 7. So we need to split again. By this idea, we need to check
// everytime if anything between range l and r is present in the block l..r or
// not. If not, then we need to perform split operation.]

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

map<long long, long long> mp;
vector<vector<long long>> v(10005);

bool ok(long long l, long long r) {
  auto high = mp.upper_bound(l);
  return high->first == r;
}

void solve() {
  /* 0 ? 1 ? n ? equal ? */
  long long n;
  cin >> n;
  long long k;

  for (int i = 0; i < n; i++) {
    cin >> k;
    long long num;
    for (int j = 0; j < k; j++) {
      cin >> num;
      v[i].push_back(num);
      mp[num] = num;
    }
  }

  long long split = 0;
  long long tower = n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)v[i].size() - 1; j++) {
      long long l = v[i][j];
      long long r = v[i][j + 1];
      if (l < r) {
        if (!ok(l, r)) {
          split++;
          tower++;
        }
      } else {
        split++;
        tower++;
      }
    }
  }
  cout << split << " " << tower - 1 << "\n";
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