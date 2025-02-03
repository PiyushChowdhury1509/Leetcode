/*You are given an array of integers nums. Return the length of the longest 
subarray
 of nums which is either 
strictly increasing
 or 
strictly decreasing
.*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int dec=1;
        int len=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) len++;
            else {
                dec=max(dec,len);
                len=1;
            }
        }
        dec=max(dec,len);
        len=1;
        int inc=1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) len++;
            else {
                inc=max(inc,len);
                len=1;
            }
        }
        inc=max(inc,len);
        return max(dec,inc);
    }
};