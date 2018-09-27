class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-2; i >= 0; i--){
            for(int q = nums.size()-1; q > i; q--){
                if(nums[q] > nums[i]){
                    int tmp = nums[i];
                    nums[i] = nums[q];
                    nums[q] = tmp;
                    reverse(nums.begin() + i +1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
