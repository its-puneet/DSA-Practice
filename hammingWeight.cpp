// counting no of 1 bits is called hammingweight

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0){
            //checking bits and number is of 32 bits
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};