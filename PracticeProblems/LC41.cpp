class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            unordered_map<int,int>mp;
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(nums[i]>0) mp[nums[i]]++;
            }
            long long count=1;
            while(count<2e31-1){
                if(mp[count]==0) return count;
                count++;
            }
            return -1;
        }
    };