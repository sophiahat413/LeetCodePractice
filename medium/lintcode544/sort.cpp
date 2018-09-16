class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // write your code here
        vector<int> result;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = size-1; i>= size-k; i--){
            //cout<<nums[i]<<endl;
            result.push_back(nums[i]);
        }
        return result;
    }
};
