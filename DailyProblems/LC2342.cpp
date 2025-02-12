/*You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.*/

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            unordered_map<int,priority_queue<int>>mp;
            int n=nums.size();
            for(int i=0;i<n;i++){
                int number=nums[i];
                int sum=0;
                while(number>0){
                    int digit=number%10;
                    number/=10;
                    sum+=digit;
                }
                mp[sum].push(nums[i]);
            }
            int ans=-1;
            for(auto i:mp){
                int a=-1;
                a=i.second.top();
                i.second.pop();
                int b=-1;
                if(!i.second.empty()) b=i.second.top();
                i.second.pop();
                if(a!=-1 && b!=-1) ans=max(ans,a+b);
            }
            return ans;
        }
    };