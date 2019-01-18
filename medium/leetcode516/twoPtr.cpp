class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())
            return 0;
        int n = s.size();
        vector<vector<int>> longest(n, vector<int>(n, 0));
        for(int len = 1; len <= n; len++){
            for(int lhs = 0; lhs + len <= s.size(); lhs++){
                int rhs = lhs + len - 1;
                if(lhs == rhs){
                    longest[lhs][rhs] = 1;
                }
                else if(lhs + 1 == rhs){
                    longest[lhs][rhs] = s[lhs] == s[rhs] ? 2 : 1;
                }
                else{
                    int add = s[lhs] == s[rhs] ? 2 : 0;
                    longest[lhs][rhs] = max(max(longest[lhs][rhs-1], longest[lhs+1][rhs]),longest[lhs+1][rhs-1]+add);
                }
            }
        }
        return longest[0].back();
    }
};
