class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeakElement(vector<int>& A) {
        // write your code here
        if(A.empty())
            return -1;
        int left = 0, right = A.size()-1, mid;
        while(left < right){
            mid = (left + right) / 2;
            if(A[mid] < A[mid+1])
                left = mid+1;
            else 
                right = mid;
        }
        return left;
    }
};
