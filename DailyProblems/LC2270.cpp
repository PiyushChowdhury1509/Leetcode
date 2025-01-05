/*You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long totalSum=0;
        for(int i=0;i<n;i++) totalSum+=nums[i];
        long long sum=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            totalSum-=nums[i];
            sum+=nums[i];
            if(sum>=totalSum) ans++;
        }
        return ans;
    }
};