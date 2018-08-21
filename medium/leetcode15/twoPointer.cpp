class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
        sort(numbers.begin(), numbers.end());
        vector<vector<int>> sets;
        int t, l, r;
        for(int i = 0; i<numbers.size()-2; i++){
           if((numbers[i] != numbers[i-1] && i>0) || i == 0){
               l = i+1;
               r = numbers.size()-1;
               t = -numbers[i];
               while(l<r){
                   if((numbers[l]+numbers[r]) == t){
                       vector<int> set{numbers[i], numbers[l], numbers[r]};
                       sets.push_back(set);
                       while(l<r && (numbers[l] == numbers[l+1]))
                            l++;
                       while(l<r && (numbers[r] == numbers[r-1]))
                            r--;
                       l++;
                   }
                   else if((numbers[l]+numbers[r]) > t){
                        r--;
                   }
                   else{
                        l++;
                   }
               }
           }
        }
        return sets;
    }
};
