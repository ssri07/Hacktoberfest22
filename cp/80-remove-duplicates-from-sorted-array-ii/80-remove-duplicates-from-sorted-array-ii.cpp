class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            nums[k++]=nums[i];
            
            if(i+1<nums.size() && nums[i]==nums[i+1])
                nums[k++]=nums[i];
            
            int j=i+1;
            
            while(j<nums.size() && nums[j]==nums[i])
                j++;
            i=j-1;
        }
        return k;
    }
};