class Solution {
    public:
        int trap(vector<int>& height) {
            int n=height.size();
            vector<int>left(n);
            int lmax=-1;
            for(int i=0;i<n;i++){
                if(height[i]<lmax) left[i]=lmax;
                else left[i]=-1;
                lmax=max(height[i],lmax);
            }
            int rmax=-1;
            vector<int>right(n);
            for(int i=n-1;i>=0;i--){
                if(height[i]<rmax) right[i]=rmax;
                else right[i]=-1;
                rmax=max(rmax,height[i]);
            }
            int ans=0;
            for(int i=0;i<n;i++){
                if(height[i]<left[i] && height[i]<right[i]) ans+=min(left[i],right[i])-height[i];
            }
            return ans;
        }
    };