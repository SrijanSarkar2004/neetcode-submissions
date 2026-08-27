class Solution {
    int f(int n, vector<int>&dp){
        if(n==-1)
        return 0;
        
        if(n==0)
        return dp[n]=1;
        
        if(dp[n]!=-1)
        return dp[n];

        int one=f(n-1,dp);
        int two=f(n-2,dp);
        return dp[n]=one+two;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=f(n,dp);
        return ans;
    }
};