class Solution {
private:
    vector<vector<string>> result;
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    bool isPalindrome(string a){
        string b = a;
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[a.length()-1-i])
                return false;
        }
        return true;
    }
    void dfs(string &s, vector<string>& path, int index){
        if(index == s.length()){
            result.push_back(path);
            return;
        }
        for(int i = 1; i <= s.length(); i++){
            if((index + i) > s.length())
                break;
            if(isPalindrome(s.substr(index, i))){
                path.push_back(s.substr(index, i));
            }
            else 
                continue;
            dfs(s, path, index+i);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string &s) {
        // write your code here
        vector<string> path;
        dfs(s, path, 0);
        return result;
    }
};
