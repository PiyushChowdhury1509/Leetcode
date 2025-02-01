/*An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

*/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=0;
        int s=0;
        for(int i=1;i<n;i++){
            if((nums[i-1]%2)==(nums[i]%2)) s++;
            pre[i]=s;
        }
        int m=queries.size();
        vector<bool>ans(m);
        for(int i=0;i<m;i++){
            int left=queries[i][0];
            int right=queries[i][1];
            int lsum=pre[left];
            int rsum=pre[right];
            if(lsum==rsum) ans[i]=true;
            else ans[i]=false;
        }
        return ans;
    }
};