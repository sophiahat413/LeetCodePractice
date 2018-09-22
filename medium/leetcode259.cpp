class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for(int i = nums.size()-1; i > 1; i--){
            int j = 0, k = i - 1;
            while(j < k){
                if(nums[j] + nums[k] + nums[i] < target){
                    count += --k - j + 1;
                }
                else
                    j++;
            }
        }
        return count;
    }
};
