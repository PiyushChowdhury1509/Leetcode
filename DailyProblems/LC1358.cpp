class Solution {
    public:
        int numberOfSubstrings(string s) {
            unordered_map<char,int>mp;
            int i=0;
            int j=0;
            int ans=0;
            while(j<s.length()){
                if(mp.size()<3){
                    mp[s[j]]++;
                    j++;
                }
                while(mp.size()==3){
                    ans+=(s.length()-j+1);
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
            }
            return ans;
        }
    };