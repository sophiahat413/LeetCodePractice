class Solution {
private:
    vector<vector<int>> result;
public:
    
    void dfs(vector<int> nums, vector<int> group){
        if(group.size() >= nums.size()){
            result.push_back(group);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 11)
                continue;
            int tmp = nums[i];
            group.push_back(nums[i]);
            nums[i] = 11;
            dfs(nums, group);
            group.pop_back();
            nums[i] = tmp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,{});
        return result;
    }
};
