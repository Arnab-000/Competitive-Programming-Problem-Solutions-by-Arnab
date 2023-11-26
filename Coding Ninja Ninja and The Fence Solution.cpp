#include <bits/stdc++.h> 
#define MOD 1000000007
long long add(long long i, long long j){
    return ((i%MOD)+(j%MOD))%MOD;
}
long long mul(long long i, long long j){
    return ((i%MOD)*(j%MOD))%MOD;
}

long long memo(long long n,long long k ,vector<long long>& dp)
{
    if(n == 1) {
        dp[n] = k;
        return dp[n]; 
    }
    if(n == 2){
        dp[n] = add(k, mul(k,k-1));
        return dp[n];
    }
    if(dp[n] != -1) return dp[n];

    dp[n] = add(mul(memo(n-1,k,dp),k-1) , mul(memo(n-2,k,dp), k-1));
    return dp[n];
}

long long tabl(long long n,long long k)
{
    // vector<long long> dp(n+1);
    long prev1,prev2,ans;
    // dp[1] = k;
    // dp[2] = add(k, mul(k,k-1));
    prev2 = k;
    prev1 = add(k, mul(k,k-1));
    for(int i = 3; i <= n; i++){
        // dp[i] = add(mul(dp[i-1],k-1) , mul(dp[i-2],k-1));
        ans = add(mul(prev1,k-1) , mul(prev2,k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    // return dp[n];
    return prev1;
}

int numberOfWays(int n, int k) {
    // Write your code here.
    // vector<long long> dp(n+1, -1);
    // memo((long long)n, (long long)k,dp);
    // return dp[n];
    return tabl((long long)n,(long long)k);
}
