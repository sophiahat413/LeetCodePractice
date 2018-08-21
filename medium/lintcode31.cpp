class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if(nums.empty())
            return 0;
        int j = -1;
        for(int i = 0; i<=nums.size()-1; i++){
            if(nums[i] < k){
                j++;
                swap(&nums[j], &nums[i]);
            }
        }
        return j+1;
    }
};
