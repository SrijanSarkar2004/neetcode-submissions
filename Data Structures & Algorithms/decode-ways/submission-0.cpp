class Solution {
public:
    int f(int ind,string &s,vector<int>&dp,int n){
        if(ind==n)
            return 1;

        if(s[ind]=='0')
            return 0;

        if(dp[ind]!=-1)
            return dp[ind];

        int one=f(ind+1,s,dp,n);
        int two=0;

        if(ind+1<n){
            int x=(s[ind]-'0')*10+(s[ind+1]-'0');

            if(x>=10&&x<=26)
                two=f(ind+2,s,dp,n);
        }

        return dp[ind]=one+two;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return f(0,s,dp,n);
    }
};