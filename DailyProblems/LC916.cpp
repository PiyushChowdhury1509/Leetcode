/*You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>mp;
        int n=words1.size();
        int m=words2.size();
        for(int i=0;i<m;i++){
            unordered_map<char,int>temp;
            int len=words2[i].length();
            string s=words2[i];
            for(int j=0;j<len;j++){
                temp[s[j]]++;
                mp[s[j]]=max(mp[s[j]],temp[s[j]]);
            }
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            string s=words1[i];
            unordered_map<char,int>um;
            int len=s.length();
            bool flag=true;
            for(int j=0;j<len;j++){
                um[s[j]]++;
            }
            for(auto it:mp){
                if(it.second>um[it.first]){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(s);
        }
        return ans;
    }
};