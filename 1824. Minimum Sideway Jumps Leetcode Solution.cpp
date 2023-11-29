class Solution {
public:
    int solve(vector<int>& obstacles, int  currlane, int currPos, vector<vector<int>>&dp){
        int n = obstacles.size()-1;

        if(currPos == n) return 0;
        if(dp[currlane][currPos] != -1) return dp[currlane][currPos];

        if(currlane != obstacles[currPos+1]){
            dp[currlane][currPos] = solve(obstacles, currlane, currPos+1, dp);
        } else {
            int ans = INT_MAX;
            for(int move = 1; move <=3 ; move++){
                if(move != currlane && obstacles[currPos] != move) {
                    ans = min(ans, 1 + solve(obstacles, move, currPos, dp));
                }
            }
            dp[currlane][currPos] = ans;
        }

        return dp[currlane][currPos];
    }
    int solveTab(vector<int>& obstacles){
        vector<vector<int>> dp(4, vector<int>(obstacles.size()));
        int n = obstacles.size()-1;
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        for(int currPos = n-1; currPos >= 0; currPos--){
            for(int currlane = 1; currlane <= 3; currlane++){
                if(currlane != obstacles[currPos+1]){
                    dp[currlane][currPos] =  dp[currlane][currPos+1];
                } else {
                    int ans = 1e9;
                    for(int move = 1; move <=3 ; move++){
                        if(move != currlane && obstacles[currPos] != move) {
                            ans = min(ans, 1 + dp[move][currPos+1]);
                        }
                    }
                    dp[currlane][currPos] = ans;
                }                
            }
        }
        return min(dp[2][0], min(dp[1][0]+1, dp[3][0]+1));
    }
    
    int OPTsolveTab(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<int> curr(4);
        vector<int> next(4,0);
        for(int currPos = n-1; currPos >= 0; currPos--){
            for(int currlane = 1; currlane <= 3; currlane++){
                if(currlane != obstacles[currPos+1]){
                    // dp[currlane][currPos] =  dp[currlane][currPos+1];
                    curr[currlane] = next[currlane];
                } else {
                    int ans = 1e9;
                    for(int move = 1; move <=3 ; move++){
                        if(move != currlane && obstacles[currPos] != move) {
                            // ans = min(ans, 1 + dp[move][currPos+1]);
                            ans = min(ans, 1 + next[move]);
                        }
                    }
                    // dp[currlane][currPos] = ans;
                    curr[currlane] = ans;
                }   
                next = curr;             
            }
        }
        return min(next[2], min(next[1]+1, next[3]+1));
    }
    


    int minSideJumps(vector<int>& obstacles) {
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(),-1));
        // return solve(obstacles,2,0,dp);
        // return solveTab(obstacles);
        return OPTsolveTab(obstacles);
    }
};