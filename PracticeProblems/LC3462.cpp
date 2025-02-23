class Solution {
    public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
            priority_queue<pair<int,int>>pq;
            int n=grid.size();
            int m=grid[0].size();
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    pq.push({grid[i][j],i});
                }
            }
            long long ans=0;
            while(k--){
                auto ele=pq.top();
                pq.pop();
                if(limits[ele.second]>0){
                    ans+=ele.first;
                    limits[ele.second]--;
                }
                else k++;
            }
            return ans;
        }
    };