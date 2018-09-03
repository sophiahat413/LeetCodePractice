class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int min = INT_MAX;
        char ans;
        for(int i = 0; i<letters.size(); i++){
            if(letters[i] < target){
                if(('z' - target + letters[i] - 'a') < min){
                    min = 'z' - target + letters[i] - 'a';
                    ans = letters[i];
                }
            }
            else if(letters[i] > target){
                if((letters[i] - target) <= min){
                    min = letters[i] - target;
                    ans = letters[i];
                }
            }
            else
               continue;
        }
        return ans;
    }
};
