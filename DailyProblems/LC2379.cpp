class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n=blocks.size();
            vector<int>v(n,0);
            if(blocks[0]=='W') v[0]=1;
            for(int i=1;i<n;i++){
                v[i]+=(blocks[i]=='W' ? 1 : 0) +v[i-1];
            }
            int ans=INT_MAX;
            int i=1;
            int j=k;
            ans=v[k-1];
            while(j<n){
                ans=min(v[j]-v[i-1],ans);
                i++;
                j++;
            }
            return ans;
        }
    };