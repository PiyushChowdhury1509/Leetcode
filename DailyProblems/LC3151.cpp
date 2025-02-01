/*An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.*/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            int a=nums[i-1]%2;
            int b=nums[i]%2;
            if(a==b) return false;
        }
        return true;
    }
};