class Solution {
private:
    vector<string> result;
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    void dfs(vector<vector<char>> num, string &digits, string s, int d){
        if(d >= digits.length()){
            result.push_back(s);   
            return;
        }
        for(int i = 0; i<num[digits[d] - '0'].size(); i++){
            s += num[digits[d]-'0'][i];
            dfs(num, digits, s, d+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string &digits) {
        // write your code here
        vector<vector<char>> num{{},{},{'a','b','c'}, {'d','e','f'}, {'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'}, {'t','u','v'},{'w','x','y','z'}};
        if(digits.empty())
            return {};
        dfs(num, digits, "", 0);
        return result;
    }
    
};
