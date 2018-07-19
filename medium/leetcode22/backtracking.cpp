//take others method as reference
class Solution {
public:
    
    void generate(int open, int close, string input, vector<string>& ans){
        if(open == 0 && close == 0){
            ans.push_back(input);
            return;
        }
        if(open)
            generate(open-1, close, input+"(", ans);
        if(open<close)
            generate(open, close-1, input+")", ans);
            
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n>0)
            generate(n, n, "", ans);
        return ans;
        
    }

};
