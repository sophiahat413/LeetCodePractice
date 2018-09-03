class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int sum = nums[0], maximum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > (sum+nums[i]))
                sum = nums[i];
            else
                sum += nums[i];
            maximum = max(maximum, sum);
        }
        return maximum;
    }
};
