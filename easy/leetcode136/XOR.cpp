class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int aXORb = 0;
        for(auto i : nums){
            aXORb ^= i;
        }
        return aXORb;
    }
};
