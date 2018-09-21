class Solution {
public:
    int findMajor(vector<int>& nums, int left, int right){
        if(left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int lm = findMajor(nums, left, mid);
        int rm = findMajor(nums, mid+1, right);
        if(lm == rm)
            return lm;
        return count(nums.begin()+left, nums.begin()+right+1, lm) > count(nums.begin()+left, nums.begin()+right+1, rm) ? lm : rm;
    }
 
    int majorityElement(vector<int>& nums) {
        return findMajor(nums, 0, (int)nums.size()-1);
    }
};
