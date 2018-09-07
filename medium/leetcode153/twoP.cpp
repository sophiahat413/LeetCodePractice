class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int left = 0, right = nums.size()-1, mid;
        while(right >= left){
            mid = (right + left) / 2;
            if(nums[left] <= nums[right])
                return nums[left];
            //rotated: middle is in the left, min in the right
            if(nums[mid] > nums[right]){
               left = mid + 1;
            }
            //rotated: middle is in the right, min in the left
            else if(nums[mid] < nums[left]){
                right = mid;
            }
            //normal: not rotated
            else{
                left++;
            }
        }
    }
};
