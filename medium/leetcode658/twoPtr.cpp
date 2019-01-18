class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> findClosestElements(vector<int> &A, int k, int x) {
        // write your code here
        int n = A.size();
        int xLower = lower_bound(A.begin(), A.end(), x) - A.begin();
        int xUpper = xLower--;
        while(k--){
            if(xLower < 0 || (xUpper < n && abs(A[xUpper] - x) < abs(x - A[xLower])))
                xUpper++;
            else
                xLower--;
        }
        vector<int> res(A.begin() + xLower + 1, A.begin() + xUpper);
        return res;
    }
};
