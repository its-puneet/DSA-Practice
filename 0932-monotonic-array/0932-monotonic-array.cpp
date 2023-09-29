class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n= nums.size();
        if(n==1)
            return true;
    
        int fcount=0, bcount=0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]<=nums[i+1])
                fcount++;
            if(nums[i]>=nums[i+1])
                bcount++;
        }
    
        if(fcount==n-1 || bcount==n-1)
            return true;
        return false;

    }
};