/*You are given an integer array pizzas of size n, where pizzas[i] represents the weight of the ith pizza. Every day, you eat exactly 4 pizzas. Due to your incredible metabolism, when you eat pizzas of weights W, X, Y, and Z, where W <= X <= Y <= Z, you gain the weight of only 1 pizza!

On odd-numbered days (1-indexed), you gain a weight of Z.
On even-numbered days, you gain a weight of Y.
Find the maximum total weight you can gain by eating all pizzas optimally.

Note: It is guaranteed that n is a multiple of 4, and each pizza can be eaten only once.*/

class Solution {
    public:
        long long maxWeight(vector<int>& pizzas) {
            sort(pizzas.begin(),pizzas.end());
            long long ans=0;
            int n=pizzas.size();
            int odd;
            int i=0;
            int j=n-1;
            if((n/4)%2!=0) odd=1+(n/8);
            else odd=n/8;
            while(odd--){
                ans+=(pizzas[j]);
                j--;
                i+=3;;
            }
            int even=n/8;
            j--;
            while(even--){
                ans+=(pizzas[j]);
                j-=2;
                i+=2;
            }
            return ans;
        }
    };