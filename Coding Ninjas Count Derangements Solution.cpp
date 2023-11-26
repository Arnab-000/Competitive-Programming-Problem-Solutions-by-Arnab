#include<bits/stdc++.h>
#define MOD 1000000007


long long int solve(int n, vector<long long int>&dp)
{
    if(n==1) {dp[n]=0; return 0;}
    if(n==2) {dp[n]=1; return 1;}

    if(dp[n] != -1) return dp[n];

    dp[n] = (((n-1)%MOD) * ((solve(n-1,dp)%MOD) + (solve(n-2,dp)%MOD) % MOD))%MOD;
    return dp[n];
}

long long int tabl(int n)
{
    // vector<long long int> dp(n+1,0);
    // dp[1] = 0;
    long long prev2 = 0;
    // dp[2] = 1;
    long long prev1 = 1;
    long long ans;
    for(long long i = 3; i <= n; i++){
        // long long first = dp[i-1] % MOD;
        long long first = prev1 % MOD;
        // long long second = dp[i-2] % MOD;
        long long second = prev2 % MOD;
        // dp[i] = ((i-1)%MOD * (first+second)%MOD)%MOD; 
        ans = ((i-1)%MOD * (first+second)%MOD)%MOD; 
        prev2 = prev1;
        prev1 = ans;
    }
    // return dp[n];
    return prev1;
}




long long int countDerangements(int n) {
    // Write your code here.
    // vector<long long int> dp(n+1,-1);
    // solve(n,dp);
    // return dp[n];
    return tabl(n);
}