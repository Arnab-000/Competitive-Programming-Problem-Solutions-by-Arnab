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
#define ff(i,start,n) for(i=start;i<=n;i++)
#define fx(s) for(auto &x:s)
#define check(i) cout << i << endl
#define EPS 1e-10
#define frs first
#define sec second
#define mp make_pair
#define vl vector<ll>
#define vi vector<int>
#define dbp cout << " = Working = " << endl;
#define aff cout <<  "YES"   << endl;
#define neg cout << "NO" <<endl;
#define inn(n) scanf("%d", &n);
#define innm(n,m) scanf("%d%d",&n,&m);
#define outnn(n) printf("%d\n",n);
#define outsn(n) printf("%d ",n);
#define R return;
#define ffin(n) for(int i=0;i<(n);i++)
#define ffjn(n) for(int j=0;j<(n);j++)
#define ffkn(n) for(int k=0;k<(n);k++)
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

// [Problem Link : https://codeforces.com/problemset/problem/1726/C]
// [Key Idea : The idea is to think in terms of stack. when ever we have a valid bracket sequence we will remove it. Lets say, we have '((' in stack and then we are getting ')' as input, so the second '(' and ')' together forms a valid bracket sequence. Whenever we are encountering a valid bracket sequence we will keep removing them. while removing we will also count the number of removal operation we are performing consequently. for each removal if the bracket sequence is nested { for example ((())) } 
//     then the remove count will be 3. so from this example we will get 2 components of brackets. {3,4}, {2,5}. Now {1,6} is also a valid component but if we add more brackets like this.. ((()))() then {1,6} and {7,8} together form a component. so we will be counting the nested brackets for each component count. And after that, finally we will add 1 to out count as all the bracket together form a component. 
//     :)
// ]



void solve()
{
    /* Sure ? */
    int n; cin >> n;
    string s; cin >> s;
    vector<char> stack; stack.push_back(s[0]);

    int cnt = 0, left = 0, right = 0, remove = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ')') {
            stack.pop_back();
            remove++;
        }
        else {
            stack.push_back(s[i]);
            if (remove >= 1) {
                cnt += remove - 1;
                remove = 0;
            }
        }
    }
    if (remove) cnt += remove - 1;
    cout << cnt + 1 << "\n";
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