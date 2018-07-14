//Time Limit Exceeded
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int q, count = 0, flag = 0;
        if(nums.size() < 3)
            return ans;
        for(int i = 0; i<nums.size()-2; i++){
            for(int q = i+1; q<nums.size() - 1; q++){
                for(int j = q+1; j<nums.size(); j++){
                    if((nums[i] + nums[q] + nums[j]) == 0){
                        vector<int> set;
                        set.push_back(nums[i]);
                        set.push_back(nums[q]);
                        set.push_back(nums[j]);
                        sort(set.begin(), set.end());
                        flag = 0;
                        for(int i = 0; i<ans.size(); i++){
                            if(ans[i] == set){
                                flag = 1;
                                break;
                            }
                        }
                        if(!flag)
                            ans.push_back(set);
                    }
                }
            }
        }
        return ans;
    }
};
