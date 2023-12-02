class Solution {
private:
    bool ok(vector<int> v1, vector<int> v2){
        return v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2];
    }
    
        int solve(vector<vector<int>>& cuboid,int prev,int pos, vector<vector<int>>&dp){
        if(pos == cuboid.size()){
            return 0;
        }
        if(dp[prev+1][pos] != -1){
            return dp[prev+1][pos];
        }
        int include = 0;
        if(prev == -1 || ok(cuboid[prev], cuboid[pos])){
            include = cuboid[pos][2] + solve(cuboid,pos,pos+1,dp);
        }
        int exclude = solve(cuboid,prev,pos+1,dp);
        return dp[prev+1][pos] = max(include,exclude);
    }



public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        for(int i = 0; i < n; i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());

        for(auto i : cuboids){
            for(auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }
        
        vector<vector<int>> dp(n+1, vector<int>(n+1 , -1));
        return solve(cuboids,-1,0,dp); 

   