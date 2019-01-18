class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest = 0;
        for(int i = 0; i < nums.size(); i++){
            if(farest < i)
                return false;
            farest = max(i + nums[i], farest);
        }
        return true;
    }
};
