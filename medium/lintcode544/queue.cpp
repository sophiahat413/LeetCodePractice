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
       priority_queue<int, vector<int>, greater<int>> min_heap;
       for(int i = 0; i<nums.size(); i++){
           min_heap.push(nums[i]);
           if(min_heap.size() > k)
                min_heap.pop();
       }
       while(min_heap.size()){
           result.push_back(min_heap.top());
           min_heap.pop();
       }
       reverse(result.begin(), result.end());
       return result;
    }
};
