class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int count = nums.size();
        int flag = 0;
        vector<int> indices;
        for(int i = 0; i<count; i++){
            int sum;
            for(int q = 0; q<count; q++){
                if(i == q)
                    continue;
                sum = nums[i] + nums[q];
                if(sum == target){
                    indices.push_back(i);
                    indices.push_back(q);
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        return indices;
    }
};
