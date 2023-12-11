class Solution {
private: 
    int solve(int index, int end, vector<int>& slices, int n,vector<vector<int>>& dp){
        if(n == 0 || index > end) {
            return 0;
        }
        if(dp[index][n] != -1) return dp[index][n];
        int eat = slices[index] + solve(index+2, end, slices, n-1, dp);
        int skip = solve(index+1, end, slices, n, dp);

        return dp[index][n] = max(eat,skip);
    }

    int solveTab(vector<int>& slices){
        int k = slices.size();
        vector<vector<int>> dp1(k+2, vector<int>(k+2,0)),dp2(k+2, vector<int>(k+2,0));

        for(int index = k-2; index >= 0; index--){
            for(int n = 1; n <= k/3; n++){
                int eat = slices[index] + dp1[index+2][n-1];
                int skip = dp1[index+1][n];

                dp1[index][n] = max(eat,skip);
            }
        }
        for(int index = k-1; index >= 1; index--){
            for(int n = 1; n <= k/3; n++){
                int eat = slices[index] + dp2[index+2][n-1];
                int skip = dp2[index+1][n];

                dp2[index][n] = max(eat,skip);
            }
        }

        return max(dp1[0][k/3] , dp2[1][k/3]);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();
        // vector<vector<int>> dp1(k+2, vector<int>(k+2,-1)),dp2(k+2, vector<int>(k+2,-1));

        // int c1 = solve(0,k-2,slices, k/3, dp1);
        // int c2 = solve(1,k-1,slices, k/3, dp2);

        // return max(c1,c2);

        return solveTab(slices);
    }
};