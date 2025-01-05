/*Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.*/

class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int score=0;
        for(int i=1;i<n-1;i++) if(s[i]=='1') score++;
        int ans=score;
        for(int i=1;i<n-1;i++){
            if(s[i]=='0') score++;
            else if(s[i]=='1') score--;
            ans=max(ans,score);
        }
        if(s[0]=='0') ans++;
        if(s[n-1]=='1') ans++;
        return ans;
    }
};