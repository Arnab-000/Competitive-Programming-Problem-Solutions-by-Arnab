class Solution {
public:
    int solve(vector<int>& v,int i,int j, vector<vector<int>>& dp){
        if((j-i) == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1; k < j; k++){
            ans = min(ans, v[i]*v[j]*v[k]+solve(v,i,k,dp)+solve(v,k,j,dp));
            dp[i][j] = ans;
        }
        return dp[i][j];
    }

    int solveTab(vector<int>& v){
        vector<vector<int>> dp(v.size(), vector<int>(v.size(),0));
        for(int i = (int)v.size()-1; i >= 0; i--){
            for(int j = i+2; j < (int)v.size(); j++){
                int ans = INT_MAX;
                for(int k = i+1; k < j; k++){
                    ans = min(ans, v[i]*v[j]*v[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][v.size()-1];
    }

    int minScoreTriangulation(vector<int>& values) {
        // vector<vector<int>> dp(values.size(), vector<int>(values.size(),-1));
        // return solve(values, 0, values.size()-1, dp);
        return solveTab(values);
    }
};