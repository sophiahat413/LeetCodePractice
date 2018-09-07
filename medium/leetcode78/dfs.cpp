class Solution {
private:
    vector<vector<int>> result;
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    
    void dfs(vector<int> &nums, vector<int> &group, int num){
        if(num >= nums.size())
            return;
        for(int i = num; i<nums.size(); i++){
            group.push_back(nums[i]);
            result.push_back(group);
            dfs(nums, group, i+1);
            if(nums[i+1] == group[group.size()-1])
                while(nums[i+1] == group[group.size()-1])
                    i++;
            group.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        result.push_back({});
        vector<int> group;
        dfs(nums, group, 0);
        return result;
        
    }
};
