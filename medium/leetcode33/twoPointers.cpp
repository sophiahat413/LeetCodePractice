class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        int left = 0, right = A.size()-1, mid;
        while(right >= left){
            mid = (right + left) / 2;
            if(target == A[mid])
                return mid;
            //rotated: middle is in the left
            if(A[mid] > A[right]){
                if(target < A[mid] && target >= A[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            //rotated: middle is in the right
            else if(A[mid] < A[left]){
                if(target > A[mid] && target <= A[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            //normal: not rotated
            else{
                if(target < A[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return -1;
    }
};
