class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
    int s = size(nums);          // count the length of the 
    for(int i=0;i<s;i++){            //check each element in array
        for(int j=i+1;j<s;j++){            //check each other element in the array
            if(nums[i] + nums[j] == target){         //determine if these two elements sum to                   target
                return{i, j};       //return all pairs of integers
            }
        }
    }
    return {-1, -1};
}
};