class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(!left || !right)     return 0;
        
        int checker = left | right, mask = 1;
        while(checker != 1)
            checker >>= 1, mask <<= 1;
        
        int val = left & right, res = 0;
        
        while(mask)
        {
            if(!(mask & val) && (mask & left || mask & right))
                break;
            else if(mask & val)
                res |= mask;
            mask >>= 1;
        }
        
        return res;
    }
};