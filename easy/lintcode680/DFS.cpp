class Solution {
private:
    vector<vector<string>> ans;
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    
    /*
    1  0 
    1,2 1
    1,2,3 2
    1,2,3,4 3
    */
    void dfs(string&s, vector<string>& path, int index){
        if(index == s.length()){
            ans.push_back(path);
            return;
        }
        for(int i = 1; i<=2; i++){
            if((index + i) > s.length())
                break;
            path.push_back(s.substr(index, i));
            dfs(s, path, index+i);
            path.pop_back();
        }
    }
    vector<vector<string>> splitString(string& s) {
        // write your code here
        vector<string> path;
        dfs(s, path, 0);
        return ans;
    }
};
