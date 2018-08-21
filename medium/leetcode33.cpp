class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index, flag = 0;
        int check;
        if(nums.size() % 2 == 0)
            check = nums.size()/2-1;
        else
            check = nums.size()/2;
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1){
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }
        if(nums[check] > target){
            if(nums[0] > target){
                if(nums[0] <= nums[check]){
                    for(index = check+1; index<nums.size(); index++){
                        if(nums[index] == target){
                            flag = 1;
                            break;
                        }
                    }
                }
                else{
                     for(index = 0; index<check; index++){
                        if(nums[index] == target){
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            else{
                for(index = 0; index<check; index++){
                    if(nums[index] == target){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        else if(nums[check] < target){
            if(nums[nums.size()-1] < target){
                if(nums[nums.size()-1] < nums[check]){
                    for(index = check+1; index< nums.size(); index++){
                        if(nums[index] == target){
                            flag = 1;
                            break;
                        }
                    }
                }
                else{
                    for(index = 0; index< check; index++){
                        if(nums[index] == target){
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            else{
                for(index = check+1; index < nums.size(); index++){
                    if(nums[index] == target){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        else{
            return check;
        }
        if(flag)
            return index;
        else 
            return -1;
    }
};
