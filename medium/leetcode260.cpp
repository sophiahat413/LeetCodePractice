class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXORb = 0;
        for(auto i : nums)
            aXORb ^= i;
        //find the last bit that a different from b
        int lastBit = aXORb & (-aXORb);
        int resA = 0, resB = 0;
        //group items into two groups and find the target
        for(auto i: nums){
            if(i & lastBit) resA ^= i;
            else    resB ^= i;
        }
        return vector<int>{resA, resB};
    }
};
