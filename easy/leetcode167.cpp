class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first = 0, last = nums.size()-1;
        while(first < last){
            if((nums[first] + nums[last]) < target)
                first++;
            else if((nums[first] + nums[last]) > target)
                last--;
            else{
                vector<int> index{first+1, last+1};
		return index;
            }
        }
    }
};
