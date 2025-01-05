/*You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        int m=shifts.size();
        vector<int>forw(n,0),back(n,0);
        for(int i=0;i<m;i++){
            int start=shifts[i][0];
            int end=shifts[i][1]+1;
            int dir=shifts[i][2];
            if(dir){
                forw[start]++;
                if(end<n) forw[end]--;
            }
            else{
                back[start]--;
                if(end<n) back[end]++;
            }
        }
        for(int i=1;i<n;i++){
            forw[i]+=forw[i-1];
            back[i]+=back[i-1];
        }
        vector<int>changes(n);
        for(int i=0;i<n;i++) changes[i]=back[i]+forw[i];
        string ans="";
        for(int i=0;i<n;i++){
            int character=(int) s[i];
            character-=97;
            character+=changes[i];
            character=character%26;
            if(character<0) character+=26;
            if(character>=26) character-=26;
            cout<<character<<" ";
            character+=97;
            char ch=(char) character;
            ans.push_back(ch);
        }
        return ans;
    }
};