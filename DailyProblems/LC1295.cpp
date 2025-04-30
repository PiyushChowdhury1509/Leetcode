class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int n=nums.size();
            int ans=0;
            for(int i=0;i<n;i++){
                int num=nums[i];
                int count=0;
                while(num){
                    num/=10;
                    count++;
                }
                if(!(count%2)) ans++;
            }
            return ans;
        }
    };