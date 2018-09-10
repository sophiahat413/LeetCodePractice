class Solution {
private:
    vector<string> result;
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    void dfs(string &str, string s){
        if(s.length() >= str.length()){
            result.push_back(s);
            return;
        }
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '0')
                continue;
            char tmp = str[i];
            s += str[i];
            str[i] = '0';
            dfs(str, s);
            s.pop_back();
            str[i] = tmp;
            while(str[i+1] == str[i])
                i++;
        }
    }
    vector<string> stringPermutation2(string &str) {
        // write your code here
        sort(str.begin(), str.end());
        dfs(str, "");
        return result;
    }
};
