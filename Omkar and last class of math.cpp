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
long long int gcd(long long int a , long long int b) {if (a % b == 0)return b; if (b == 0)return a; return gcd(b, a % b);}
long long int lcm(long long int a , long long int b) { return (a / gcd(a, b)) * b;}
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


// [Problem link : https://codeforces.com/problemset/problem/1372/B]

// [Key Idea: For any given input, if it is an even number then the answer will always be half. As by dividing the even number into two halves the lcm will be the half itself, because both half will be same number. LCM of any two same number is the number itself. 

// Now what about odd numbers? So for any number the number can be written as 1+(given number - 1) { for example 5 == 1 + 4 } and the lcm will be... (given number - 1) as any number is divisible by 1. So we need to minimize this. we can do it by finding out all the divisors of the odd number. If we can find any divisor then we can surely minimize the LCM as lcm(divisor of number, number-divisor) will be (number - divisor) because the (number- divisor) is itself a multiple of the divisor which makes (number - divisor) the LCM of(divisor of number, number-divisor). Lets say we don't have any divisor, in that case we always have an option to print 1 and (given number - 1). Now for divisors we only need find the smallest lcm. And that's it :) 
// ]


void solve()
{
    /* Sure ? */
    int n;
    cin >> n;
    if (n & 1) {
        int minLCM = lcm(1, n - 1);
        int first = 1, second = n - 1;
        for (int i = 2; i <= sqrt(n + 1); i++) {
            if (n % i == 0) {
                int l, r, tempLCM;
                int a = i;
                int b = n / i;
                int lcm1 = lcm(a, n - a);
                int lcm2 = lcm(b, n - b);
                if (lcm1 < lcm2) {
                    tempLCM = lcm1;
                    l = a;
                    r = n - a;
                } else {
                    tempLCM = lcm2;
                    l = b;
                    r = n - b;
                }
                if (tempLCM < minLCM) {
                    minLCM = tempLCM;
                    first = l;
                    second = r;
                }
            }
        }
        cout << first << sp << second << nn;
    } else cout << n / 2 << sp << n / 2 << nn;

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