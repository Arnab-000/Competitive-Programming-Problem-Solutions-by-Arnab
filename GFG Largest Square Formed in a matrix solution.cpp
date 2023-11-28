//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int solve(vector<vector<int>> &mat, int r, int c, int &maxAns){
    //     if(r >= mat.size() || c >= mat[0].size()) return 0;
        
    //     int right = solve(mat, r, c+1, maxAns);
    //     int diagonal = solve(mat, r+1, c+1, maxAns);
    //     int down = solve(mat, r+1, c , maxAns);
        
    //     if(mat[r][c] == 1){
    //         int ans = 1 + min({right, diagonal, down});
    //         maxAns = max(maxAns, ans);
    //         return ans;
    //     } else return 0;
        
    // }
    int solve(vector<vector<int>> &mat, int r, int c, int &maxAns, vector<vector<int>> &dp){
        if(r >= mat.size() || c >= mat[0].size()) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        
        int right = solve(mat, r, c+1, maxAns, dp);
        int diagonal = solve(mat, r+1, c+1, maxAns, dp);
        int down = solve(mat, r+1, c , maxAns, dp);
        
        if(mat[r][c] == 1){
            int ans = 1 + min({right, diagonal, down});
            maxAns = max(maxAns, ans);
            dp[r][c] = ans;
        } else dp[r][c] = 0;
        return dp[r][c];
    }
    
    void tabl(vector<vector<int>> &mat, int &maxAns){
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        
        for(int i = row-1; i >=0 ; i--){
            for(int j=col-1; j >= 0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
        
                if(mat[i][j] == 1){
                    int ans = 1 + min({right, diagonal, down});
                    maxAns = max(maxAns, ans);
                    dp[i][j] = ans;
                } else dp[i][j] = 0;
            }
        }
    }
    void Optimized_tabl(vector<vector<int>> &mat, int &maxAns){
        int row = mat.size();
        int col = mat[0].size();
        // vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        vector<int> currRow(col+1);
        vector<int> nextRow(col+1);
        
        for(int i = row-1; i >=0 ; i--){
            for(int j=col-1; j >= 0; j--){
                // int right = dp[i][j+1];
                int right = currRow[j+1];
                // int diagonal = dp[i+1][j+1];
                int diagonal = nextRow[j+1];
                // int down = dp[i+1][j];
                int down = nextRow[j];
        
                if(mat[i][j] == 1){
                    int ans = 1 + min({right, diagonal, down});
                    maxAns = max(maxAns, ans);
                    currRow[j] = ans;
                } else currRow[j] = 0;
            }
            nextRow = currRow;
        }
    }
    
    


    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxAns = 0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // solve(mat,0,0, maxAns,dp);
        // tabl(mat,maxAns);
        Optimized_tabl(mat,maxAns);
        return maxAns;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends