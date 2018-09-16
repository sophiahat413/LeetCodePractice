class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        map<int, int> prefixSum;
        vector<int> result;
        prefixSum[0] = -1; //the subarray starts with index 0;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            if(prefixSum.find(sum) != prefixSum.end()){
                result.push_back(prefixSum[sum]+1);
                result.push_back(i);
                return result;
            }
            prefixSum[sum] = i;
        }
        return result;
    }
};
