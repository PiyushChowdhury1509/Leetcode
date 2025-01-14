/*You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.*/

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(auto it:mp){
            int freq=it.second;
            if(freq>2){
                if(freq%2==0) ans+=(freq-2);
                else ans+=(freq-1);
            }
        }
        return n-ans;
    }
};