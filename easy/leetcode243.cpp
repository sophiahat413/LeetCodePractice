class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int dis = INT_MAX, indexA = -1, indexB = -1;
        for(int i = 0; i<words.size(); i++){
           if(words[i] == word1){
               indexA = i; 
               if(indexB != -1)
                    dis = min(indexA - indexB, dis);
            }
            else if(words[i] == word2){
                indexB = i;
                if(indexA != -1)
                     dis = min(indexB - indexA, dis);
            }
        }
        return dis;
    }
};
