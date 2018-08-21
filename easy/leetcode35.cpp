class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        while(high >= low){
            mid = low + (high - low)/2;
            if(target > nums[mid]){
                if(mid < nums.size() && nums[mid+1] > target)
                    return mid+1;
                else if(mid < nums.size() && nums[mid+1] < target)
                    low = mid+1;
                else if(mid < nums.size() && nums[mid+1] == target)
                    return mid+1;
            }
            else if(target < nums[mid]){
                if(mid>0 && nums[mid-1] < target)
                    return mid;
                else if(mid>0 && nums[mid-1] > target)
                    high = mid-1;
                else if(mid>0 && nums[mid-1] == target)
                    return mid-1;
                else
                    return 0;
            }
            else
                return mid;       
        }
        return nums.size();
    }
};
