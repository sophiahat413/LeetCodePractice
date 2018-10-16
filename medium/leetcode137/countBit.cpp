class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        int i, q, res = 0;
        for(i = 0; i < nums.size(); i++){
            for(q = 31; q >= 0; q--){
                bits[q] += nums[i] & 1;
                nums[i] >>= 1;
                if(nums[i] == 0)
                    break;
            }
        }
        for(i = 0; i < bits.size(); i++){
            if(bits[i] % 3)
                res += 1 << (31-i);
        }
        return res;
    }
};
