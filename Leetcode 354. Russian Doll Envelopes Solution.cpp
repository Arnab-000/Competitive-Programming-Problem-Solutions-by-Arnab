class Solution {
private:
// The idea is to use Longest Increasing Subsequence Logic with binary search
    int solve(vector<int>& a){
        int n = a.size();
        vector<int> ans;
        ans.push_back(a[0]);
        // Lis Logic
        for(int i = 1; i < n; i++){
            if(ans.back() < a[i]){
                ans.push_back(a[i]);
                continue;
            }
            int pos = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[pos] = a[i];
        }
        return ans.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>a, vector<int>b){
            if(a.front() == b.front()) return a.back() > b.back();
            else return a.front() < b.front();
        });
        vector<int> a;
        for(auto i:envelopes){
            a.push_back(i.back());
        }
        return solve(a);
    }
};