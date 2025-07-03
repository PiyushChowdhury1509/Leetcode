class Solution {
public:
    string f(string s){
        string t="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            ch=(ch-'a'+1)%26+'a';
            t.push_back(ch);
        }
        return t;
    }
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<k){
            string t=f(s);
            s+=t;
        }
        return s[k-1];
    }
};