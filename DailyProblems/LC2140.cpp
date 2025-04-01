class Solution {
    public:
        long long f(vector<vector<int>>&questions,int i,vector<long long>&dp){
            if(i>=questions.size()) return 0;
            if(dp[i]!=-1) return dp[i];
            long long ans=0;
            ans=max(ans,questions[i][0]+f(questions,i+1+questions[i][1],dp));
            ans=max(ans,f(questions,i+1,dp));
            return dp[i]=ans;
        }
        long long mostPoints(vector<vector<int>>& questions) {
            int n=questions.size();
            vector<long long>dp(n+5,-1);
            return f(questions,0,dp);
        }
    };