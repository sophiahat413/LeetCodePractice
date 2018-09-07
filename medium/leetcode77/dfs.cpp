class Solution {
private:
    vector<vector<int>> result;
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    void dfs(int n, int k, int num, vector<int> group){
        if(group.size() == k){
            result.push_back(group);
            return;
        }
        for(int i = num; i <= n; i++){
            group.push_back(i);
            dfs(n, k, i+1, group);
            group.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        // write your code here
        vector<int> group;
        dfs(n, k, 1, group);
        return result;
    }
};
