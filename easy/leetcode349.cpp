class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // write your code here
        if(nums1.empty() || nums2.empty())
            return {};
        vector<int> inter;
        set<int> arr1;
        set<int> arr2;
        for(int i = 0; i<nums1.size(); i++){
            arr1.insert(nums1[i]);
        }
        for(int i = 0; i<nums2.size(); i++){
            if(!arr2.count(nums2[i])){
                arr2.insert(nums2[i]);
                if(arr1.count(nums2[i]))
                    inter.push_back(nums2[i]);
            }
        }
        return inter;
    }
};
