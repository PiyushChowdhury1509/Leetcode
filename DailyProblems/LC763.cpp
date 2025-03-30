class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char,int>mp;
            int n=s.length();
            for(int i=0;i<n;i++){
                mp[s[i]]++;
            }
            unordered_map<char,int>temp;
            vector<int>ans;
            for(int i=0;i<n;i++){
                temp[s[i]]++;
                int count=0;
                bool flag=true;
                for(auto i:temp){
                    if(i.second==mp[i.first]) count+=i.second;
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    temp.clear();
                    ans.push_back(count);
                }
            }
            return ans;
        }
    };