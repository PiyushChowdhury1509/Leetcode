/*You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.*/


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>st1;
        unordered_set<int>st2;
        int n=A.size();
        vector<int>ans(n);
        int count=0;
        for(int i=0;i<n;i++){
            if(A[i]==B[i]){
                count++;
                st1.insert(A[i]);
            }
            else{
                st1.insert(A[i]);
                st2.insert(B[i]);
                if(st2.find(A[i])!=st2.end()) count++;
                if(st1.find(B[i])!=st1.end()) count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};