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


//[Problem Link : https://codeforces.com/problemset/problem/478/B]
//[Key Idea: To find the maximum number of pair we just need to divide the teams in such way that all team has exactly one member and only one team contains all the other memebers, in this way we can maximize the number of pair of friends. When, we are thinking about minimum number then we need to divide the members as evenly as possible so that. So, here we need to consider two different cases. If number of teams is divides the total pariticipants then we will divide them evenly. But, what if the total number of teams does not divide the number of participants? well, in that case we will divide the participants evenly at first, but then we will consider the extra participants. Number of extra participants can be found by pariticipants % team number. Our optimal solution is to add each of extra participants to one of the teams and as extra participant is the result of mod, so it is guaranteed that number of extra participants will always be smaller than number of teams. Now the question arises, if we add one extra person to a team, how many number of pairs it is gonna add to the previous result. we if we add a person, he can pair up with all the participants we distributed before to each team. So final result will be, extra participants * participants of each team + (total participants / number of team) .


void solve()
{
    /* 0 ? 1 ? n ? equal ? */
    int n; cin >> n;
    int m; cin >> m;
    long long minf;

    if (n % m == 0) {
        long long temp = n / m;
        minf = (temp * (temp - 1)) / 2;
        minf *= m;
    } else {
        int extra = n % m;
        long long temp = n / m;
        minf = (temp * (temp - 1)) / 2;
        minf *= m;
        minf += (temp * extra);
    }



    long long temp = n - (m - 1);
    cout << minf << " " << (temp * (temp - 1)) / 2 << "\n";


}





int main()
{
    FIO
#ifndef ONLINE_JUDGE
    FRW
#endif

//auto  START = std::chrono::steady_clock::now();
    int t = 1 ;
//cin >> t ;
    while (t--)
    {
        solve();
    }
//auto  END = std::chrono::steady_clock::now();
//double MMM = double(std::chrono::duration_cast <std::chrono::nanoseconds>(END-START).count());
//cout<<"Shomoy gese : "<<MMM/1e9<<" sec"<<endl;
    return 0 ;
}