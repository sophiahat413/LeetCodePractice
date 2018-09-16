class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // write your code here
        set<int> s(nums1.begin(), nums1.end());
        vector<int> out;
        for (int x : nums2)
            if (s.erase(x))
                out.push_back(x);
        return out;
    }
};
