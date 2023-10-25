/*

 Author : Catalyst71
 < While there is a code, there is a bug > ¯\_(ツ)_/¯

*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define FIO ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nn endl
#define sp " "
#define fx(s) for(auto &x:s)
#define EPS 1e-10
#define frs first
#define sec second
#define vl vector<ll>
#define vi vector<int>
#define dbp(x) cout << #x << " = " << x << endl
#define FRW {freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
int dx[8] = {1, -1, 0,  0, 1,  1, -1, -1};
int dy[8] = {0,  0, 1, -1, 1, -1,  1, -1};

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// o_set<int> se; *se.find_by_order(1) -> se[1]; se.order_of_key(5) -> value less than 5
//bool isSquare(ll x){ll sq=sqrt(x);return sq*sq==x;}
//long long int gcd(long long int a , long long int b){if(a%b==0)return b;if(b==0)return a;return gcd(b,a%b);}
//long long int lcm(long long int a , long long int b){ return (a / gcd(a, b)) * b;}
//int isprime(long long n){if(n==1)return 0;if(n==2||n==3)return 1;if(n % 2 == 0) return 0;for(long long i = 2; i * i <= n; i++){if(n % i == 0){return 0;}}return 1;}
//int egcd(int a,int b,int &x,int &y){if(b==0){x=1;y=0;return a;}int x1,y1;int d=egcd(b,a%b,x1,y1);x=y1;y=x1-y1*(a/b);return d;}

//////////////////////////
// Finding Kth element in set ->
// if (k >= 1 && k <= mySet.size()) {
//     auto it = mySet.begin();
//     advance(it, k - 1); // Advance the iterator to the kth element
//     cout << "The " << k << "th element is: " << *it << endl;
// } else {
//     cout << "Invalid value of k" << endl;
// }
/////////////////////////
/////////////////////////
// const int N = 3e5 + 9;
// int a[N];
// struct ST {
//   int t[4 * N];
//   static const int inf = 1e9;
//   ST() { memset(t, 0, sizeof t); }
//   void build(int n, int b, int e) {
//     if (b == e) {
//       t[n] = a[b];
//       return;
//     }
//     int mid = (b + e) >> 1, l = n << 1, r = l | 1;
//     build(1, b, mid);
//     build(r, mid + 1, e);
//     t[n] = max(t[1], t[r]); // change this
//   }

//   void upd(int n, int b, int e, int i, int x) {
//     if (b > i || e < i)
//       return;
//     if (b == e && b == i) {
//       t[n] = x; // update
//       return;
//     }
//     int mid = (b + e) >> 1, l = n << 1, r = l | 1;
//     upd(1, b, mid, i, x);
//     upd(r, mid + 1, e, i, x);
//     t[n] = max(t[l], t[r]); // change this
//   }
//   int query(int n, int b, int e, int i, int j) {
//     if (b > j || e < i)
//       return -inf; // return appropriate value
//     if (b >= i && e <= j)
//       return t[n];
//     int mid = (b + e) >> 1, l = n << 1, r = l | 1;
//     return max(query(1, b, mid, i, j),
//                query(r, mid + 1, e, i, j)); // change this
//   }
// } t;
////////////////////////


/*struct vobon
{
    int roll,age;
    string name ;
};*/



// [Problem Link : https://codeforces.com/problemset/problem/1573/B]
// [Key Idea : To find the minimum we have to consider each element
// from array. Lets say for any element in array a, to make it lexographically
// smaller the least greater element needed is a+1. As, a is an odd number
// so a+1 will always be an even number which exists in array b. 

// Now lets say we are considering any integer a[k]. to make a lexographically
// smaller array with a[k], we need to bring a[k] to first. So operation needed
// here is a[k]-1.

// Now the question is, which number can be placed at first position of array b. 
// So that, b becomes lexographically larger ? the answer is any number between
// a[k]+1 to maximum element of b. So our only choice is to pick whatever number is 
// nearest to 1 and which is greater than a[k]+1.

// We can do it using lower_bound. As it returns the first element
// which is not smaller than the value we are finding lower_bound for.
// ]

void solve()
{
    /* 0 ? 1 ? n ? equal ? */
    int n; cin >> n;
    vector<int> up(n + 1), down(n + 1);
    vector<int> maxNum(n + 1);
    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        cin >> up[i];
    }
    int currMax = -1;
    for (int i = 1; i <= n; i++) {
        cin >> down[i];
        mp[down[i]] = i;
        currMax = max(currMax, down[i]);
        maxNum[i] = currMax;
    }

    vector<int>:: iterator it;
    int ans = INT_MAX, op = 0;
    for (int i = 1; i <= n; i++) {
        int nextBig = up[i] + 1;

        it = lower_bound(maxNum.begin(), maxNum.end(), nextBig);
        int pos = it - maxNum.begin() - 1;
        pos++;
        op = pos + i - 2;
        ans = min(ans, op);

    }
    cout << ans << "\n";


}





int main()
{
    FIO
#ifndef ONLINE_JUDGE
    FRW
#endif

//auto  START = std::chrono::steady_clock::now();
    int t = 1 ;
    cin >> t ;
    while (t--)
    {
        solve();
    }
//auto  END = std::chrono::steady_clock::now();
//double MMM = double(std::chrono::duration_cast <std::chrono::nanoseconds>(END-START).count());
//cout<<"Shomoy gese : "<<MMM/1e9<<" sec"<<endl;
    return 0 ;
}