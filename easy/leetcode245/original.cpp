class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int indexA = -1, indexB = -1, dist = INT_MAX;
        if(word1 == word2){
            vector<int> pos;
            for(int i = 0; i<words.size(); i++){
                if(words[i] == word1){
                    if(!pos.empty())
                        dist = min(dist, i - pos.back());
                    pos.push_back(i);
                }
            }
            return dist;
        }
        for(int i = 0; i<words.size(); i++){
            if(words[i] == word1){
                indexA = i;
                //cout<<"A:"<<indexA<<" B: "<<indexB<<endl;
                if(indexB != -1)
                    dist = min(dist, indexA - indexB);
            }
            else if(words[i] == word2){
                indexB = i;
                //cout<<"A:"<<indexA<<" B: "<<indexB<<endl;
                if(indexA != -1)
                    dist = min(dist, indexB - indexA);
            }  
        }
         return dist;
    }
};
