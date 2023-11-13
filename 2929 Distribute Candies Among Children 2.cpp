class Solution {
public:
    long long distributeCandies(long long n, long long limit) {
        long long ans = 0;
        for(int i = 0; i <= min(n,limit); i++){
            long long rem = n - i;
            if(rem > 2*limit) continue;
            long long mx = min(limit,rem);
            rem = rem - mx;
            long long cc = mx-rem+1;
            ans += max(0LL,cc);
        }
        return ans;
    }
};