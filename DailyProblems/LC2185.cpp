/*You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.*/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int m=pref.size();
        int count=0;
        for(int i=0;i<n;i++){
            string s=words[i].substr(0,m);
            if(s==pref) count++;
        }
        return count;
    }
};