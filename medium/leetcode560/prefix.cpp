class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefix_sum;
        int sum = 0, count = 0;
        prefix_sum[0] ++; //take into account those subarray begins with index 0
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            count += prefix_sum[sum - k];
            prefix_sum[sum]++;
        }
        return count;
    }
};
