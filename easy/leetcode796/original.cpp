class Solution {
public:
    bool rotateString(string A, string B) {
        int i = 0, q = 0, start, match = 0, end, count = 0;
        if(A.length() != B.length())
            return false;
        while(q < B.length()){
            if(count == A.size())
                return false;
            if(A[i] == B[q]){
                string A_sub = A.substr(i, A.size()-i-q);
                int len = A.size()-i-q;
                string B_sub = B.substr(q, len);
                if(A_sub == B_sub){    
                    if(i == 0)
                        return true;
                    q += len;
                    i = 0;
                }
                else{
                    count++;
                    i++;
                }
            }
            else{
                count++;
                i++;
            }
        }
        return true;
    }
};
