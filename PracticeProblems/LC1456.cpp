class Solution {
    public:
        bool f(char ch){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
            return false;
        }
        int maxVowels(string s, int k) {
            int ans=INT_MIN;
            int sum=0;
            int n=s.length();
            for(int i=0;i<k;i++){
                if(f(s[i])) sum++;
            }
            ans=sum;
            for(int i=1;i+k-1<n;i++){
                if(f(s[i-1])) sum--;
                if(f(s[i+k-1])) sum++;
                ans=max(sum,ans);
            }
            return ans;
        }
    };