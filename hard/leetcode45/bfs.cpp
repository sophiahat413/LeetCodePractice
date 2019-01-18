class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)    return 0;
        int step = 1, maxReach = nums[0], i = 0, k = 0;
        while(maxReach < nums.size()-1){
            step++;
            for(int j = i+1; j <= i + nums[i]; j++){
                if(j + nums[j] > maxReach){
                    k = j;
                    maxReach = j + nums[j];
                }
            }
            i = k;
        }
        return step;
    }
};
