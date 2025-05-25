class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>v(26,vector<int>(26,0));
        int ans=0;
        for(int i=0;i<n;i++){
            char a=words[i][0];
            char b=words[i][1];
            int idx1=(int)a-97;
            int idx2=(int)b-97;
            if(v[idx2][idx1]){
                ans+=4;
                v[idx2][idx1]--;
            }
            else v[idx1][idx2]++;
        }
        int maxm=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j) maxm=max(maxm,v[i][j]);
            }
        }
        ans+=(maxm*2);
        return ans;
    }
};