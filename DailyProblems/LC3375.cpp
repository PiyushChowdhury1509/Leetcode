class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_map<int,int>mp;
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(nums[i]<k) return -1;
                if(nums[i]!=k) mp[nums[i]]++;
            }
            return mp.size();
        }
    };