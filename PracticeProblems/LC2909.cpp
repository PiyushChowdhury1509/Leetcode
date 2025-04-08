class Solution {
    public:
        int minimumSum(vector<int>& nums) {
            int n=nums.size();
            vector<int>pre(n);
            int low=nums[0];
            pre[0]=-1;
            for(int i=1;i<n;i++){
                if(nums[i]>low){
                    pre[i]=low;
                }
                else{
                    pre[i]=-1;
                    low=nums[i];
                }
            }
            vector<int>suff(n);
            suff[n-1]=-1;
            low=nums[n-1];
            for(int i=n-2;i>=0;i--){
                if(nums[i]>low){
                    suff[i]=low;
                }
                else{
                    suff[i]=-1;
                    low=nums[i];
                }
            }
            int ans=INT_MAX;
            for(int i=1;i<n-1;i++){
                if(pre[i]!=-1 && suff[i]!=-1){
                    int sum=nums[i]+pre[i]+suff[i];
                    ans=min(ans,sum);
                }
            }
            if(ans==INT_MAX) return -1;
            return ans;
        }
    };