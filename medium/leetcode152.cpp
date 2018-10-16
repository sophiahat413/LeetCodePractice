class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        vector<int> pos(n, 1);
        vector<int> neg(n, 1);
        pos[0] = nums[0];
        neg[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pos[i] = max(nums[i], max(nums[i] * pos[i-1], nums[i] * neg[i-1]));
            neg[i] = min(nums[i], min(nums[i] * pos[i-1], nums[i] * neg[i-1]));
            res = max(res, pos[i]);
        }
        return res;
    }
};
