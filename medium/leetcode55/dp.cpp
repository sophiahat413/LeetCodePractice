class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res(n);
        res[n-1] = true;
        for(int i = n-1; i >= 0; i--){
            for(int q = 0; q <= nums[i] && i + q < n; q++){
                if(res[i+q] == true){
                    res[i] = true;
                    break;
                }
            }
        }
        return res[0];
    }
};
