/*You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.*/

class Solution {
public:
    bool areAlmostEqual(string s, string t) {
        int count=0;
        int n=s.length();
        char c='-';
        char d='-';
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                count++;
                mp[s[i]]++;
                if(c=='-') c=t[i];
                else d=t[i];
            }
        }
        if(count==0) return true;
        if(count==2){
            mp[c]--;
            mp[d]--;
            for(auto i:mp){
                if(i.second!=0) return false;
            }
            return true;
        }
        return false;
    }
};