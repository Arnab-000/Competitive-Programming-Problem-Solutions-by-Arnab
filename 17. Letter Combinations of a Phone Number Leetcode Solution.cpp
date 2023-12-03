class Solution {
private:
    vector<string> solve(string &digits, int curr, vector<string> &ans, vector<string> &word){
        int n = digits.length();
        if(curr == n - 1) {
            for(auto i : word[digits[curr]-'0']){
                string seng(1, i);
                ans.push_back(seng);
            }
            return ans;
        }

        vector<string> next = solve(digits, curr+1, ans, word);
        ans.clear();
        for(auto i : word[digits[curr]-'0']){
            for(auto j : next){
                string temp = i+j;
                ans.push_back(temp);
            }
        }
        return ans;
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() < 1) return {};
        vector<string> word = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        return solve(digits,0,ans,word);
    }
};