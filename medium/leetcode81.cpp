class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l  = 0, r = nums.size()-1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            //rotated, mid is on the left side
            if(nums[mid] == target)
                return true;
            while(nums[l] == nums[mid] && nums[mid] == nums[r]){
                l++;
                r--;
            }
            if(nums[mid] > nums[r]){
                if(target < nums[mid] && target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            //rotated, mid on the right side
            else if(nums[mid] < nums[l]){
                if(target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            //not rotated
            else{
                if(target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};
