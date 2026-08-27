// class Solution {
// public:
//     int f(int ind, int turn, vector<int>& stoneValue,
//           vector<array<int, 2>>& dp,     // Changed to array
//           vector<array<bool, 2>>& vis,   // Changed to array
//           int n) {

//         if (ind >= n)
//             return 0;

//         if (vis[ind][turn])
//             return dp[ind][turn];

//         vis[ind][turn] = true;

//         int take_one = (turn == 0) ? -1e9 : 1e9;
//         int take_two = (turn == 0) ? -1e9 : 1e9;
//         int take_three = (turn == 0) ? -1e9 : 1e9;

//         take_one = (1 - turn) * stoneValue[ind]
//                  + f(ind + 1, 1 - turn, stoneValue, dp, vis, n);

//         if (ind + 1 < n)
//             take_two = (1 - turn) * (stoneValue[ind] + stoneValue[ind + 1])
//                      + f(ind + 2, 1 - turn, stoneValue, dp, vis, n);

//         if (ind + 2 < n)
//             take_three = (1 - turn) * (stoneValue[ind] + stoneValue[ind + 1] + stoneValue[ind + 2])
//                        + f(ind + 3, 1 - turn, stoneValue, dp, vis, n);

//         if (turn == 0)
//             return dp[ind][turn] = max({take_one, take_two, take_three});
//         else
//             return dp[ind][turn] = min({take_one, take_two, take_three});
//     }

//     string stoneGameIII(vector<int>& stoneValue) {
//         int n = stoneValue.size();

//         // One heap allocation each! Drastically faster initialization.
//         vector<array<int, 2>> dp(n);
//         vector<array<bool, 2>> vis(n, {false, false}); 

//         int alice_score = f(0, 0, stoneValue, dp, vis, n);

//         int total_score = 0;
//         for (int x : stoneValue)
//             total_score += x;

//         int bob_score = total_score - alice_score;

//         if (alice_score == bob_score)
//             return "Tie";
//         if (alice_score > bob_score)
//             return "Alice";
//         return "Bob";
//     }
// };
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<vector<int>> dp(n + 3, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; --i) {
            int take_one_a = stoneValue[i] + dp[i + 1][1];
            
            int take_two_a = -1e9;
            if (i + 1 < n) 
                take_two_a = stoneValue[i] + stoneValue[i + 1] + dp[i + 2][1];
                
            int take_three_a = -1e9;
            if (i + 2 < n) 
                take_three_a = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + dp[i + 3][1];
                
            dp[i][0] = max({take_one_a, take_two_a, take_three_a});


            int take_one_b = dp[i + 1][0];
            
            int take_two_b = 1e9;
            if (i + 1 < n) 
                take_two_b = dp[i + 2][0];
                
            int take_three_b = 1e9;
            if (i + 2 < n) 
                take_three_b = dp[i + 3][0];
                
            dp[i][1] = min({take_one_b, take_two_b, take_three_b});
        }

        int alice_score = dp[0][0]; 
        
        int total_score = 0;
        for (int x : stoneValue) {
            total_score += x;
        }

        int bob_score = total_score - alice_score;

        if (alice_score == bob_score) return "Tie";
        if (alice_score > bob_score) return "Alice";
        return "Bob";
    }
};