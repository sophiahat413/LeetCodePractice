class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int start = 0, end = nums.size()-1;
        while(start < end){
            if(nums[start] < nums[end])
                return nums[start];
            int mid = (start + end) / 2;
            if(nums[mid] >= nums[start])
                start = mid+1;
            else{
                end = mid;
            }
        }
        return nums[start];
    }
};
