class Solution {
public:
    int f(int ind, vector<int>& cost, vector<int>&dp, int n){
        if(ind==n)
        return 0;

        if(ind==n-1)
        return dp[n-1]=cost[n-1];

        if(dp[ind]!=-1)
        return dp[ind];

        int one=cost[ind] + f(ind+1, cost, dp, n);
        int two = cost[ind] + f(ind+2, cost, dp, n);
        return dp[ind]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int ans1=f(0,cost,dp,n);
        int ans2=f(1,cost,dp,n);
        return min(ans1,ans2);
    }
};