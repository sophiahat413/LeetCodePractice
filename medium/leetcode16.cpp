class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum;
        if(nums.size() < 3){
            for(int i = 0; i<nums.size(); i++)
                sum += nums[i];
            return sum;
        }
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int min = abs(nums[0] + nums[1] + nums[2] - target);
        int dif, ans;
        for(int i = 0; i<len - 2; i++){
                int j = i+1;
                int k = len -1;
                while(j<k){
                    sum = nums[i] + nums[j] + nums[k];
                    dif = abs(sum - target);
                    if(dif <= min){
                        min = dif;
                        ans = nums[i] + nums[j] + nums[k];
                    }
                    if(sum == target)
                        return sum;
                    else if(sum > target)
                        k--;
                    else
                        j++;
                }
            
        }
        return ans;
    }
};
