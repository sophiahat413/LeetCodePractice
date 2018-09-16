class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size(), 0);
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int q = 0; q <= i; q++){
                sums[q] += nums[i];
                if(sums[q] == k)
                    count++;
            }
        }
        return count;
    }
};
