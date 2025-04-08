class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            unordered_map<int,int>mp;
            int n=nums.size();
            for(int i=0;i<n;i++){
                mp[nums[i]]++;
            }
            int ans=0;
            int i=0;
            while(i<n-1){
                bool flag=false;
                for(int j=i+1;j<n;j++){
                    if(mp[nums[j]]>1){
                        flag=true;
                        break;
                    }
                }
                if(!flag) break;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                if(i+1<n) mp[nums[i+1]]--;
                if(i+1<n && mp[nums[i+1]]==0) mp.erase(nums[i+1]);
                if(i+2<n) mp[nums[i+2]]--;
                if(i+2<n && mp[nums[i+2]]==0) mp.erase(nums[i+2]);
                i+=3;
                ans++;
            }
            return ans;
        }
    };