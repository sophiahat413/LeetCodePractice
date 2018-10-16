class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum % k != 0)
            return false;
        int subSum = sum / k, beginIndex = nums.size()-1;
        sort(nums.begin(), nums.end());
        if(nums[beginIndex] > subSum)
            return false;
        while(beginIndex >= 0 && nums[beginIndex] == subSum){
            beginIndex--;
            k--;
        }
        vector<int> subsets(k, 0);
        return partition(subsets, nums, beginIndex, subSum);
    }
private:
    bool partition(vector<int>& subsets, vector<int> nums, int index, int subSum){
        if(index < 0)
            return true;
        int n = nums[index];
        for(int i = 0; i < subsets.size(); i++){
            if(subsets[i] + n <= subSum){
                subsets[i] += n;
                if(partition(subsets, nums, index-1, subSum))
                    return true;
                subsets[i] -= n;
            }
        }
        return false;
    }
};
