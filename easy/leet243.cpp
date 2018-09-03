class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int dis = INT_MAX, countA = -1, countB = -1;
        vector<int> A, B;
        for(int i = 0; i<words.size(); i++){
           if(words[i] == word1){
               A.push_back(i); 
               countA++;
               if(B.size())
                    dis = min(abs(A[countA] - B[B.size()-1]), dis);
            }
            else if(words[i] == word2){
                B.push_back(i);
                countB++;
                if(A.size())
                     dis = min(abs(B[countB] - A[A.size()-1]), dis);
            }
        }
        return dis;
    }
};
