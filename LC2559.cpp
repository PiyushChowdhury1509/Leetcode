/*You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.*/

class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int m=words.size();
        int n=queries.size();
        vector<int>ans(n);
        vector<int>prefix(m+1,0);
        for(int i=0;i<m;i++){
            string s=words[i];
            char a=s[0];
            char b=s[s.length()-1];
            if(isVowel(a) && isVowel(b)) prefix[i+1]=prefix[i]+1;
            else prefix[i+1]=prefix[i];
        }
        for(int i=0;i<n;i++){
            int lidx=queries[i][0];
            int hidx=queries[i][1];
            ans[i]=prefix[hidx+1]-prefix[lidx];
        }
        return ans;
    }
};