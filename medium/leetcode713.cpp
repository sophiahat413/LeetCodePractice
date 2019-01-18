class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int prod = 1, left = 0, res = 0, i;
        for(i = 0; i < nums.size(); i++){
            prod *= nums[i];
            while(prod >= k){
                prod /= nums[left];
                left++;
            }
            res += i - left + 1;
        }
        return res;
    }
};
