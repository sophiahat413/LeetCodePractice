class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, "", 0, 0, res);
        return res;
    }
private:
    void dfs(const string& num, const int target, int pos, const string& exp, long prev, long curr, vector<string>& ans){
        if(pos == num.length()){
            if(curr == target)
                ans.push_back(exp);
            return;
        }
    
        for(int l = 1; l <= num.size() - pos; l++){
            string t = num.substr(pos, l);
            if(t[0] == '0' && t.length() > 1)
                break;
            long n = std::stol(t);
            if(n > INT_MAX)
                break;
            if(pos == 0){
                dfs(num, target, l, t, n, n, ans);
                continue;
            }
            dfs(num, target, pos+l, exp + '+' + t, n, curr+n, ans);
            dfs(num, target, pos+l, exp + '-' + t, -n, curr-n, ans);
            dfs(num, target, pos+l, exp + '*' + t, prev * n, curr - prev + prev * n, ans);
        
        }
    }
};
