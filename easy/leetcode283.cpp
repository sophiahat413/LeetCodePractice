class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 1, tmp;
        while(right < nums.size()){
            if(nums[left] == 0){
                if(nums[right] == 0)
                    right++;
                else{
                    nums[left] = nums[right];
                    nums[right] = 0;
                    left++;
                    right++;
                }
            }
            else{
                while(nums[left] != 0){
                    left++;
                    right++;
                }
            }
                
        }   
    }
};
