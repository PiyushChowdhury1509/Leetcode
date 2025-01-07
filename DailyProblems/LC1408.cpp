/*Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string*/



//bruteforce approach
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            string s=words[i];
            for(int j=0;j<n;j++){
                if(i!=j){
                    string t=words[j];
                    if(t.find(s)!=string::npos){
                        ans.push_back(s);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

//optimised approach using kmp