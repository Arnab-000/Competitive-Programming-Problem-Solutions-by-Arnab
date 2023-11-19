/*

 Author : Catalyst71
 < While there is a code, there is a bug > ¯\_(ツ)_/¯

*/

#include<bits/stdc++.h>
using namespace std;
#define Osthir ios::sync_with_stdio(0); cin.tie(0);
/*
#include<iostream>
#include<numeric>
#include<tuple>
#include<bitset>
#include<iomanip>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<math.h>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<sstream>
#include<string.h>
#include<deque>
#include<set>
*/

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define all(x) (x).begin(), (x).end()
#define sz 100005
#define nn endl
#define sp " "
#define ff(i,n) for(i=0;i<n;i++)
//long long int gcd(long long int a , long long int b){if(a%b==0)return b;if(b==0)return a;return gcd(b,a%b);}
//long long int lcm(long long int a , long long int b){ return (a / gcd(a, b)) * b;}
//int pwr(int base, int power){int ans=1;while(power--){ans*=base ;}    return ans; ;}
/* to_string */
//int isprime(long long n){if(n==1)return 0;if(n==2||n==3)return 1;if(num % 2 == 0) return 0;for(long long i = 2; i * i <= n; i++){if(num % i == 0){return 0;}}return 1;}

bool check(ll n, int d)
{
    while (n)
    {
        if (n % 10 == d)
            return true ;
        n /= 10;
    }
    return false ;
}
int main()
{
    Osthir
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, i, j, k, l, ans = 0, count, flag = 0, temp = 0  ;
    int arr[100000], c[sz] {0} ;
    string null ;
    vector<int> v ;
    cin >> t ;
    int q , d, num;
    while (t--)
    {
        int dd[30] ;
        cin >> q >> d ;
        for (i = 1, j = 0; i <= 10; i++)
        {
            dd[j] = (d * i);
            j++ ;
        }
        flag = 0;
        ff(i, q)
        {
            flag = 0;
            cin >> num ;
            temp = num % 10 ;
            //cout << temp << nn;
            ff(j, 10)
            {
                //cout << dd[j]%10 << nn ;
                if (check(num, d) || num % d == 0 || num>=d*10)
                    flag = 1;
                else if (dd[j] % 10 == temp && dd[j] <= num)
                {
                    //cout << dd[j] << nn ;
                    flag = 1 ;
                    break ;
                }
            }
            cout << (flag == 1 ? "YES" : "NO") << nn ;
        }
    }


    return 0;
}



 