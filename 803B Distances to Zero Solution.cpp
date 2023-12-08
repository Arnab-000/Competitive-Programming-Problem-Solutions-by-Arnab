/*
 
 Author : Catalyst71
 < While there is a code, there is a bug > ¯\_(ツ)_/¯
 
*/
 
#include<bits/stdc++.h>
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
 
/*struct vobon
{
    int roll,age;
    string name ;
};*/
 
 
 
 
 
void solve()
{
    /* check FIO if not using C IO */
    int n;
    cin >> n;
    vi v(n), zeros, ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (!v[i]) zeros.pb(i);
    }
    if (zeros.size() == 1) {
        for (int i = 0 ; i < n; i++) {
            cout << abs(i - zeros[0]) << " ";
        }
    } else {
        // 0 1 2 3 4 5 6 7 8 9  . . . .
        // 1 2 3 4 0 8 9 8 7 0  . . . .  1 to first 0
        int z = zeros[0];
        for (int i = 0; i < zeros[0]; i++) {
            ans.pb(abs(i - z));
        }
        for (int i = 0; i < zeros.size() - 1; i++) {
            int left = zeros[i];
            int right = zeros[i + 1];
            int mid = left + (right - left - 1) / 2 ;
            for (int j = left; j < right; j++) {
                if (j <= mid) ans.pb(abs(j - left));
                else ans.pb(abs(j - right));
            }
        }
        /// last 0 to last
        z = zeros[zeros.size() - 1];
        for (int i = z; i < n; i++) {
            ans.pb(abs(i - z));
        }
        fx(ans) cout << x << " ";
    }
 
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