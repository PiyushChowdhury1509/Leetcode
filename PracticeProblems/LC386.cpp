/*Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.*/

class Solution
{
public:
    void f(int i, int n, vector<int> &ans, unordered_set<int> &st)
    {
        if (i > n)
            return;
        for (int j = i; j <= i + 9; j++)
        {
            if (st.find(j) == st.end())
            {
                if (j > n)
                    break;
                ans.push_back(j);
                st.insert(j);
                f(j * 10, n, ans, st);
            }
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        unordered_set<int> st;
        f(1, n, ans, st);
        return ans;
    }
};