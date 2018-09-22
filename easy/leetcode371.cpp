class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while(b != 0){
            //when checking the carry, we do a & b (only if 1 1 will have carry 1)
            int carry = a & b;
            //when sum the two number, we do XOR (1 0 will get 1)
            a = a ^ b;
            //shift the carry left by 1, so that we add the right value of carry to the original sum
            b = carry << 1;
        }
        return a;
    }
};
