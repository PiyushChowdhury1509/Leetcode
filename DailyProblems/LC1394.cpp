class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        int ans=-1;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        for(auto i:mp){
            if(i.second==i.first) ans=i.first;
        }
        return ans;
    }
};