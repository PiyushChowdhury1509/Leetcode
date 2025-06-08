class Solution {
public:
    void f(int i,int &n,vector<int>&ans,unordered_set<int>&st){
        if(i>n) return;
        for(int j=i;j<=i+9;j++){
            if(j>n) break;
            if(st.find(j)==st.end()){
                ans.push_back(j);
                st.insert(j);
            }
            cout<<j<<" ";
            f(j*10,n,ans,st);
        }
    }
    vector<int> lexicalOrder(int n) {
        unordered_set<int>st;
        vector<int>ans;
        int i=1;
        f(i,n,ans,st);
        return ans;
    }
};