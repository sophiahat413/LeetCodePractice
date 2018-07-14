class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)
            return ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int sum = 0;
        for(int i = 0; i<len - 3; i++){
            if(i == 0 || (i>0 && nums[i] != nums[i-1])){
                for(int q = i+1; q<len - 2; q++){
                    if(q == (i+1) || (q>(i+1) && nums[q] != nums[q-1])){
                        int j = q+1;
                        int k = len - 1;
                        while(j<k){
                            sum = nums[i] + nums[q] + nums[j] + nums[k];
                            if(sum == target){
                                vector<int> set;
                                set.push_back(nums[i]);
                                set.push_back(nums[q]);
                                set.push_back(nums[j]);
                                set.push_back(nums[k]);
                                ans.push_back(set);
                                while(j<k && nums[j] == nums[j+1]) j++;
                                while(j<k && nums[k] == nums[k-1]) k--;
                                j++;
                            }
                            else if(sum > target)
                                k--;
                            else{
                                j++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
