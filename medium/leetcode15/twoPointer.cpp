//Take others method as reference
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int sum;
        if(nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2; i++){
            if(((nums[i] != nums[i-1]) && i>0)|| i == 0){
                int j = i+1;
                int k = nums.size() - 1;
                while(j<k){
                    sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0){
                        vector<int> set;
                        set.push_back(nums[i]);
                        set.push_back(nums[j]);
                        set.push_back(nums[k]);
                        ans.push_back(set);
                        while((j < k) && (nums[j] == nums[j+1])) j++;
                        while((j < k) && (nums[k] == nums[k-1])) k--;
                        j++;
                    }
                    else if(sum > 0)
                        k--;
                    else
                        j++;
                }
            }
        }
        return ans;
    }
};
