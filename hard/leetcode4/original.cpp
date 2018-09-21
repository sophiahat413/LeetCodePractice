class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int total = n1 + n2, tmp;
        int middle = total % 2 == 0 ? total / 2 - 1 : (total-1) / 2;
        int i = 0, q = 0, cur = 0, val;
        double ans = 0;
        while(i < nums1.size() && q < nums2.size()){
            if(nums1[i] >= nums2[q]){
                val = nums2[q];
                q++;
            }
            else{
                val = nums1[i];
                i++;
            }
            if(cur == middle){
                if(total % 2 == 0){
                    if(i < nums1.size() && q < nums2.size())
                        tmp = nums1[i] > nums2[q] ? nums2[q] : nums1[i];
                    else if(i < nums1.size())
                        tmp = nums1[i];
                    else
                        tmp = nums2[q];
                    return (double) (val + tmp) / 2;
                }
                return val;
            }
            cur++;
        }
        while(cur <= middle){
            while(i < nums1.size()){
                if(cur == middle){
                    if(total % 2 == 0){
                        return (double) (nums1[i] + nums1[i+1]) / 2;
                    }
                    return nums1[i];
                }
                i++;
                cur++;
            }
            while(q < nums2.size()){
                if(cur == middle){
                    if(total % 2 == 0){
                        return (double) (nums2[q] + nums2[q+1]) / 2;
                    }
                    return nums2[q];
                }
                q++;
                cur++;
            }
        }
    }
};
