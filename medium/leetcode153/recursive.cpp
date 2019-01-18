class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
      return findMin(nums, 0, nums.size()-1);
    }
private:
    int findMin(vector<int> &nums, int l, int r){
        if(l+1 >= r)
            return min(nums[l], nums[r]);
        //sorted
        if(nums[l] < nums[r])
            return nums[l];
        int mid = l + (r-l) / 2;
        return min(findMin(nums, l, mid-1), findMin(nums, mid, r));
    }
};
