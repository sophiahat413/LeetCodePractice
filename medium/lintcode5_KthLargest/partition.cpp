class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    void swap(int* a, int* b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    int partition(vector<int> &nums, int left, int right, int n){
        int i = left-1, pivot = nums[right];
        for(int j = left; j<= right; j++){
            if(nums[j] < pivot){
                i++;
                swap(&nums[i], &nums[j]);
            }
        }
        swap(&nums[i+1], &nums[right]);
        if((i+1) == (nums.size() - n))
            return nums[i+1];
        else if((i+1) < (nums.size() - n + 1))
            partition(nums, i+2, right, n);
        else
            partition(nums, left, i, n);
    }
    int kthLargestElement(int n, vector<int> &nums) {
        partition(nums, 0, nums.size()-1, n);
    }
};
