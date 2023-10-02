class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> m ;
        int a=nums1.size()-1;
        int b=nums2.size()-1;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        while(i<=a && j<=b){

            if(nums1[i]==nums2[j]){
                m.push_back(nums1[i]);
                i++;
                j++;

            }else if(nums1[i]<nums2[j]){
                i++;

            }else{
                j++;
            }
        }



        
     
     m.erase(unique(m.begin(), m.end()), m.end()); 
        return m;

    }
};