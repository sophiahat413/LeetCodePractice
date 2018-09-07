class Solution {
private:
    vector<vector<int>> result;
    
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    void dfs(vector<int> &num, vector<int> group, int sum, int cur, int target){
        if(cur >= num.size())
            return;
        if(sum + num[cur] == target){
            group.push_back(num[cur]);
            result.push_back(group);
            return;
        }
        if(sum + num[cur] > target)
            return;
        for(int i = cur; i<num.size(); i++){
            group.push_back(num[i]);
            sum += num[i];
            if(sum < target)
                dfs(num, group, sum, i+1, target);
            else if(sum == target)
                result.push_back(group);
            sum -= group[group.size()-1];
            while(num[i+1] == group[group.size()-1])
                i++;
            group.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        if(num.empty())
            return {};
        sort(num.begin(), num.end());
        vector<int> group;
        dfs(num, group, 0, 0, target);
        return result;
    }
};
