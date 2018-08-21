class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int low = 0, high = nums.size()-1,i;
        int mid = (nums.size()-1) >> 1;
        while(high >= low){
            mid = low + (high - low) / 2;
            //cout<<"mid: "<<mid<<" ";
            if(target > nums[mid]){
                low = mid+1;
                if(nums[low] != target)
                    while(low+1 < nums.size() && nums[low] == nums[low+1])
                        low++;
            }
            else if(target < nums[mid]){
                high = mid-1;
                if(nums[high] != target)
                    while(high-1 > 0 && nums[high] == nums[high-1])
                        high--;
            }
            else{
                i = mid;
                while(nums[i] == target && i >= 0)
                    i--;
                ans[0] = i+1;
                i = mid;
                while(nums[i] == target && i < nums.size())
                    i++;
                ans[1] = i-1;
                break;
            }
        }
        return ans;
    }
};
