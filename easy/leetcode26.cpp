class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int count = 1;
        int previous = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] != previous){
                nums[count] = nums[i];
                count++;
                previous = nums[i];
            }
        }
        return count;
    }
};
