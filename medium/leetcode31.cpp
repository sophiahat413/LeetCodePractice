class Solution {
public:
    void reverse(vector<int>& nums, int index){
        vector<int> temp;
        int i, q = 0;
        for(i = nums.size()-1; i >= index; i--)
            temp.push_back(nums[i]);
        for(i = index; i<nums.size(); i++){
            nums[i] = temp[q];
            q++;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int reg, min = 10, flag = 0, temp, k, i, q, j, s ;
        for(i = nums.size()-1; i >= 0; i--){
            for(q = nums.size()-1; q > i; q--){
                if(i == q)
                    continue;
                if(nums[q] > nums[i]){
                    if(flag == 0){
                        min = nums[q];
                        reg = q;
                        flag = 1;
                    }
                    else if (nums[q] < min){
                        min = nums[q];
                        reg = q;
                    }
                }
            }
            if(flag){
                temp = nums[i];
                nums[i] = nums[reg];
                nums[reg] = temp;
                reverse(nums, i+1);
                break;
            }
        }
        i++;
        if(i == 0){
            if(flag == 0)
               reverse(nums, 0);
        }
    }
};
