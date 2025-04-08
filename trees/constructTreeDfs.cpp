#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <cstring>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define F first
#define S second
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m - b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
ll mod_exp(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

class TreeNode{
    public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        value=x;
        left=nullptr;
        right=nullptr;
    }

};


TreeNode *f(vector<int>&nums,int i){
    if(i>=nums.size() || nums[i]==-1) return nullptr;
    TreeNode*ans;
    ans=new TreeNode(nums[i]);
    ans->left=f(nums,2*i+1);
    ans->right=f(nums,2*i+2);
    return ans;
}

void print(TreeNode*a){
    if(!a) return;
    cout<<a->value<<" ";
    print(a->left);
    print(a->right);
}

vector<vector<int>> fun(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*>q;
    q.push(root);
    q.push(nullptr);
    vector<vector<int>>ans;
    while(!q.empty()){
        vector<int>v;
        while(!q.empty() && q.front()!=nullptr){
            TreeNode*t=q.front();
            q.pop();
            if(t){
                v.push_back(t->value);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        q.pop();
        ans.push_back(v);
        if(!q.empty()) q.push(nullptr);
    }
    return ans;
}

int main() {
    fast_io;

    int t = 1;  
    while (t--) {
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        TreeNode *root=f(nums,0);
        print(root);
        cout<<endl;
        vector<vector<int>>sums=fun(root);
        vector<int>sum;
        for(int i=0;i<sums.size();i++){
            int sz=sums[i].size();
            int summation=0;
            for(int j=0;j<sz;j++) summation+=sums[i][j];
            sum.push_back(summation);
        }
        vector<int>ans(sums.size());
        ans[0]=0;
        ans[1]=0;
        int diff=sum[1]-sum[0];
        for(int i=2;i<ans.size();i++){
            int ele=sum[i-1]+diff;
            int answer=ele-sum[i];
            ans[i]=answer;
        }
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    }

    return 0;
}