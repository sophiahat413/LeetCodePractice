class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1, i = m-1, q = n-1;
        while(q >= 0){
            nums1[index--] = i >= 0 && nums1[i] > nums2[q] ? nums1[i--] : nums2[q--];
        }
    }
};
