class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeakElement(vector<int>& A) {
        // write your code here
        int n = A.size();
        return helper(A, 0, n-1);
    }
    int helper(vector<int>& A, int low, int high){
        if(low == high)
            return low;
        int mid = (low + high) / 2;
        if(A[mid] < A[mid+1])
            return helper(A, mid+1, high);
        else
            return helper(A, low, mid);
        
    }
};
