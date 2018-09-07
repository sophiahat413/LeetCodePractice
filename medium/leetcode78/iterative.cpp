class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
       sort(nums.begin(), nums.end());
       vector<vector<int>> result(1, vector<int>());
       for(int i = 0; i<nums.size(); i++){
           int n = result.size();
           for(int q = 0; q<n; q++){
               result.push_back(result[q]);
               result.back().push_back(nums[i]);
           }
       }
        return result;
    }
};
