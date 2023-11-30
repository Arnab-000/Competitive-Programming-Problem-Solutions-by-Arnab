class Solution {
public:
    int solve(vector<int>& satisfaction, int currPos, int time, vector<vector<int>>& dp){
        int n = satisfaction.size();
        if(currPos == n) return 0;

        if(dp[currPos][time] != -1) return dp[currPos][time];

        int include = time*satisfaction[currPos] +solve(satisfaction, currPos+1, time+1, dp);
        int exclude = solve(satisfaction, currPos+1, time, dp);
        dp[currPos][time] = max(include, exclude);

        return dp[currPos][time];
    }

    int solveTab(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));

        for(int currPos = n-1; currPos >= 0; currPos--){
            for(int time = currPos; time >= 0; time--){
                int include = (time + 1)*satisfaction[currPos] + dp[currPos+1][time+1];
                int exclude = dp[currPos+1][time];
                dp[currPos][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());

        // int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        // return solve(satisfaction,0,1,dp);
        return solveTab(satisfaction);
    }
};