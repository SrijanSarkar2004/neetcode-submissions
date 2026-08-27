class Solution {
public:
    // int f(int ind, vector<int>& coins, int target, vector<vector<int>>& dp)
    // {
    //     if(ind==0)
    //     {
    //         if(target % coins[0] == 0)
    //             return dp[0][target] = target / coins[0];
    //         return 1e9;
    //     }

    //     if(dp[ind][target] != -1)
    //         return dp[ind][target];

    //     int notTake = f(ind-1, coins, target, dp);

    //     int take = 1e9;
    //     if(coins[ind] <= target)
    //         take = 1 + f(ind, coins, target - coins[ind], dp);

    //     return dp[ind][target] = min(take, notTake);
    // }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        
        int target=amount;
        for(int T=0;T<=target;T++)
        {
            if(T%coins[0]==0)
            dp[0][T]=T/coins[0];
            else
            dp[0][T]=1e9;
        }
       for(int ind =1;ind<coins.size();ind++)
       {
        for(int T=0;T<=target;T++)
           {
             int notTake =0+ dp[ind-1][T];

            int take = 1e9;
            if(coins[ind] <= T)
                take = 1 + dp[ind][T-coins[ind]];

            dp[ind][T] = min(take, notTake);
            }
       }

        // int ans = f(coins.size()-1, coins, amount, dp);
        int ans=dp[coins.size()-1][target];
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};