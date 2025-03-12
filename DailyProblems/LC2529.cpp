class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n=nums.size();
            int poscount=0,negcount=0;
            for(int i=0;i<n;i++){
                if(nums[i]<0) negcount++;
                else if(nums[i]>0) poscount++;
            }
            return max(negcount,poscount);
        }
    };