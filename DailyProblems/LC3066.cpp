/*You are given a 0-indexed integer array nums, and an integer k.

In one operation, you will:

Take the two smallest integers x and y in nums.
Remove x and y from nums.
Add min(x, y) * 2 + max(x, y) anywhere in the array.
Note that you can only apply the described operation if nums contains at least two elements.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.*/

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long,vector<long long>,greater<long long>>pq;
            int n=nums.size();
            long long ans=0;
            for(int i=0;i<n;i++) pq.push(nums[i]);
            while(pq.top()<k){
                long long a=pq.top();
                pq.pop();
                long long b=pq.top();
                pq.pop();
                long long c=min(a,b)*2+max(a,b);
                pq.push(c);
                ans++;
            }
            return ans;
        }
    };