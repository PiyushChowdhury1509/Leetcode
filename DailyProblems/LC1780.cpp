class Solution {
    public:
        bool f(long long sum,long long i,int &n){
            if(sum==n) return true;
            if(sum>n) return false;
            if(pow(3,i)>(long long)n) return false;
            return f(sum,i+1,n) || f(sum+pow(3,i),i+1,n);
        }
        bool checkPowersOfThree(int n) {
            return f((long long)0,(long long)0,n);
        }
    };